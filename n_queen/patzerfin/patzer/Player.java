// Jeff Somers
// Jan. 2001


public abstract class Player
{
	protected int _color; // is player playing WHITE or BLACK pieces?
	protected Board _myboard;

	Player(int mycolor, Board myboard) throws patzException
	{
		Util.assert(mycolor == Board.WHITE || mycolor == Board.BLACK);
		Util.assert(myboard != null);

		_color = mycolor;
		_myboard = myboard;
	}

	public abstract void getMove(Move move) throws patzException;
	public abstract void describeSelf();
}