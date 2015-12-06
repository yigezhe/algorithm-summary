// Jeff Somers
// Jan 2001

public final class Pawn extends Piece
{
	// constructor
	Pawn(int mycolor, int piecenum, Board board) throws patzException
	{
		super(mycolor, piecenum, symbol, board);
	}


	public void genPseudoLegalMoves()
	{
		//NOTE:  worry about promotion

	}

	static final char symbol = 'P'; //NOTE: worry about promotion

	/** 
	 *  Return value of piece (pawn = 100, knight = 300, etc.)
	 **/
	public int getValue(){return 100;}


	// Capture is same as move
	// NOTE: this will only return "true" accurate value if there is a piece
	// of opposite color at the location -- won't tell us if tosq is threatened
	// by this pawn.
	public boolean isLegalCapture(int fromsq, int tosq) throws patzException
	{
		int from = _board._mailbox[_board._checkmailbox[fromsq]];
		int to = _board._mailbox[_board._checkmailbox[tosq]];

		if (from == -1 || to == -1) {
			return false; // off the board
		}

		if (Board.WHITE == _color)
		{
			int diff = fromsq - tosq;
			if (diff == 7 || diff == 9)
			{
				int cappiece = _board.getBoardPos(tosq);
				if (cappiece >= 16 && cappiece <= 31) // black piece
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			int diff = fromsq - tosq;
			if (diff == -7 || diff == -9)
			{
				int cappiece = _board.getBoardPos(tosq);
				if (cappiece >= 0 && cappiece <= 15) // white piece
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		return false;			
	}

	
	public boolean isLegalMove(int fromsq, int tosq) throws patzException
	{
		// The pawn is weird because it captures differently than it moves
		// and its moves depend on its color.  
		// Also it can capture en passant (not implemented)

		//NOTE: worry about promotion

		Util.assert(_color == Board.WHITE || _color == Board.BLACK);

		int from = _board._mailbox[_board._checkmailbox[fromsq]];
		int to = _board._mailbox[_board._checkmailbox[tosq]];

		if (from == -1 || to == -1) {
			return false; // off the board
		}

		if (Board.WHITE == _color)
		{
			int diff = fromsq - tosq;
			if (diff == 8 && _board.getBoardPos(tosq) == -1)
			{
				return true;
			}
			if (diff == 16 && _board.getBoardPos(tosq) == -1 &&
							_board.getBoardPos(fromsq - 8) == -1 &&
							!_hasMoved)
			{
				return true;
			}
			if (diff == 7 || diff == 9)
			{
				int cappiece = _board.getBoardPos(tosq);
				if (cappiece >= 16 && cappiece <= 31) // black piece
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		else
		{
			int diff = fromsq - tosq;
			if (diff == -8 && _board.getBoardPos(tosq) == -1)
			{
				return true;
			}
			if (diff == -16 && _board.getBoardPos(tosq) == -1 &&
							_board.getBoardPos(fromsq + 8) == -1 &&
							!_hasMoved)
			{
				return true;
			}
			if (diff == -7 || diff == -9)
			{
				int cappiece = _board.getBoardPos(tosq);
				if (cappiece >= 0 && cappiece <= 15) // white piece
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		return false;			
	}

	// Generate all captures for the piece
	public void generateAllCaptures(ListOMoves list, int position) throws patzException
	{
		int origpos = position;
		int whiteoffsets[] = {-9, -11}; // offsets in "mailbox array"
		int realwhitemoves[] = {-7, -9}; // offsets in real board (8x8 array)

		int blackoffsets[] = {9, 11}; // offsets in "mailbox array"
		int realblackmoves[] = {7, 9}; // offsets in real board (8x8 array)

		int arr[];
		int arreal[];
		if (_color == _board.WHITE)
		{
			arr = whiteoffsets;
			arreal = realwhitemoves;
		}
		else
		{
			arr = blackoffsets;
			arreal = realblackmoves;
		}

		for (int i = 0; i < arr.length; ++i)
		{
			// move in each direction 
			position = origpos;
			int val = _board._mailbox[_board._checkmailbox[position]];
			val = _board._mailbox[ val + arr[i]];
			position += arreal[i];

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
				// should check if pawn promotion here
			}
		}
	}

	// Generate all moves which are not captures
	public void generateAllNonCaptures(ListOMoves list, int position) throws patzException
	{
		int origpos = position;

		int offset[] = new int[2];
		int offsetreal[] = new int[2];

		if (_color == _board.WHITE)
		{
			if (_hasMoved)
			{
				offset[0] = -10;
				offset[1] = 0; // can't move 2 rows, already moved
				offsetreal[0] = -8;
				offsetreal[1] = 0;
			}
			else
			{
				offset[0] = -10;
				offset[1] = -20; 
				offsetreal[0] = -8;
				offsetreal[1] = -16;
			}
		}
		else
		{
			if (_hasMoved)
			{
				offset[0] = 10;
				offset[1] = 0; // can't move 2 rows, already moved
				offsetreal[0] = 8;
				offsetreal[1] = 0;
			}
			else
			{
				offset[0] = 10;
				offset[1] = 20; 
				offsetreal[0] = 8;
				offsetreal[1] = 16;
			}
		}

		
		for (int i = 0; i < offset.length; ++i)
		{
			if (offset[i] == 0) continue; // can't stay on same square
			
			// move in each direction 
			position = origpos;
			int val = _board._mailbox[_board._checkmailbox[position]];
			val = _board._mailbox[ val + offset[i]];
			position += offsetreal[i];

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
			else
			{
				break; // if can't move ahead by one row, then can't move two rows
			}
		}
	}
}
