// Jeff Somers
// Jan. 2001

import java.util.Vector;
import java.io.*;

public final class Board
{
	static PrintStream p = new PrintStream(System.out);

	/**
	 * This is the so-called mailbox array.  I have no
	 * idea why it's called that, other than it looks like
	 * a square inside another square.  It's described in
	 * " Chess Skill in Man and Machine (Texts and Monographs 
	 * in Computer Science)" ed. by Peter W. Frey.  Basically
	 * it's used as a quick way to test if moves are legal.
	 * For example, say a knight is in the A8 corner.  That 
	 * corresponds to position 21 in this array (the upper left
	 * corner of the "inner" box.  We can add 8 offsets to this
	 * position (for the 8 ways a knight may move).  If the 
	 * mailbox position is a -1, then the knight is off the board 
	 * and it's not a legal move.
	 */
	public final static int _mailbox[] = 
	{  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  21,  22,  23,  24,  25,  26,  27,  28,  -1,
       -1,  31,  32,  33,  34,  35,  36,  37,  38,  -1,
       -1,  41,  42,  43,  44,  45,  46,  47,  48,  -1,
       -1,  51,  52,  53,  54,  55,  56,  57,  58,  -1,
       -1,  61,  62,  63,  64,  65,  66,  67,  68,  -1,
       -1,  71,  72,  73,  74,  75,  76,  77,  78,  -1,
       -1,  81,  82,  83,  84,  85,  86,  87,  88,  -1,
       -1,  91,  92,  93,  94,  95,  96,  97,  98,  -1,
	   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	   -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	};

	public final static int _checkmailbox[] = 
	{
		21,  22,  23,  24,  25,  26,  27,  28,
        31,  32,  33,  34,  35,  36,  37,  38,
        41,  42,  43,  44,  45,  46,  47,  48,
        51,  52,  53,  54,  55,  56,  57,  58,
        61,  62,  63,  64,  65,  66,  67,  68,
        71,  72,  73,  74,  75,  76,  77,  78,
        81,  82,  83,  84,  85,  86,  87,  88,
        91,  92,  93,  94,  95,  96,  97,  98,
	};

	private int _boarddisp[] = 
	{
	   17, 22, 20, 19, 16, 21, 23, 18,
	   24, 25, 26, 27, 28, 29, 30, 31,
	   -1, -1, -1, -1, -1, -1, -1, -1,
	   -1, -1, -1, -1, -1, -1, -1, -1,
	   -1, -1, -1, -1, -1, -1, -1, -1,
	   -1, -1, -1, -1, -1, -1, -1, -1,
	    8,  9, 10, 11, 12, 13, 14, 15, 
	    1,  6,  4,  3,  0,  5,  7,  2
	};

	private final static int BOARDSIZE = 8;
	private final static int NUMPIECES = 16;

	protected Piece _whitePieces[];
	protected Piece _blackPieces[];

	protected final static int EMPTY = -1;
	protected final static int KING  = 0;
	protected final static int ROOK1 = 1;
	protected final static int ROOK2 = 2;
	protected final static int QUEEN  = 3;
	protected final static int BISHOP1  = 4;
	protected final static int BISHOP2  = 5;
	protected final static int KNIGHT1  = 6;
	protected final static int KNIGHT2  = 7;
	protected final static int PAWN1  = 8;
	protected final static int PAWN2  = 9;
	protected final static int PAWN3  = 10;
	protected final static int PAWN4  = 11;
	protected final static int PAWN5  = 12;
	protected final static int PAWN6  = 13;
	protected final static int PAWN7  = 14;
	protected final static int PAWN8  = 15;

	public final static int WHITE = 0;
	public final static int BLACK = 1;

	Vector moveVect;

	protected int _numMoves;

	private ListOMoves _listOMoves;

	// constructor
	Board() throws patzException
	{
		_whitePieces = setupboard(WHITE);
		_blackPieces = setupboard(BLACK);

		moveVect = new Vector(50, 10);

		_numMoves = 0;

		_listOMoves = new ListOMoves();
	}

