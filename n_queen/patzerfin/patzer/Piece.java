// Jeff Somers
// Jan 2001

public abstract class Piece
{
	private boolean _captured;
	protected int _value;
	protected boolean _hasMoved;
	protected int _bonus[];
	protected int _color;
	protected int _piecenum;
	protected char _symbol;
	protected Board _board;

	public abstract void genPseudoLegalMoves();
	public abstract boolean isLegalMove(int fromsq, int tosq) throws patzException;
	public abstract boolean isLegalCapture(int fromsq, int tosq) throws patzException;

	// constructor
	Piece(int piececolor, int piecenum, char symbol, Board board) throws patzException
	{
		Util.assert(piececolor == Board.BLACK || piececolor == Board.WHITE);
		Util.assert(board != null);
		Util.assert(piecenum >= 0 && piecenum <= 31);

		if (piececolor == Board.BLACK) {
			_symbol = Character.toUpperCase(symbol);
		}
		else { // white is lower case
			_symbol = Character.toLowerCase(symbol);
		}
		_piecenum = piecenum;
		_color = piececolor;
		_captured = false;
		_hasMoved = false;
		_board = board;
		_bonus = new int[120];

		for (int i = 0; i < _bonus.length; ++i)
		{
			_bonus[i] = -999;
		}
	}

	public boolean isCaptured() {return _captured;}
	public void setCaptured() {_captured = true;}
	public void setUncaptured() {_captured = false;} // when undo a move

	public boolean hasMoved() {return _hasMoved;}
	public void setMoved() {_hasMoved = true;}
	public void setUnmoved() {_hasMoved = false;} // when undo a move
	public void setMovedValue(boolean mv) {_hasMoved = mv;}

	char getSymbol() {return _symbol;}

	int getColor() {return _color;}

	public abstract void  generateAllCaptures(ListOMoves list, int position) throws patzException; // generate all captures for piece
	public abstract void generateAllNonCaptures(ListOMoves list, int position) throws patzException; // generate all non-captures

	/** 
	 *  Return value of piece (pawn = 100, knight = 300, etc.)
	 **/
	public abstract int getValue();
}