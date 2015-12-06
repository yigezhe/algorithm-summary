// Jeff Somers
// Patzer Chess Playing Program
// January, 2001

//package patzer;

import java.io.*;

public final class patzer
{
	static DataInputStream dis = new DataInputStream(System.in);
	static PrintStream p = new PrintStream(System.out);

	public static void main(String args[])
	{
		try
		{
			Util.setAsserts(true); // turn assertions on
			System.out.println("Welcome to Patzer, a chess playing program.");
			Game mygame = new Game();
			mygame.play();
			System.out.println("Goodbye.");
		}
		catch(patzException e)
		{
			System.out.println("caught patzException in main()");
			e.printStackTrace();
		}
		catch(Exception e)
		{
			System.out.println("caught Exception in main()");
			e.printStackTrace();
		}

		// We want the window to stay up if debugging or if user
		// double clicked on an executable.
		try
		{
			p.println("\nPress Enter key to quit Patzer.");
			dis.readChar();
		}
		catch(Exception e)
		{
			System.out.println("caught Exception in main()");
			e.printStackTrace();
		}
	}
}