	private Piece[] setupboard(int mycolor) throws patzException
	{
		Piece pieces[] = new Piece[NUMPIECES];
		pieces[KING] = new King(mycolor, KING, this);
		pieces[ROOK1] = new Rook(mycolor, ROOK1, this);
		pieces[ROOK2] = new Rook(mycolor, ROOK2, this);
		pieces[QUEEN] = new Queen(mycolor, QUEEN, this);
		pieces[BISHOP1] = new Bishop(mycolor, BISHOP1, this);
		pieces[BISHOP2] = new Bishop(mycolor, BISHOP2, this);
		pieces[KNIGHT1] = new Knight(mycolor, KNIGHT1, this);
		pieces[KNIGHT2] = new Knight(mycolor, KNIGHT2, this);
		pieces[PAWN1] = new Pawn(mycolor, PAWN1, this);
		pieces[PAWN2] = new Pawn(mycolor, PAWN2, this);
		pieces[PAWN3] = new Pawn(mycolor, PAWN3, this);
		pieces[PAWN4] = new Pawn(mycolor, PAWN4, this);
		pieces[PAWN5] = new Pawn(mycolor, PAWN5, this);
		pieces[PAWN6] = new Pawn(mycolor, PAWN6, this);
		pieces[PAWN7] = new Pawn(mycolor, PAWN7, this);
		pieces[PAWN8] = new Pawn(mycolor, PAWN8, this);
		return pieces;
	}

	public int getBoardPos(int pos) throws patzException
	{
		Util.assert(pos >= 0 && pos <= 63);
		return _boarddisp[pos];
	}

	// pass in number from 0 to 63, 0 is upper left from
	// white's point of view, 63 is lower right.
	// Return value points to piece at that position, or
	// null if no piece there.
	public Piece getBoardPiece(int pos) throws patzException
	{
		Piece retVal = null;

		Util.assert(pos >= 0 && pos <= 63);

		int val = _boarddisp[pos];
		Util.assert(val >= -1 && val <= 31);

		if (val >= 0 && val <= 15)
		{
			retVal = _whitePieces[val];
		}
		else if (val >= 16 && val <= 31)
		{
			retVal = _blackPieces[val - 16]; // convert to 0 to 15 
		}

		return retVal;
	}

	public void printboard() throws patzException
	{
		System.out.println("\n\n");
		for (int i = 0; i < BOARDSIZE; ++i)
		{
			System.out.print("    " + (BOARDSIZE - i));
			for (int j = 0; j < BOARDSIZE; ++j)
			{
				int piece = _boarddisp[i * BOARDSIZE + j];
				if (piece < 0) {
					System.out.print(" ."); // empty square
				}
				else if (piece < 16) {
					System.out.print(" " + _whitePieces[piece].getSymbol());
				}
				else if (piece < 32) {
					System.out.print(" " + _blackPieces[piece - 16].getSymbol());
				}
				else {
					Util.assert(false); // board is set up incorrectly
				}
			}
			System.out.println("");
		}
		System.out.println("      a b c d e f g h\n");
	}

	// Determine if game is draw.
	private boolean isADraw()
	{
		// if each side has a King and just one Knight or one Bishop,
		// then it's a draw.
		int numBlackBishKnight = 0, numWhiteBishKnight = 0;
		int numBlackRookQueenPawn = 0; 

		int pieces = 0, index[] = {0, 0, 0};
		for (int i = 0; i < 16; ++i)
		{
			if (!_whitePieces[i].isCaptured()) {
				index[pieces++] = i;
				if (pieces > 2) break;
			}
		}
		// we know the King must be present.  Is only one knight or 
		// bishop present

		if ((pieces > 2) || 
			(index[0] != KING && index[0] != BISHOP1 && index[0] != BISHOP2 &&
			 index[0] != KNIGHT1 && index[0] != KNIGHT2) || // rook, queen, pawn
			(index[1] != KING && index[1] != BISHOP1 && index[1] != BISHOP2 &&
			 index[1] != KNIGHT1 && index[1] != KNIGHT2)) // rook, queen, pawn
		{
			return false;
		}

		pieces = index[0] =  index[1] =  index[2] = 0;
		for (int i = 0; i < 16; ++i)
		{
			if (!_blackPieces[i].isCaptured()) {
				index[pieces++] = i;
				if (pieces > 2) break;
			}
		}
		// we know the King must be present.  Is only one knight or 
		// bishop present

		if ((pieces > 2) || 
			(index[0] != KING && index[0] != BISHOP1 && index[0] != BISHOP2 &&
			 index[0] != KNIGHT1 && index[0] != KNIGHT2) || // rook, queen, pawn
			(index[1] != KING && index[1] != BISHOP1 && index[1] != BISHOP2 &&
			 index[1] != KNIGHT1 && index[1] != KNIGHT2)) // rook, queen, pawn
		{
			return false;
		}
		return true; // it's a draw
	}

