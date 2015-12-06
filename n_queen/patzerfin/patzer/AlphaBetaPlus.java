// Jeff Somers
// Jan 2001

import java.util.*;

/**
 *  This AI implements minimax searching w/
 *  alpha-beta cutoffs
 **/
public final class AlphaBetaPlus extends AI
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

	private int _history[][];
	
	boolean _orderByPrincContin; // are we ordering the moves by principal continuation?

	/**
	 *  constructor
	 **/
	AlphaBetaPlus(Board board)
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

		_history = new int[64][];
		for (int i = 0; i < _history.length; ++i)
		{
			_history[i] = new int[64];
			for (int j = 0; j < _history[i].length; ++j)
			{
				_history[i][j] = 0;
			}
		}
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
	 *  Initialize the history array of "Killer" Moves
	 *  These moves caused an alpha/beta cutoff, so we
	 *  want to remember them.
	 **/
	private void initHistory()
	{
		for (int i = 0; i < _history.length; ++i)
		{
			for (int j = 0; j < _history[i].length; ++j)
			{
				_history[i][j] = 0;
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
		initHistory();
		_nodesSearched = 0;
		_orderByPrincContin = true;

		p.println("Searching to ply: " + _maxply);
		long time1 = System.currentTimeMillis();
		
		p.println("ply\tscore\t# nodes\tPrincipal Continuation");
		p.println("\t\t(running");
		p.println("\t\ttotal)");
		for (int i = 1; i < (_maxply + 1); ++i)
		{
			_orderByPrincContin = true;
			int score = alphabeta(0, color, -1000000, 1000000, null, i); 

			p.print(i + "\t");
			p.print(score + "\t");
			p.print(_nodesSearched + "\t");
		
			// print principal continuation
			for (int j = 0; j < MAXPLY; ++j)
			{
				Move m = _principal[0][j];
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
		}
		long time2 = System.currentTimeMillis();
		double sec = (time2 - time1)/1000.0;
		p.println("Time taken: " + sec + " seconds.");
		p.println("Nodes searched/sec: " + (int)(_nodesSearched/sec));

		_principal[0][0].loadValues(move); //load move
	}

	/**
	 *   evaluate the moves according to the alpha beta pruning algorithm
	 *   We use negamax here, which means that we don't have to have separate
	 *   "min" and "max" subroutines, since those functions are "mirror
	 *   images" of each other.
	 **/
	private int alphabeta(int ply, int color, int alpha, int beta, Move currMove, int maxply) throws patzException
	{
		// max ply has to be at least one
		if (maxply == ply) {
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

		// assign a score to each move so that we may put the
		// moves most likely to cause cutoffs early in the list.
		// this increases the efficiency of alpha-beta cutoffs.
		rankMoves(_listOMoves, ply);

		// Get the # of elements in our slice of the list of moves
		int numMoves = _listOMoves._plyIndices[ply][1] - _listOMoves._plyIndices[ply][0];

		boolean havelegalmoves = false;
		int mIndex = _listOMoves._plyIndices[ply][0];
		while(numMoves != 0 && mIndex < _listOMoves._plyIndices[ply][1])
		{
			_nodesSearched++;

			 // put the move first that is most likely to generate a cutoff
			putBestMoveFirst(mIndex, _listOMoves, ply);
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
			int score = -alphabeta(ply + 1, nextcolor, -beta, -alpha, computerMove, maxply); 

			_board.undoMove(computerMove); // undo the move

			if (score > alpha)
			{

				// This move caused an alpha/beta cutoff, so we
				// want to remember it.
				_history[computerMove._fromSq][computerMove._toSq] += maxply - ply; // favor cutoffs higher in tree -- more effective

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
	 * assign a score to each move so that we may put the
	 * moves most likely to cause cutoffs early in the list.
	 * this increases the efficiency of alpha-beta cutoffs.
	 **/
	private void rankMoves(ListOMoves listOMoves, int ply) throws patzException
	{
		// Get the # of elements in our slice of the list of moves
		int numMoves = listOMoves._plyIndices[ply][1] - listOMoves._plyIndices[ply][0];

		int mIndex = listOMoves._plyIndices[ply][0];
		
		boolean princeContFound = false;
		while(numMoves != 0 && mIndex < listOMoves._plyIndices[ply][1])
		{
			// add principal variation score as well
			Move mv = listOMoves._moveList[mIndex];
			if (mv._toSqIndex != -1) // it's a capture
			{
				Piece pieces[] = null;
				int index1 = mv._toSqIndex;

				// Rank a queen capture > pawn capture, etc.
				if (mv._toSqIndex > 15)
				{
					pieces = _board._blackPieces;
					index1 = mv._toSqIndex - 16;
				} else {
					pieces = _board._whitePieces;
				}

				Piece p1 = pieces[index1];
				mv._rank = p1.getValue();
			}
			else
			{
				mv._rank = _history[mv._fromSq][mv._toSq];
			}
			
			// Okay, so what we want to do is take the best moves
			// as determined by the previous iteration & evaluate them
			// first, hopefully ensuring many cutoffs.  So if we previously
			// searched to 1 ply & found e2e4 was the best move, then when
			// we search to 2 ply we want to look at e2e4 first.  e2e4 may
			// not be the best move for a 2 ply search, but it has a very
			// good shot of being one of the best.  Looking at the best moves
			// first insures more alpha-beta cutoffs.
			if (_orderByPrincContin)
			{
				if (mv.equals(_principal[0][ply]))
				{
					mv._rank += 10000;
					princeContFound = true;
				}
			}
			mIndex++;
		}
		
		_orderByPrincContin = princeContFound;
	}

	/**
	 *  Put the best move first in the list to try to 
	 *  ensure a cutoff.
	 **/
	private void putBestMoveFirst(int mIndex, ListOMoves listOMoves, int ply)
	{
		// Get the # of elements in our slice of the list of moves
		int numMoves = listOMoves._plyIndices[ply][1] - listOMoves._plyIndices[ply][0];
		int orig = mIndex;
		int newindex = mIndex;

		while(numMoves != 0 && mIndex < listOMoves._plyIndices[ply][1])
		{
			Move mv = _listOMoves._moveList[mIndex];
			if (mv._rank > _listOMoves._moveList[newindex]._rank) {
				newindex = mIndex;
			}
			mIndex++;
		}

		// switch the moves
		if (newindex != orig)
		{
			//Move temp = new Move();
			//_listOMoves._moveList[newindex].loadValues(temp);
			//_listOMoves._moveList[orig].loadValues(_listOMoves._moveList[newindex]);
			//temp.loadValues(_listOMoves._moveList[orig]);

			Move temp = _listOMoves._moveList[newindex];
			_listOMoves._moveList[newindex] = _listOMoves._moveList[orig];
			_listOMoves._moveList[orig] = temp;
		}
	}


	/**
	 *  Provide a description for print outs.
	 **/
	public void describeSelf()
	{
		p.println("an alpha-beta AI with better move ordering at depth " + _maxply);
	}

}