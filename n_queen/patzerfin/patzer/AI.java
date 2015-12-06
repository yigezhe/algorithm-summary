// Jeff Somers
// Jan 2001

import java.io.*;

public abstract class AI
{
	static PrintStream p = new PrintStream(System.out);
	
	protected Board _board;
	protected int _maxply; // to what depth are we searching in the game tree?
	protected boolean _needPly; // are we using alphabeta searches & need the user
					// to enter a depth of search parameter?

	// constructor
	AI(Board board)
	{
		_board = board;
		_maxply = 0;
		_needPly = false;
	}

	public abstract void selectMove(Move move, int color) throws patzException;

	public abstract void describeSelf();

}