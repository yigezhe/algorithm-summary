// Jeff Somers
// Jan 2001

import java.util.*;

public final class RandomMover extends AI
{	
	ListOMoves _listOMoves;
	Random _rand;

	// constructor
	RandomMover(Board board)
	{
		super(board);

		_listOMoves = new ListOMoves();

		_rand = new Random();
	}

	public void selectMove(Move move, int color) throws patzException
	{
		// go to board, generate all moves for that color
		// put in ListOMoves
		// for ply 0, pick one move
		// return it, if doesn't put king in check

		_listOMoves.reset();
		_board.generateAllMoves(color, _listOMoves);

		int numMoves = _listOMoves._plyIndices[0][1];

		// Check that move does not leave king in check
		boolean moveOK = false;
		Move computerMove = null;
		while (!moveOK)
		{
			int mymove = Math.abs(_rand.nextInt()) % numMoves;

			computerMove = _listOMoves._moveList[mymove];

			_board.doMove(computerMove);

			if (!_board.inCheck(color)) {
				moveOK = true;
			}

			_board.undoMove(computerMove); // undo the move
		}

		computerMove.loadValues(move); // change values of move
	}

	public void describeSelf()
	{
		p.println("a randomly moving AI.");
	}

}