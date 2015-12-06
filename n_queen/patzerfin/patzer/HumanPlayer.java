// Jeff Somers
// jsomers@alumni.williams.edu, allagash98@yahoo.com
// Jan 2001

import java.io.*;

public final class HumanPlayer extends Player
{
	static DataInputStream dis = new DataInputStream(System.in);
	static PrintStream p = new PrintStream(System.out);

	ListOMoves _listOMoves;

	/** 
	 *  constructor
	 **/
	HumanPlayer(int mycolor, Board myboard) throws patzException
	{
		super(mycolor, myboard);

		_listOMoves = new ListOMoves();
	}

	/** 
	 *  Print description of this player.
	 **/
	public void describeSelf()
	{
		p.println("Human Player");
	}

	/** 
	 *  Retrieve input from user until valid move 
	 *  is entered.
	 **/
	public void getMove(Move move) throws patzException
	{
		move._color = _color;
		for (;;)
		{
			if (_color == Board.WHITE) {
				p.print("White, enter a move:  ");
			} else {
				p.print("Black, enter a move: ");
			}
			// offer help e2e4, O-O (accept lower case, 0-0)
			// can also draw, resign
//			_currMove = move;
			if (!getMoveInput(move))
			{
				p.println("**** Illegal move ****");
				printhelp();
				_myboard.printboard();
				continue;
			}
			break;
		}
	}

	/** 
	 *  Print cursory help text for user.
	 **/
	private void printhelp()
	{
		System.out.println("\nHere are examples of valid input:");
		System.out.println("\te2e3");
		System.out.println("\tg8h6");
		System.out.println("You may also resign, draw or quit.");
	}

	/** 
	 *  Retrieve the user's input from the command line.
	 **/
	private boolean getMoveInput(Move move) throws patzException
	{
		// get input
		// is it valid?
		// if not, try again, offer help
		// must know if it's white/black
		String input = null;
		try
		{
			input = dis.readLine().trim();
		}
		catch(IOException ioe)
		{
			System.out.println(ioe);
			System.exit(-1);
		}

		input = input.toUpperCase();
		if (isRegularMove(input, move)) {
			return true;
		}
		else if (isSpecialMove(input, move)) {
			return true;
		} else if (isDebugMove(input, move)) { // user wants debug output
			return false;
		}

		return false; // illegal move, or bad input
	}

	/** 
	 *  Check if the user is allowed to castle Queenside.
	 **/
	private boolean checkCastleKingside(Move mymove) throws patzException
	{
		// check if castle legal
		// king not moved, rook not moved, 
		// king not in check
		// squares not in check
		// king won't end up in check
		if (_color == Board.WHITE) 
		{
			if (_myboard._whitePieces[Board.KING].hasMoved()) {
				p.println("King has already moved, you can't castle.");
				return false;
			}
			if (_myboard._whitePieces[Board.ROOK2].hasMoved()) {
				p.println("King's Rook has already moved, you can't castle.");
				return false;
			}
			if (_myboard.inCheck(Board.WHITE)) {
				p.println("Can't castle because King is in check.");
				return false;
			}
			if (_myboard.underAttack(Board.WHITE, 61)) {
				p.println("Square F1 is under attack by Black, so you can't castle Kingside.");
				return false;
			}
			if (_myboard.underAttack(Board.WHITE, 62)) {
				p.println("Castling would leave King in check.");
				return false;
			}
			if ((_myboard.getBoardPos(61) != -1) ||
				(_myboard.getBoardPos(62) != -1)) {
				p.println("Squares between King and Rook must be empty in order to castle.");
				return false;
			}
			mymove._castleKingSide = true;
			return true;
		}
		else {
			if (_myboard._blackPieces[Board.KING].hasMoved()) {
				p.println("King has already moved, you can't castle.");
				return false;
			}
			if (_myboard._blackPieces[Board.ROOK2].hasMoved()) {
				p.println("King's Rook has already moved, you can't castle.");
				return false;
			}
			if (_myboard.inCheck(Board.BLACK)) {
				p.println("Can't castle because King is in check.");
				return false;
			}
			if (_myboard.underAttack(Board.BLACK, 5)) {
				p.println("Square F8 is under attack, so you can't castle Kingside.");
				return false;
			}
			if (_myboard.underAttack(Board.BLACK, 6)) {
				p.println("Castling would leave King in check.");
				return false;
			}
			if ((_myboard.getBoardPos(5) != -1) ||
				(_myboard.getBoardPos(6) != -1)) {
				p.println("Squares between King and Rook must be empty in order to castle.");
				return false;
			}
			mymove._castleKingSide = true;
			return true;
		}
	}


