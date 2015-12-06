// Jeff Somers
// Jan 2001

public final class Knight extends Piece
{

	static final char symbol = 'N'; // K is for King

	// constructor
	Knight(int mycolor, int piecenum, Board board) throws patzException
	{
		super(mycolor, piecenum, symbol, board);
	}

	/** 
	 *  Return value of piece (pawn = 100, knight = 300, etc.)
	 **/
	public int getValue(){return 300;}

	public void genPseudoLegalMoves()
	{

	}

	// Capture is same as move
	public boolean isLegalCapture(int fromsq, int tosq) throws patzException
	{
		return this.isLegalMove(fromsq, tosq);
	}

	// Is this a legal move?
	public boolean isLegalMove(int fromsq, int tosq) throws patzException
	{
		int from = _board._mailbox[_board._checkmailbox[fromsq]];
		int to = _board._mailbox[_board._checkmailbox[tosq]];

		if (from == -1 || to == -1) {
			return false; // off the board
		}

		int diff = (from > to) ? (from - to) : (to - from); // absolute value
 
		if (diff == 19 || diff == 21 || 
			diff == 12 || diff == 8)
			
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
		int offsets[] = {8, -8, 12, -12, 19, -19, 21, -21}; // offsets in "mailbox array"
		int realmoves[] = {6, -6, 10, -10, 15, -15, 17, -17}; // offsets in real board (8x8 array)
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
		int origpos = position;
		int offsets[] = {8, -8, 12, -12, 19, -19, 21, -21}; // offsets in "mailbox array"
		int realmoves[] = {6, -6, 10, -10, 15, -15, 17, -17}; // offsets in real board (8x8 array)
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