	public boolean legalMoveExists(int color) throws patzException
	{
		Util.assert(color == WHITE || color == BLACK);

		if (isADraw()) {
			p.println("It's a draw due to insufficient material.");
			return false;
		}

		// if the number of moves is greater than 75 (150 ply), then 
		// it's a draw.  We enforce this because Patzer doesn't really
		// know about draw conditions (50 move rule, 3 reps) so we don't
		// want games to go on forever due to perpetual check, etc.

		if (_numMoves > 150)
		{
			p.println("Game called a draw due to too many (150 ply) moves.");
			p.println("We enforce this because Patzer doesn't really");
			p.println("know about draw conditions (50 move rule, 3 reps)");
			p.println("so we don't want games to go on forever due to");
			p.println("perpetual check, etc.");
			return false;
		}

		// if color has no legal move and king is in check, then its checkmate.
		// if color has no legal move and king is not check, then its stalemate.
		
		_listOMoves.reset();
		generateAllMoves(color, _listOMoves); // get list of all possible moves

		int numMoves = _listOMoves._plyIndices[0][1];
		boolean moveOK = false;

		// test each move -- is there a move you can make that
		// doesn't leave the king in check?
		for (int i = 0; i < numMoves; ++i)
		{
			Move testmove = _listOMoves._moveList[i];
			doMove(testmove);

			if (!inCheck(color)) { // is the king in check?
				moveOK = true;
				undoMove(testmove); // undo the move
				break;
			}

			undoMove(testmove); // undo the move
		}

		if (!moveOK) // no legal moves
		{
			if (inCheck(color))
			{
				p.print("Checkmate! ");
				p.print( ((color == WHITE) ? "White" : "Black"));
				p.println(" loses!");
			}
			else
			{
				p.println("Game is a draw due to stalemate.");
				p.print( ((color == WHITE) ? "White" : "Black"));
				p.println(" has no legal move but is not in check.");
			}
			return false;
		}

		return true;
	}


	// determine if King of this color is in check
	public boolean inCheck(int color) throws patzException
	{
		Util.assert(color == WHITE || color == BLACK);

		int kingvalue = (color == WHITE) ? KING : (KING + 16);

		// find king position
		// can black move to king position 
		int i;
		for (i = 0; i < 64; ++i)
		{
			if (_boarddisp[i] == kingvalue) {
				break;
			}
		}
		return (underAttack(color, i));

	}

	// Determine if piece of this color at this position can
	// be captured.
	public boolean underAttack(int color, int pos) throws patzException
	{
		Util.assert(color == WHITE || color == BLACK);
		Util.assert(pos >= 0 && pos < 64);

		if (color == WHITE)
		{
			for (int i = 0; i < 64; ++i) {
				int piece = _boarddisp[i];
				if (piece > 15 && piece < 32)
				{
					// found black piece
					if (_blackPieces[piece - 16].isLegalCapture(i, pos)) {
						return true;
					}
				}
			}
			return false;  // didn't find any captures
		}
		else
		{
			for (int i = 0; i < 64; ++i) {
				int piece = _boarddisp[i];
				if (piece >= 0  && piece < 16)
				{
					// found white piece
					if (_whitePieces[piece].isLegalCapture(i, pos)) {
						return true;
					}
				}
			}
			return false;  // didn't find any captures
		}
	}

