// Jeff Somers
// Jan 2001


/**
 *  Performs static evaluation of a chessboard for a given side.
 **/
public final class Evaluator
{	

	/**
	 *  Constructor
	 **/
	Evaluator()
	{
	}

	// The idea for piece bonus arrays comes from 
	// Tom's simple chess program at http://ucsu.colorado.edu/~kerrigat/
	// although his bonus values are much more complicated than mine.

	/**
	 *  We want the pawns to control the center, and move to 
	 *  the back row.  The pawns know they can't move backwards,
	 *  so weighting the back row is not a problem.
	 **/
	private final static int _PawnBonus[] = 
	{
	   30, 30, 30, 30, 30, 30, 30, 30,
	   20, 20, 20, 20, 20, 20, 20, 20,
	   20, 20, 22, 27, 25, 22, 20, 20,
	    0,  0, 23, 24, 30, 24,  0,  0,
	    0,  0, 23, 24, 30, 24,  0,  0,
	   20, 20, 22, 27, 25, 22, 20, 20,
	   20, 20, 20, 20, 20, 20, 20, 20,
	   30, 30, 30, 30, 30, 30, 30, 30,
	};

	/**
	 *  We don't want the knights on the sides.
	 **/
	private final static int _KnightBonus[] = 
	{
	    0,  0,  0,  0,  0,  0,  0,  0,
	    0, 10, 20, 20, 20, 20, 20,  0,
	    0, 20, 30, 30, 30, 30, 20,  0,
	    0, 20, 30, 30, 30, 30, 20,  0,
	    0, 20, 30, 30, 30, 30, 20,  0,
	    0, 20, 30, 30, 30, 30, 20,  0,
	    0, 10, 20, 20, 20, 20, 10,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,
	};

	/**
	 *  We don't want the bishops on the sides.
	 **/
	private final static int _BishopBonus[] = 
	{
	    0,  0,  0,  0,  0,  0,  0,  0,
	    0, 10, 10, 10, 10, 10, 10,  0,
	    0, 10, 20, 20, 20, 20, 10,  0,
	    0, 10, 20, 30, 30, 20, 10,  0,
	    0, 10, 20, 30, 30, 20, 10,  0,
	    0, 10, 20, 20, 20, 20, 10,  0,
	    0, 10, 10, 10, 10, 10, 10,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,
	};
	

	/**
	 *  We want the king to castle & not move to the center
	 **/
	private final static int _KingBonus[] = 
	{
	   40, 40, 50, 10,  0, 10, 50, 40,
	   10, 10, 10, 10, 40, 10, 10, 10,
	    0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,  0,  0,  0,
	   10, 10, 10, 10, 40, 10, 10, 10,
	   40, 40, 50, 10,  0, 10, 50, 40,
	};
	
	/**
	 *  Static evaluation of a chessboard for a given side.
	 **/
	static public int eval(Board board, int color) throws patzException
	{
		Util.assert(color == Board.WHITE || color == Board.BLACK);

		// Add up value of pieces & value of positions
		int whiteScore = getPieceScore(board, Board.WHITE);

		// Add penalties if developed pieces poorly
		whiteScore += getMoveScore(board, Board.WHITE);

		// Add penalties if pawns are "bad"
		whiteScore += getPawnScore(board, Board.WHITE);

		// Add up value of pieces & value of positions
		int blackScore = getPieceScore(board, Board.BLACK);

		// Add penalties if developed pieces poorly
		blackScore += getMoveScore(board, Board.BLACK);

		// Add penalties if pawns are "bad"
		blackScore += getPawnScore(board, Board.BLACK);

		if (color == Board.WHITE) {
			return (whiteScore - blackScore);
		} else {
			return (blackScore - whiteScore);
		}
	}