	/** 
	 *  Check if the user is allowed to castle Queenside.
	 **/
	private boolean checkCastleQueenside(Move mymove) throws patzException
	{
	// check if castle legal
	// king not moved, rook not moved, 
	// king not in check
	// squares not in check
	// king won't end up in check
		if (_color == Board.WHITE) 
		{
			if (_myboard._whitePieces[Board.KING].hasMoved()) {
				p.println("King has already moved, you can't castle.");
				return false;
			}
			if (_myboard._whitePieces[Board.ROOK1].hasMoved()) {
				p.println("King's Rook has already moved, you can't castle.");
				return false;
			}
			if (_myboard.inCheck(Board.WHITE)) {
				p.println("Can't castle because King is in check.");
				return false;
			}
			if (_myboard.underAttack(Board.WHITE, 59)) {
				p.println("Square D1 is under attack by Black, so you can't castle Queenside.");
				return false;
			}
			if (_myboard.underAttack(Board.WHITE, 58)) {
				p.println("Castling would leave King in check.");
				return false;
			}
			if ((_myboard.getBoardPos(57) != -1) ||
				(_myboard.getBoardPos(58) != -1) ||
				(_myboard.getBoardPos(59) != -1)) {
				p.println("Squares between King and Rook must be empty in order to castle.");
				return false;
			}
			mymove._castleQueenSide = true;
			return true;
		}
		else {
			if (_myboard._blackPieces[Board.KING].hasMoved()) {
				p.println("King has already moved, you can't castle.");
				return false;
			}
			if (_myboard._blackPieces[Board.ROOK1].hasMoved()) {
				p.println("King's Rook has already moved, you can't castle.");
				return false;
			}
			if (_myboard.inCheck(Board.BLACK)) {
				p.println("Can't castle because King is in check.");
				return false;
			}
			if (_myboard.underAttack(Board.BLACK, 3)) {
				p.println("Square D8 is under attack, so you can't castle Queenside.");
				return false;
			}
			if (_myboard.underAttack(Board.BLACK, 2)) {
				p.println("Castling would leave King in check.");
				return false;
			}
			if ((_myboard.getBoardPos(1) != -1) ||
				(_myboard.getBoardPos(2) != -1) ||
				(_myboard.getBoardPos(3) != -1)) {
				p.println("Squares between King and Rook must be empty in order to castle.");
				return false;
			}
			mymove._castleQueenSide = true;
			return true;
		}
	}
	
	/** 
	 *  Is the user castling, resigning or offering
	 *  a draw?
	 **/
	private boolean isSpecialMove(String myinput, Move mymove) throws patzException
	{
		// castling kingside
		if (myinput.equals("O-O") || myinput.equals("0-0"))
		{
			return checkCastleKingside(mymove);
		}

		// castling queenside
		if (myinput.equals("O-O-O") || myinput.equals("0-0-0"))
		{
			return checkCastleQueenside(mymove);
		}

		if (myinput.equals("QUIT") || myinput.equals("Q") 
			|| myinput.equals("RESIGN"))
		{
			if (_color == Board.WHITE) {
				p.println("Black wins!!");
			} else {
				p.println("White wins!!");
			}
			mymove._specialMove = true;
			mymove._resign = true;
			return true;
		}

		// draws are always accepted, currently
		if (myinput.equals("DRAW"))
		{
			mymove._specialMove = true;
			mymove._offerDraw = true;
			p.println("Game is a draw.");
			return true;
		}

		return false;
	}

