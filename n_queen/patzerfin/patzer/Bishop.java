// Jeff Somers
// Jan 2001

public final class Bishop extends Piece
{

	public void genPseudoLegalMoves()
	{

	}

	// constructor
	Bishop(int mycolor, int piecenum, Board board) throws patzException
	{
		super(mycolor, piecenum, symbol, board);
	}
	static final char  symbol = 'B';

	/** 
	 *  Return value of piece (pawn = 100, knight = 300, etc.)
	 **/
	public int getValue(){return 320;}

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

		if (fromsq == tosq) {
			return false; // can't move to same square
		}

		// diagonals go up by either 7 or 9 (on regular board)
		int diff = tosq - fromsq;
 
		if (diff % 7 == 0 )
		{
			// it's a positive diagonal (lower left to upper right or v. versa)
			int sign = (diff > 0) ? 1 : -1;
			int inc = 7 * sign;
			for (fromsq += inc; fromsq != tosq; fromsq += inc)
			{
				if (_board.getBoardPos(fromsq) != -1) {
					return false;// something's in the way
				}
			}
			return true;
		}

		if (diff % 9 == 0 )
		{
			// it's a negative diagonal (lower right to upper left or v. versa)
			int sign = (diff > 0) ? 1 : -1;
			int inc = 9 * sign;
			for (fromsq += inc; fromsq != tosq; fromsq += inc)
			{
				if (_board.getBoardPos(fromsq) != -1) {
					return false;// something's in the way
				}
			}
			return true;
		}

		return false;
	}

	// Generate all captures for the piece
	public void generateAllCaptures(ListOMoves list, int position) throws patzException
	{
		int origpos = position;
		int offsets[] = {9, -9, 11, -11}; // offsets in "mailbox array"
		int realmoves[] = {7, -7, 9, -9}; // offsets in real board (8x8 array)
		for (int i = 0; i < offsets.length; ++i)
		{
			position = origpos;
			// move in one direction until space is occupied or off board
			int val = _board._mailbox[_board._checkmailbox[position]];
			val = _board._mailbox[ val + offsets[i]];
			position += realmoves[i];
			while (val != -1 && _board.getBoardPos(position) == -1)
			{
				val = _board._mailbox[ val + offsets[i]];// move again
				position += realmoves[i];
			}

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
		int origpos = position;
		int offsets[] = {9, -9, 11, -11}; // offsets in "mailbox array"
		int realmoves[] = {7, -7, 9, -9}; // offsets in real board (8x8 array)
		for (int i = 0; i < offsets.length; ++i)
		{
			position = origpos;
			// move in one direction until space is occupied or off board
			int val = _board._mailbox[_board._checkmailbox[position]];
			val = _board._mailbox[ val + offsets[i]];
			position += realmoves[i];
			while (val != -1 && _board.getBoardPos(position) == -1)
			{
				Move cap = list.giveOutNewMove();
				cap._color = _color;
				cap._fromSq = origpos;
				cap._toSq = position;
				cap._fromSqIndex = _board.getBoardPos(origpos);
				cap._toSqIndex = _board.getBoardPos(position);
				cap._fromSqHasMoved = _hasMoved;

				val = _board._mailbox[ val + offsets[i]]; // move again
				position += realmoves[i];
			}
		}
	}

}
