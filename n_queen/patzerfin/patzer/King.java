// Jeff Somers
// Jan 2001

public final class King extends Piece
{

	public void genPseudoLegalMoves()
	{

	}

	// constructor
	King(int mycolor, int piecenum, Board board) throws patzException
	{
		super(mycolor, piecenum, symbol, board);
	}

	static final char  symbol = 'K'; // Knight is 'N'

	/** 
	 *  Return value of piece (pawn = 100, knight = 300, etc.)
	 **/
	public int getValue(){return 0;} // you always have king, no extra value

	// Capture is same as move
	public boolean isLegalCapture(int fromsq, int tosq) throws patzException
	{
		return this.isLegalMove(fromsq, tosq);
	}

	public boolean isLegalMove(int fromsq, int tosq) throws patzException
	{
		int from = _board._mailbox[_board._checkmailbox[fromsq]];
		int to = _board._mailbox[_board._checkmailbox[tosq]];

		if (from == -1 || to == -1) {
			return false; // off the board
		}

		int diff = (from > to) ? (from - to) : (to - from); // absolute value
 
		if (diff == 1 || diff == 10 || 
			diff == 11 || diff == 9)
			
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// Generate all captures for the piece
	public void generateAllCaptures(ListOMoves list, int position) throws patzException
	{
		int origpos = position;
		int offsets[] = {-1, -11, -10, -9, 1, 11, 10, 9}; // offsets in "mailbox array"
		int realmoves[] = {-1, -9, -8, -7, 1, 9, 8, 7}; // offsets in real board (8x8 array)
		for (int i = 0; i < offsets.length; ++i)
		{
			position = origpos;
			// move in each direction 
			int val = _board._mailbox[_board._checkmailbox[position]];
			val = _board._mailbox[ val + offsets[i]];
			position += realmoves[i];

			// if off board, continue
			if (val == -1) continue;
			int piece = _board.getBoardPos(position);
			if ((_color == _board.WHITE && piece > 15 && piece < 32) || // found black piece
			   (_color == _board.BLACK && piece > -1 && piece < 16)) // found white piece
			{
				Move cap = list.giveOutNewMove();
				cap._color = _color;
				cap._fromSq = origpos;
				cap._toSq = position;
				cap._fromSqIndex = _board.getBoardPos(origpos);
				cap._toSqIndex = _board.getBoardPos(position);
				cap._fromSqHasMoved = _hasMoved;
			}
		}
	}

	// Generate all moves which are not captures
	public void generateAllNonCaptures(ListOMoves list, int position) throws patzException
	{
		//NOTE: king should generate castling moves, if allowed
		int origpos = position;
		int offsets[] = {-1, -11, -10, -9, 1, 11, 10, 9}; // offsets in "mailbox array"
		int realmoves[] = {-1, -9, -8, -7, 1, 9, 8, 7}; // offsets in real board (8x8 array)
		for (int i = 0; i < offsets.length; ++i)
		{
			position = origpos;
			// move in each direction 
			int val = _board._mailbox[_board._checkmailbox[position]];
			val = _board._mailbox[ val + offsets[i]];
			position += realmoves[i];

			// if off board, continue
			if (val == -1) continue;
			int piece = _board.getBoardPos(position);
			if (piece == -1) // found empty square
			{
				Move cap = list.giveOutNewMove();
				cap._color = _color;
				cap._fromSq = origpos;
				cap._toSq = position;
				cap._fromSqIndex = _board.getBoardPos(origpos);
				cap._toSqIndex = _board.getBoardPos(position);
				cap._fromSqHasMoved = _hasMoved;
			}
		}
	}
}