	private boolean castle(Move move) throws patzException
	{
		Util.assert(move._color == Board.WHITE || move._color == Board.BLACK);

		if (move._color == Board.WHITE)
		{
			if (move._castleKingSide) {
				_boarddisp[61] = _boarddisp[63]; // move rook
				_boarddisp[62] = _boarddisp[60]; // move king
				_boarddisp[60] = _boarddisp[63] = -1;// set squares empty
				_whitePieces[Board.KING].setMoved();
				_whitePieces[Board.ROOK2].setMoved();
			}
			else {
				_boarddisp[59] = _boarddisp[56]; // move rook
				_boarddisp[58] = _boarddisp[60]; // move king
				_boarddisp[60] = _boarddisp[56] = -1; // set squares empty
				_whitePieces[Board.KING].setMoved();
				_whitePieces[Board.ROOK1].setMoved();
			}
		}
		else
		{
			if (move._castleKingSide) {
				_boarddisp[5] = _boarddisp[7]; // move rook
				_boarddisp[6] = _boarddisp[4]; // move king
				_boarddisp[4] = _boarddisp[7] = -1;// set squares empty
				_blackPieces[Board.KING].setMoved();
				_blackPieces[Board.ROOK2].setMoved();
			}
			else {
				_boarddisp[3] = _boarddisp[0]; // move rook
				_boarddisp[2] = _boarddisp[4]; // move king
				_boarddisp[4] = _boarddisp[0] = -1; // set squares empty
				_blackPieces[Board.KING].setMoved();
				_blackPieces[Board.ROOK1].setMoved();
			}

		}
		return true;
	}

	// Add one to the number of moves
	public void incMoveCount()
	{
		_numMoves++;
	}


	// Move the piece
	public boolean doMove(Move move) throws patzException
	{
		if (move._castleKingSide || move._castleQueenSide)
		{
			castle(move);
			return true;
		}

		int piece = _boarddisp[move._fromSq];
		int cappiece = _boarddisp[move._toSq];
		
		Util.assert(piece >=0 && piece <= 31);
		Util.assert(cappiece >= -1 && piece <= 31);

		// NOTE: handle castling here

		// If not moving to an empty square....
		if (cappiece != -1) // -1 is empty
		{
			if (cappiece > 15) {
				_blackPieces[cappiece - 16].setCaptured();
			} else {
				_whitePieces[cappiece].setCaptured();
			}
		}

		// Set flag to show piece has moved.
		if (piece > 15) {
			_blackPieces[piece - 16].setMoved();
		} else {
			_whitePieces[piece].setMoved();
		}

		// Move piece to new square & set previous
		// square to empty
		_boarddisp[move._toSq] = _boarddisp[move._fromSq];
		_boarddisp[move._fromSq] = EMPTY;

		//NOTE: have to deal w/ e.p., pawn promotion

		return true;
	}

	// Undo a Move 
	public boolean undoMove(Move move) throws patzException
	{
		if (move._castleKingSide || move._castleQueenSide)
		{
			undoCastle(move);
			return true;
		}

		// Move pieces back
		_boarddisp[move._fromSq] = _boarddisp[move._toSq];
		_boarddisp[move._toSq] = move._toSqIndex;

		// If a capture, set piece to "non captured" status
		if (-1 != move._toSqIndex) {
			if (move._toSqIndex > 15) {
				_blackPieces[move._toSqIndex - 16].setUncaptured();
			} else {
				_whitePieces[move._toSqIndex].setUncaptured();
			}
		}

		// Reset the value of the "has moved" flag
		if (move._fromSqIndex > 15) {
			_blackPieces[move._fromSqIndex - 16].setMovedValue(move._fromSqHasMoved);
		} else {
			_whitePieces[move._fromSqIndex].setMovedValue(move._fromSqHasMoved);
		}

		//NOTE: have to deal w/ e.p., pawn promotion
		
		return true;
	}