	/**
	 *  Determine the material balance & board positioning
	 *  of a side.
	 **/
	static public int getPieceScore(Board board, int color) throws patzException
	{
		int score = 0;
		int range1 = 0, range2 = 0;

		if (color == Board.WHITE) {
			range1 = 0;
			range2 = 15;
		} else {
			range1 = 16;
			range2 = 31;
		}

		for (int i = 0; i < 64; ++i)
		{
			int index = board.getBoardPos(i);
			if (range1 <= index && index <= range2) // we have a piece of correct color
			{
				switch(index - range1)
				{
				case Board.KING:
					{
						score += _KingBonus[i];
						break;
					}
				case Board.KNIGHT1:
				case Board.KNIGHT2:
					{
						score += _KnightBonus[i];
						break;
					}
				case Board.BISHOP1:
				case Board.BISHOP2:
					{
						score += _BishopBonus[i];
						break;
					}
				case Board.PAWN1: case Board.PAWN2: case Board.PAWN3: case Board.PAWN4:
				case Board.PAWN5: case Board.PAWN6: case Board.PAWN7: case Board.PAWN8:
					{
						score += _PawnBonus[i];
						break;
					}
				}


				// Add 100 for each pawn, 300 for knight, etc.
				score += board.getBoardPiece(i).getValue();
			}
		}
		return score;
	}

	/**
	 *  Make sure queen doesn't move to soon, etc.
	 **/
	static public int getMoveScore(Board board, int color)
	{
		int score = 0;
		Piece pieces[] = null;

		if (color == Board.WHITE) {
			pieces = board._whitePieces;
		} else {
			pieces = board._blackPieces;
		}

		// If queen has moved before knights and bishops have
		// moved, it's a penalty.
		if (pieces[Board.QUEEN].hasMoved() &&
			(!pieces[Board.KNIGHT1].hasMoved() ||
			 !pieces[Board.KNIGHT2].hasMoved() ||
			 !pieces[Board.BISHOP1].hasMoved() ||
			 !pieces[Board.BISHOP2].hasMoved()))
		{
			score -= 100;
		}

		// If king has moved before either rook, it's 
		// penalty, we want to castle first.
		if (pieces[Board.KING].hasMoved() &&
			!pieces[Board.ROOK1].hasMoved() &&
			!pieces[Board.ROOK2].hasMoved())
		{
			score -= 100;
		}
		
		return score;
	}

	static int pawns[] = new int[8];

	/**
	 *  Penalize doubled pawns & isolated pawns.
	 **/
	static public int getPawnScore(Board board, int color) throws patzException
	{
		int score = 0;
		int range1 = 0, range2 = 0;

		// Zero out the pawn array
		for (int i = 0; i < 8; i++) {
			pawns[i] = 0;
		}

		if (color == Board.WHITE) {
			range1 = 0;
			range2 = 15;
		} else {
			range1 = 16;
			range2 = 31;
		}

		// So what we're going to do is count the pawns
		// in each column.  If a column is occupied, but 
		// the ones near it are not, the pawn is isolated 
		// and a penalty is accessed.
		// Also, penalize doubled pawns.
		for (int i = 0; i < 64; ++i)
		{
			int index = board.getBoardPos(i);
			if (range1 <= index && index <= range2) // we have a piece of correct color
			{
				// Get index into piece array
				int piece = index - range1;
				if (piece >= Board.PAWN1 &&
					piece <= Board.PAWN8)
				{
					pawns[i % 8] += 1;
				}
			}
		}

		// Penalize doubled pawns
		for (int i = 0; i < 8; ++i)
		{
			if (pawns[i] > 1) {
				score -= 20;
			}
		}

		// Penalize isolated pawns
		// 1st column
		if (pawns[0] > 0 && pawns[1] == 0) {
			score -= 20;
		}
		// last column
		if (pawns[7] > 0 && pawns[6] == 0) {
			score -= 20;
		}
		// other columns
		for (int i = 1; i < 7; ++i)
		{
			if (pawns[i] > 0 && pawns[i-1] == 0 &&
				pawns[i+1] == 0 ) {
				score -= 20;
			}
		}

		return score;
	}
}