// Jeff Somers
// Jan 2001

import java.io.*;

public final class Move implements Cloneable
{
	protected int _color;
	protected int _fromSq; // 0 to 63, upper left is 0 (black rook), lower right is 63 (white rook)
	protected int _toSq;

	protected int _fromSqIndex;
	protected int _toSqIndex;
	protected boolean _fromSqHasMoved;

	protected int _enpassantIndex; // not used currently

	protected boolean _specialMove;
	protected boolean _castleKingSide;
	protected boolean _castleQueenSide;
	protected boolean _enpassant; // to be implemented later
	protected boolean _resign;
	protected boolean _offerDraw; 
	protected boolean _pawnPromotion; 

	protected int _rank;

	static PrintStream p = new PrintStream(System.out);

	private final String _boardprint[] = 
	{
	   "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", 
	   "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", 
	   "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6", 
	   "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5", 
	   "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4", 
	   "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3", 
	   "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", 
	   "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1", 		   
	};

	// constructor
	Move()
	{
		init();
	}

	public void init()
	{
		_color = -1;
		_fromSq = -1;
		_toSq = -1;

		_fromSqIndex = -1;
		_toSqIndex = -1;
		_fromSqHasMoved = false;

		_enpassantIndex = 1; // not used currently
		
		_specialMove = false;
		_castleKingSide = false;
		_castleQueenSide = false;
		_enpassant = false; // to be implemented later
		_resign = false;
		_offerDraw = false; 
		_pawnPromotion = false; 

		_rank = -1;
	}

	/**
	 *  Override equals 
	 **/
	public boolean equals(Move obj2)
	{
		if (obj2._color != _color) return false;

		// If the colors are the same & we're castling the
		// same way then they're equivalent
		if ((_castleKingSide && obj2._castleKingSide) ||
		    (_castleQueenSide && obj2._castleQueenSide))
		{
			return true;
		}

		if (obj2._fromSq !=_fromSq ||
		    obj2._toSq != _toSq ||
			obj2._fromSqIndex != _fromSqIndex ||
			obj2._toSqIndex != _toSqIndex ||
			obj2._fromSqHasMoved != _fromSqHasMoved)
		{
			return false;
		}

		if (obj2._enpassantIndex != _enpassantIndex || // not used currently
			obj2._specialMove != _specialMove ||
			obj2._enpassant != _enpassant || // to be implemented later
			obj2._resign  != _resign ||
			obj2._offerDraw != _offerDraw ||
			obj2._pawnPromotion != _pawnPromotion)
		{
			return false;
		}

		// does rank matter?  No.
		// if (obj2._rank != _rank) return false;

		return true;
	}

	// Load a Move objects with these values
	protected void loadValues(Move changeit)
	{
		changeit._color = _color;
		changeit._fromSq =_fromSq;
		changeit._toSq = _toSq ;

		changeit._fromSqIndex = _fromSqIndex;
		changeit._toSqIndex = _toSqIndex;
		changeit._fromSqHasMoved = _fromSqHasMoved;

		changeit._enpassantIndex = _enpassantIndex; // not used currently
		
		changeit._specialMove = _specialMove;
		changeit._castleKingSide = _castleKingSide;
		changeit._castleQueenSide = _castleQueenSide;
		changeit._enpassant = _enpassant; // to be implemented later
		changeit._resign = _resign;
		changeit._offerDraw = _offerDraw; 
		changeit._pawnPromotion =_pawnPromotion ; 

		changeit._rank = _rank;
	}

	// make duplicate of object
	protected Object clone()
	{
		Move clone = new Move();
		clone._color = _color;
		clone._fromSq =_fromSq;
		clone._toSq = _toSq ;

		clone._fromSqIndex = _fromSqIndex;
		clone._toSqIndex = _toSqIndex;
		clone._fromSqHasMoved = _fromSqHasMoved;

		clone._enpassantIndex = _enpassantIndex; // not used currently
		
		clone._specialMove = _specialMove;
		clone._castleKingSide = _castleKingSide;
		clone._castleQueenSide = _castleQueenSide;
		clone._enpassant = _enpassant; // to be implemented later
		clone._resign = _resign;
		clone._offerDraw = _offerDraw; 
		clone._pawnPromotion =_pawnPromotion ; 

		clone._rank = _rank;

		return clone;
	}

	static int convertMoveToIndex(char alpha, char num) throws patzException
	{
		// input is in the form A2A4, etc.
		// convert to a number from 0 to 63, where 0 is the upper
		// left hand corner of the board (from white's point of view)
		// and 63 is the lower right.
		Util.assert(alpha >= 'A' && alpha <= 'H' && num >= '1' && num <= '8');

		// so A8 will return 0 and H1 will return 63
		return ( ('8' - num) * 8 + (alpha - 'A'));
	}

	public String print() throws patzException
	{
		String printmv = null;

		if (_castleKingSide) {
			printmv = new String("O-O");
		} else if (_castleQueenSide) {
			printmv = new String("O-O-O");
		} else if (_resign) {
			printmv = new String("resigns");
		} else if (_offerDraw) {
			printmv = new String("offers draw");
		} else {
			Util.assert(_fromSq > -1 && _fromSq < 64);
			Util.assert(_toSq > -1 && _toSq < 64);

			printmv = new String(_boardprint[_fromSq] + _boardprint[_toSq]);
		}

		return printmv;
	}
}