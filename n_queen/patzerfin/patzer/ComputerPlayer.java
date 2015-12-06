// Jeff Somers
// Jan 2001

import java.io.*;
import java.util.*;

public final class ComputerPlayer extends Player
{
	static PrintStream p = new PrintStream(System.out);
	static DataInputStream dis = new DataInputStream(System.in);
	static StringTokenizer st;

	AI _ai = null;
	
	// constructor
	ComputerPlayer(int mycolor, Board myboard) throws patzException
	{
		super(mycolor, myboard);

		getAI();
	}

	private void getAI() throws patzException
	{
		try
		{
			p.print("Computer is playing ");
			p.println((_color == Board.WHITE) ? "white." : "black.");
			String input ;
			boolean needPly = false;
			for (;;)
			{
				p.println("\nPlease select how you wish the computer to play:");
				p.println("\nType the number of the selection and press Enter.");
				p.println("\t1\tRandom Move");
				p.println("\t2\tSimple Alpha Beta");
				p.println("\t3\tAlpha Beta with better move ordering");
				input = dis.readLine().trim();
				if (!input.equals("1") && !input.equals("2") &&
					!input.equals("3")) {
					continue;
				} else {
					break;
				}
			}
			if (input.equals("1")) {
				_ai = new RandomMover(_myboard);
			}
			if (input.equals("2")) {
				_ai = new SimpleAlphaBeta(_myboard);
				needPly = true;
			}
			if (input.equals("3")) {
				_ai = new AlphaBetaPlus(_myboard);
				needPly = true;
			}
			if (needPly)
			{
				for (;;)
				{
					p.println("\nPlease select the number of plies to search: ");
					st = new StringTokenizer(dis.readLine());
					int ply = Integer.parseInt(st.nextToken());
					if (ply < 1 || ply > 5) {
						p.println("Min is 1, Max is 5");
						continue;
					}
					_ai._maxply = ply;
					break;
				}
			}
			
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}


	public void getMove(Move move) throws patzException
	{
		move._color = _color;
		p.println("Computer will now move for " + 
			((_color == Board.WHITE) ? "white." : "black."));
		_ai.selectMove(move, _color);
		p.println("Computer moves " + move.print());
	}

	public void describeSelf()
	{
		p.print("Computer Player with ");
		_ai.describeSelf();
	}

}