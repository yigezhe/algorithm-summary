// Jeff Somers
// Jan 2001

public final class Queen extends Piece
{

	// constructor
	Queen(int mycolor, int piecenum, Board board) throws patzException
	{
		super(mycolor, piecenum, symbol, board);
	}

	public void genPseudoLegalMoves()
	{

	}

	static final char  symbol = 'Q';

	/** 
	 *  Return value of piece (pawn = 100, knight = 300, etc.)
	 **/
	public int getValue(){return 900;};


	// Capture is same as move
	public boolean isLegalCapture(int fromsq, int tosq) throws patzException
	{
		return this.isLegalMove(fromsq, tosq);
	}

	public boolean isLegalMove(int fromsq, int tosq) throws patzException
	{
		// We're using white pieces here, but it doesn't matter, since
		// white & black queens move the same way & we're not checking if 
		// the move leaves the king in check.
		if (_board._whitePieces[_board.BISHOP1].isLegalMove(fromsq, tosq) ||
			_board._whitePieces[_board.ROOK1].isLegalMove(fromsq, tosq))
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
		generateAllDiagCaptures(list, position);
		generateAllVertHorizCaptures(list, position);
	}

	// Generate all noncaptures for the piece
	public void generateAllNonCaptures(ListOMoves list, int position) throws patzException
	{
		generateAllDiagNonCaptures(list, position);
		generateAllVertHorizNonCaptures(list, position);
	}

	// Copied from Bishop class (this should really be in a common area)
	void generateAllDiagCaptures(ListOMoves list, int position) throws patzException
	{
		int origpos = position;
		int offsets[] = {1, -1, 10, -10}; // offsets in "mailbox array"
		int realmoves[] = {1, -1, 8, -8}; // offsets in real board (8x8 array)
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
	// Copied from Bishop class (this should really be in a common area)
	void generateAllDiagNonCaptures(ListOMoves list, int position) throws patzException
	{
		int origpos = position;
		int offsets[] = {1, -1, 10, -10}; // offsets in "mailbox array"
		int realmoves[] = {1, -1, 8, -8}; // offsets in real board (8x8 array)
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

	// Generate all captures for the piece (copied from Rook)
	void generateAllVertHorizCaptures(ListOMoves list, int position) throws patzException
	{
		int origpos = position;
		int offsets[] = {1, -1, 10, -10}; // offsets in "mailbox array"
		int realmoves[] = {1, -1, 8, -8}; // offsets in real board (8x8 array)
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

	// Generate all moves which are not captures (copied from Rook)
	void generateAllVertHorizNonCaptures(ListOMoves list, int position) throws patzException
	{
		int origpos = position;
		int offsets[] = {1, -1, 10, -10}; // offsets in "mailbox array"
		int realmoves[] = {1, -1, 8, -8}; // offsets in real board (8x8 array)
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
