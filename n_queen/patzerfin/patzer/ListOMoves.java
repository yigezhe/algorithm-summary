// Jeff Somers
// Jan 2001


public final class ListOMoves 
{	
	final int MAXMOVES = 2000;

	final int MAXPLY = 50;

	int _plyIndices[][];

	Move _moveList[];

	int _currPly;
	int _topOfList;

	// constructor
	ListOMoves()
	{
		// So, the ListOfMoves stores the moves generated during
		// the AI's search.  Rather than creating & discarding all
		// these Move objects each time its the AI's turn, we keep a
		// stack & reinitialize the moves each time.

		// The _plyIndices array stores the indexes into the moves.
		_plyIndices = new int[MAXPLY][];
		for (int i = 0; i < MAXPLY; ++i) {
			_plyIndices[i] = new int[2];
		}

		_moveList = new Move[MAXMOVES];

		for (int i = 0; i < MAXMOVES; ++i) {
			_moveList[i] = new Move();
		}

		_currPly = 0;
		_topOfList = 0;
	}

	public void reset() // reset the list
	{
		_currPly = 0;
		_topOfList = 0;
		for (int i = 0; i < MAXPLY; ++i) {
			_plyIndices[i][0] = _plyIndices[i][1] = 0;
		}
	}

	public void setCurrPly(int ply) {
		_currPly = ply;
		if (ply > 0)
		{
			_plyIndices[_currPly][0] = _plyIndices[_currPly-1][1]; // start of new ply in list
			_plyIndices[_currPly][1] = _plyIndices[_currPly][0]; // end of ply in new list
			_topOfList = _plyIndices[_currPly][0];
		}
		else
		{
			_topOfList = 0;
			_plyIndices[_currPly][0] = _topOfList; // start of new ply in list
			_plyIndices[_currPly][1] = _topOfList;
		}
}

	public int getCurrPly() {return _currPly;}

	public Move giveOutNewMove() throws patzException
	{
		Util.assert(_topOfList < MAXMOVES);

		_plyIndices[_currPly][1] = _topOfList + 1; // ply has one more move

		_moveList[_topOfList].init(); // reinit the move
		return _moveList[_topOfList++];
	}

}