	/** 
	 *  Is this a move in the form of e2e4?
	 **/
	private boolean isRegularMove(String myinput, Move mymove) throws patzException
	{
		Util.assert(mymove != null); // move must be passed in

		// We've already performed trim() and toUpperCase() to input 
		// by this point.
		// We're looking for input like E2E4, G7G8, etc.
		if (myinput.length() != 4) {
			return false;
		}

		// first & third chars must be in the range [A..H]
		// second & third chars must be within [1..8]
		// so move looks like A2A3, etc.
		char[] carray = myinput.toCharArray();
		if (carray[0] < 'A' || carray[0] > 'H' ||
			carray[2] < 'A' || carray[2] > 'H' ||
			carray[1] < '1' || carray[1] > '8' ||
			carray[3] < '1' || carray[3] > '8') 
		{
			return false;
		}

		// check have piece there, moving to blank or capturing enemy
		// not leaving king in check.

		int fromsq = Move.convertMoveToIndex(carray[0], carray[1]);
		int tosq = Move.convertMoveToIndex(carray[2], carray[3]);

		Piece movepiece = _myboard.getBoardPiece(fromsq);
		Piece capturepiece = _myboard.getBoardPiece(tosq);

		if (movepiece == null)
		{
			System.out.println("You have no piece on that square.");
			return false;
		} 
		else if (movepiece.getColor() != _color)
		{
			System.out.println("You can't move the other player's piece.");
			return false;
		}
		else if (capturepiece != null && capturepiece.getColor() == _color)
		{
			System.out.println("You can't move on top of your own piece.");
			return false;
		}

		if (movepiece.isLegalMove(fromsq, tosq))
		{
			mymove._fromSq = fromsq;
			mymove._toSq = tosq;
		}
		else
		{
			return false;
		}

		// Check if the king is in check
		
		// Store extra stuff in move so we can undo it.
		mymove._fromSqIndex = _myboard.getBoardPos(mymove._fromSq);
		mymove._toSqIndex = _myboard.getBoardPos(mymove._toSq);
		mymove._fromSqHasMoved = _myboard.getBoardPiece(mymove._fromSq).hasMoved();

		_myboard.doMove(mymove);

		boolean moveOK = true;
		if (_myboard.inCheck(_color)) {
			p.println("Illegal:  Move leaves king under attack.");
			moveOK = false;
		}

		_myboard.undoMove(mymove); // undo the move
		return moveOK;

		// NOTE have to deal w/ pawn promotions
	}

	/**
	 *  Print a list of moves.  Do not check if move
	 *  will leave the king in check.
	 **/
	private void printAllMoves(ListOMoves list, String strcolor) throws patzException
	{
		int numMoves = list._plyIndices[0][1];
		boolean moveOK = false;

		p.println(numMoves + " Legal Moves for " + strcolor);

		// test each move -- is there a move you can make that
		// doesn't leave the king in check?
		for (int i = 0; i < numMoves; ++i)
		{
			Move testmove = list._moveList[i];
			p.print(testmove.print() + "  ");
		}
	}

	/** 
	 *  Print a list of moves.  Only print ones which do 
	 *  not leave the king in check.
	 **/
	private void printAllLegalMoves(ListOMoves list, String strcolor, int color)  throws patzException
	{
		int numMoves = list._plyIndices[0][1];
		boolean moveOK = false;

		p.println(numMoves + " Legal Moves for " + strcolor);

		// test each move -- is there a move you can make that
		// doesn't leave the king in check?
		for (int i = 0; i < numMoves; ++i)
		{
			Move testmove = list._moveList[i];
			_myboard.doMove(testmove);

			if (!_myboard.inCheck(color)) { // is the king in check?
				p.print(testmove.print() + "  ");
			}

			_myboard.undoMove(testmove); // undo the move
		}
	}

