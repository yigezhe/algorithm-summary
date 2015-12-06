// Jeff Somers
// 1/2001

import java.util.*;
import java.io.*;

import Move;
// Class Game stores the two players, the
// attributes of the game (time limits, etc.)
// and the list of moves played.
public final class Game
{
	private Player _playerWhite;
	private Player _playerBlack;
	private Board _myBoard;
	private int _numsecs;
	private Vector _moves;

	static DataInputStream dis = new DataInputStream(System.in);
	static PrintStream p = new PrintStream(System.out);


	// constructor
	Game() throws patzException
	{
		_myBoard = new Board();
	}

	public void play() throws patzException
	{
		getPlayers();
		runGame();
		printPlayers();
	}

	private void printPlayers()
	{
		p.print("White player was a ");
		_playerWhite.describeSelf();
		p.print("Black player was a ");
		_playerBlack.describeSelf();
	}

	private void runGame() throws patzException
	{
		_myBoard.printboard();
		Move move = new Move();
		for (;;)
		{
			move.init();
			 _playerWhite.getMove(move);
			// if is special move & not cancelling, break
			 if (move._resign || move._offerDraw) {
				 break;
			 }
			_myBoard.doMove(move);
			_myBoard.incMoveCount(); // add one to # of moves
			_myBoard.printboard();
			// is there a legal move for black?
			if (!_myBoard.legalMoveExists(Board.BLACK)) {
				break;
			}
			move.init();
			_playerBlack.getMove(move);
			// if is special move & not cancelling, break
			 if (move._resign || move._offerDraw) {
				 break;
			 }
			_myBoard.doMove(move);
			_myBoard.incMoveCount(); // add one to # of moves
			_myBoard.printboard();
			// is there a legal move for white?
			if (!_myBoard.legalMoveExists(Board.WHITE)) {
				break;
			}
		}

		// get move from first player (white)
		// is there a legal move left? draw, stalemate, checkmate
		// has player resigned? if more than 50 moves (100 ply) will offer to resign/draw
		// get move from 2nd player (black)
		// is there a legal move left?
	}

	private String getHC(String color)
	{
		boolean done = false;
		String input = "";
		try
		{
			while (!done)
			{
				// This is not a critical loop, so we don't need examine
				// using StringBuffers here instead of Strings.
				System.out.print("Will " + color + " be played by a Human or Computer (H/C)? ");
				input = dis.readLine();
				input = input.toUpperCase();
				if (!input.equals("H") && !input.equals("C"))
				{
					System.out.println("Please type the letter H or C and then press Enter");
					continue;
				}
				done = true;
			}
		}
		catch(IOException ioe)
		{
			System.out.println(ioe);
			System.exit(-1);
		}
		return input;
	}

	private void getPlayers() throws patzException
	{
		String player = getHC("white");
		if (player.equals("H"))
		{
			_playerWhite = new HumanPlayer(Board.WHITE, _myBoard);
		}
		else
		{
			_playerWhite = new ComputerPlayer(Board.WHITE, _myBoard);
		}

		player = getHC("black");
		if (player.equals("H"))
		{
			_playerBlack = new HumanPlayer(Board.BLACK, _myBoard);
		}
		else
		{
			_playerBlack = new ComputerPlayer(Board.BLACK, _myBoard);
		}
	}


}