	public boolean undoCastle(Move move) throws patzException
	{
		Util.assert(move._color == Board.WHITE || move._color == Board.BLACK);

		if (move._color == Board.WHITE)
		{
			if (move._castleKingSide) {
				_boarddisp[63] = _boarddisp[61]; // move rook
				_boarddisp[60] = _boarddisp[62]; // move king
				_boarddisp[61] = _boarddisp[62] = -1;// set squares empty
				_whitePieces[Board.KING].setUnmoved();
				_whitePieces[Board.ROOK2].setUnmoved();
			}
			else {
				_boarddisp[56] = _boarddisp[59]; // move rook
				_boarddisp[60] = _boarddisp[58]; // move king
				_boarddisp[58] = _boarddisp[59] = -1; // set squares empty
				_whitePieces[Board.KING].setUnmoved();
				_whitePieces[Board.ROOK1].setUnmoved();
			}
		}
		else
		{
			if (move._castleKingSide) {
				_boarddisp[7] = _boarddisp[5]; // move rook
				_boarddisp[4] = _boarddisp[6]; // move king
				_boarddisp[5] = _boarddisp[6] = -1;// set squares empty
				_blackPieces[Board.KING].setUnmoved();
				_blackPieces[Board.ROOK2].setUnmoved();
			}
			else {
				_boarddisp[0] = _boarddisp[3]; // move rook
				_boarddisp[4] = _boarddisp[2]; // move king
				_boarddisp[2] = _boarddisp[3] = -1; // set squares empty
				_blackPieces[Board.KING].setUnmoved();
				_blackPieces[Board.ROOK1].setUnmoved();
			}

		}
		return true;
	}

	public boolean generateAllMoves(int color, ListOMoves listMoves) throws patzException
	{
		if (color == WHITE)
		{
			for (int i = 0; i < 64; ++i)
			{
				int piece = _boarddisp[i];
				if (piece >= 0 && piece < 16) 
				{
					// if find piece
					// generate all captures, non captures
					// place on list
					_whitePieces[piece].generateAllCaptures(listMoves, i);
					_whitePieces[piece].generateAllNonCaptures(listMoves, i);
				}
			}
		}
		else
		{
			for (int i = 0; i < 64; ++i)
			{
				int piece = _boarddisp[i];
				if (piece > 15 && piece < 32) 
				{
					// if find piece
					// generate all captures, non captures
					// place on list
					_blackPieces[piece - 16].generateAllCaptures(listMoves, i);
					_blackPieces[piece - 16].generateAllNonCaptures(listMoves, i);
				}
			}
		}

		return true;
	}


	public boolean generateAllCaptures(int color, ListOMoves listMoves) throws patzException
	{
		if (color == WHITE)
		{
			for (int i = 0; i < 64; ++i)
			{
				int piece = _boarddisp[i];
				if (piece >= 0 && piece < 16) 
				{
					// if find piece
					// generate all captures, non captures
					// place on list
					_whitePieces[piece].generateAllCaptures(listMoves, i);
				}
			}
		}
		else
		{
			for (int i = 0; i < 64; ++i)
			{
				int piece = _boarddisp[i];
				if (piece > 15 && piece < 32) 
				{
					// if find piece
					// generate all captures, non captures
					// place on list
					_blackPieces[piece - 16].generateAllCaptures(listMoves, i);
				}
			}
		}

		return true;
	}

	public boolean generateAllNonCaptures(int color, ListOMoves listMoves) throws patzException
	{
		if (color == WHITE)
		{
			for (int i = 0; i < 64; ++i)
			{
				int piece = _boarddisp[i];
				if (piece >= 0 && piece < 16) 
				{
					// if find piece
					// generate all captures, non captures
					// place on list
					_whitePieces[piece].generateAllNonCaptures(listMoves, i);
				}
			}
		}
		else
		{
			for (int i = 0; i < 64; ++i)
			{
				int piece = _boarddisp[i];
				if (piece > 15 && piece < 32) 
				{
					// if find piece
					// generate all captures, non captures
					// place on list
					_blackPieces[piece - 16].generateAllNonCaptures(listMoves, i);
				}
			}
		}

		return true;
	}

	/**
	 *  For debugging purposes, print the
	 *  evaluation of a board from a side's
	 *  point of view.
	 **/
	public void printEvaluation(int color) throws patzException
	{
		p.println("Board has evaluation " + Evaluator.eval(this, color) + " for " + ((color == WHITE) ? "white" : "black"));
	}
}