	/** 
	 *  Does the user want to print debug output? 
	 *  NOTE: After the debug info is printed, the game
	 *        will print ***Illegal Move***, because you
	 *        didn't enter a valid chess move.  Ignore
	 *        that admonishment.
	 **/
	private boolean isDebugMove(String myinput, Move mymove) throws patzException
	{
		// Print all pseudo legal moves for white (these may leave the king in check)
		if (myinput.equals("W") || myinput.equals("WHITEPSEUDO"))
		{
			_listOMoves.reset();
			_myboard.generateAllMoves(Board.WHITE, _listOMoves); // get list of all possible moves
			printAllMoves(_listOMoves, "white");
			return true;
		} 
		// Print all legal moves for white	
		else if (myinput.equals("WL") || myinput.equals("WHITELEGAL"))
		{
			_listOMoves.reset();
			_myboard.generateAllMoves(Board.WHITE, _listOMoves); // get list of all possible moves
			printAllLegalMoves(_listOMoves, "white", _myboard.WHITE); // note we check for LEGAL moves
			return true;
		} 
		// Print all captures for white (may leave king in check)
		else if (myinput.equals("WC") || myinput.equals("WHITECAPTURES"))
		{
			_listOMoves.reset();
			_myboard.generateAllCaptures(Board.WHITE, _listOMoves); // get list of all possible moves
			printAllMoves(_listOMoves, "white");
			return true;
		} 
		// Print all non-captures for white (may leave king in check)
		else if (myinput.equals("WN") || myinput.equals("WHITENONCAPTURES"))
		{
			_listOMoves.reset();
			_myboard.generateAllNonCaptures(Board.WHITE, _listOMoves); // get list of all possible moves
			printAllMoves(_listOMoves, "white");
			return true;
		}
		// Print all pseudo legal moves for black (these may leave the king in check)
		else if (myinput.equals("B") || myinput.equals("BLACKPSEUDO"))
		{
			_listOMoves.reset();
			_myboard.generateAllMoves(Board.BLACK, _listOMoves); // get list of all possible moves
			printAllMoves(_listOMoves, "black");
			return true;
		} 
		// Print all legal moves for black	
		else if (myinput.equals("BL") || myinput.equals("BLACKLEGAL"))
		{
			_listOMoves.reset();
			_myboard.generateAllMoves(Board.BLACK, _listOMoves); // get list of all possible moves
			printAllLegalMoves(_listOMoves, "black", _myboard.BLACK); // note we check for LEGAL moves
			return true;
		} 
		// Print all captures for black (may leave king in check)
		else if (myinput.equals("BC") || myinput.equals("BLACKCAPTURES"))
		{
			_listOMoves.reset();
			_myboard.generateAllCaptures(Board.BLACK, _listOMoves); // get list of all possible moves
			printAllMoves(_listOMoves, "black");
			return true;
		} 
		// Print all non-captures for black (may leave king in check)
		else if (myinput.equals("BN") || myinput.equals("BLACKNONCAPTURES"))
		{
			_listOMoves.reset();
			_myboard.generateAllNonCaptures(Board.BLACK, _listOMoves); // get list of all possible moves
			printAllMoves(_listOMoves, "black");
			return true;
		}

		// Print board evaluations
		else if (myinput.equals("S") || myinput.equals("EVALBOARD")) 
		{
			p.println("Board evaluations for white & black:");
			_myboard.printEvaluation(_myboard.WHITE);
			_myboard.printEvaluation(_myboard.BLACK);
			return true;
		}
		return false; // not a debug command
	}
		
}