// Jeff Somers
// Jan 2001

import java.util.*;

/**
 *  This AI implements minimax searching w/
 *  alpha-beta cutoffs
 **/
public final class SimpleAlphaBeta extends AI
{	
	ListOMoves _listOMoves;

	// the _principal continuation array holds
	// the best moves for each side.  If we're 
	// searching 4 ply, then the first row of the
	// array will store the 4 next "best" moves
	// for each player, as returned by the search.
	// See "How Computers Play Chess" by David Levy
	// and Monty Newborn for more info.
	Move _principal[][];

	private final int MAXPLY = 20;

	private int _nodesSearched;

	/**
	 *  constructor
	 **/
	SimpleAlphaBeta(Board board)
	{
		super(board);

		_listOMoves = new ListOMoves();

		// Init the array as a 2 dimensional 
		// MAXPLY x MAXPLY array
		_principal = new Move[MAXPLY][];
		for (int i = 0; i < _principal.length; ++i)
		{
			_principal[i] = new Move[MAXPLY];
			for (int j = 0; j < _principal[i].length; ++j)
			{
				_principal[i][j] = new Move();
			}
		}

		_nodesSearched = 0;
	}

	/**
	 *  Initialize the principal continuation array
	 **/
	private void initPrincipal()
	{
		for (int i = 0; i < _principal.length; ++i)
		{
			for (int j = 0; j < _principal[i].length; ++j)
			{
				_principal[i][j].init();
			}
		}

	}

	/**
	 *   pick the best move
	 **/
	public void selectMove(Move move, int color) throws patzException
	{
		_listOMoves.reset();
		initPrincipal();
		_nodesSearched = 0;

		p.println("Searching to ply: " + _maxply);
		long time1 = System.currentTimeMillis();
		int score = alphabeta(0, color, -1000000, 1000000, null);
		long time2 = System.currentTimeMillis();

		p.println("Computer evaluates score as: " + score + " (one pawn is worth 100).");
		p.println("Nodes searched: " + _nodesSearched);
		double sec = (time2 - time1)/1000.0;
		p.println("Time taken: " + sec + " seconds.");
		p.println("Nodes searched/sec: " + (int)(_nodesSearched/sec));

		
		// print principal continuation
		p.print("Principal continuation: ");
		for (int i = 0; i < MAXPLY; ++i)
		{
			Move m = _principal[0][i];
			if(m._castleKingSide || m._castleQueenSide) {
				p.print(" " +m.print());
				continue;
			}
			if (m._fromSq > -1 && m._fromSq < 64 &&
				m._toSq > -1 && m._toSq < 64) {
				p.print(" " +m.print());
				continue;
			}
			else 
			{
				break;
			}
		}
		p.println("");

		_principal[0][0].loadValues(move); //load move
	}

	/**
	 *   evaluate the moves according to the alpha beta pruning algorithm
	 *   We use negamax here, which means that we don't have to have separate
	 *   "min" and "max" subroutines, since those functions are "mirror
	 *   images" of each other.
	 **/
	private int alphabeta(int ply, int color, int alpha, int beta, Move currMove) throws patzException
	{
		// max ply has to be at least one
		if (_maxply == ply) {
			// Set the principal continuation array
			//currMove.loadValues(_principal[ply][ply]);

			return Evaluator.eval(_board, color);
		}

		// we have to worry about setting the right array coords
		_listOMoves.setCurrPly(ply);

		// generateAllMoves will generate all pseudo legal moves --
		// i.e. the moves are on the board, and the pieces move
		// correctly, but the moves may leave the king in check.
		_board.generateAllMoves(color, _listOMoves);

		// Get the # of elements in our slice of the list of moves
		int numMoves = _listOMoves._plyIndices[ply][1] - _listOMoves._plyIndices[ply][0];

		boolean havelegalmoves = false;
		int mIndex = _listOMoves._plyIndices[ply][0];
		while(numMoves != 0 && mIndex < _listOMoves._plyIndices[ply][1])
		{
			_nodesSearched++;
			Move computerMove = _listOMoves._moveList[mIndex];

			_board.doMove(computerMove); // perform the move

			// If this move leaves our king in check, it's illegal.
			// Get the next move.
			if (_board.inCheck(color)) {
				mIndex++;
				_board.undoMove(computerMove);
				continue;
			}
			havelegalmoves = true;

			int nextcolor = (color == Board.WHITE) ? Board.BLACK : Board.WHITE;

			// NOTE that the alpha & beta values are switched the next call
			// to alphabeta().  This is intentional and is the key to the
			// negamax algorithm.
			int score = -alphabeta(ply + 1, nextcolor, -beta, -alpha, computerMove); 

			_board.undoMove(computerMove); // undo the move

			if (score > alpha)
			{
				// We're pruning!
				if (score >= beta)
				{
					return beta; // update player's score
				}
				alpha = score; // update "best so far"
			
				// Update the principal variation array
				computerMove.loadValues(_principal[ply][ply]);
				for (int i = ply + 1; i < MAXPLY; ++i) 
				{
					_principal[ply + 1][i].loadValues(_principal[ply][i]);
				}
			}

			mIndex++;
		}

		// if no legal moves, determine if stalemate or checkmate
		if (!havelegalmoves)
		{
			if(_board.inCheck(color))
			{
				// We're checkmated!
				return  -1000000 + ply;
			}
			else
			{
				return 0; // stalemate
			}
		}
		
		return alpha;
	}

	/**
	 *  Provide a description for print outs.
	 **/
	public void describeSelf()
	{
		p.println("a simple alpha-beta AI with depth " + _maxply);
	}

}