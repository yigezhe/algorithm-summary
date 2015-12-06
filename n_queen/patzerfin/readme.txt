Jeff Somers
jsomers@alumni.williams.edu
11 January 2000

Patzer chess playing program

===

Source

The compiled class files and source are in patzer.zip.

===

How to run:

If you have version 1.2 or above of the Java JVM, you can enter 
this command to run:

	java -jar patzer.zip

If you have version 1.1, you have to unpack the zip file, 
extract the class files, and run

	java patzer

(This is how you have to run it on ice.harvard.edu)

With Microsoft's JVM, you can run

	jview /cp patzer.zip patzer

You can also run patzer.exe through Windows.

===

Input your moves as follows:

e2e4
b1a3

etc.

You can also castle:
O-O
O-O-O

Other commands include 

quit
draw

Input is not case sensitive,
so both e2e4 and E2E4 are allowed.

Pawn promotions are not supported.
Neither are en passant captures.
patzer doesn't really know about draws, so it
will keep playing until a checkmate or stalemate,
too many moves occur, or a user enters QUIT or DRAW.

===

patzer has 3 AI opponents: a random mover, an alpha-beta search & an 
alpha-beta search with improved move ordering for more cutoffs.  The
latter two will return moves with the same score, but the improved
a-b AI will be faster.

Here's one example of the efficiencies which can found
(see simplealphabeta.txt and alphabetaplus.txt)

		Regular AlphaBeta	Alpha Beta Improved
move 1	
nodes searched	16125			3852
time		17.837 sec		3.735 sec

move 2		26733			5088
nodes searched	31.022 sec		4.397 sec
time

move 3
nodes searched	38613			3712
time		34.58 sec		3.948 sec



Techniques used for move ordering:

1)  History Table

If a move causes a cutoff, it is stored in the history array, which is
a 64 x 64 array of ints, corresponding to the from position and the
to position of the piece moved.

patzer will generate all moves for a given board, then rank them according
to how good they appear to be.  We want to check the promising moves first
since that will resort in more alpha-beta cutoffs, which means fewer nodes
searched, which means the search works faster.

Moves are checked against the history table & bumped up in priority if the
move previously generated a cutoff.

2)  Captures

Captures are generally good moves, and are rated according to the strength
of the piece captured.  Capturing a queen is a better move than capturing
a knight.

Captures are generally rated higher than moves in the history table.

3)  Principal Continuation

patzer will first search the game tree to a depth of 1 ply.  It will then
start all over and search it to a depth of 2 ply, etc., until the max.
ply is reached.

Why do this?  To make the last ply search as efficient as possible, 'cause
it's only the last one that takes time.

Example:

In chess there are about 30 moves possible for each position.  So the first
ply search will look at 30 possibilities.  The next will look at (worst case)
30 x 30, or 900 moves.  The third will take 30 x 900 = 27000 moves, and a 
search of depth 4 will look at 810,000 moves.  That last search will take
up 97% of the time, so a little redundancy will be hardly be noticed it.

At each ply the search returns the best move, and tries that as the first
move for the next search.

Example:

patzer searches to 1 ply and finds the best move is e2e4.  patzer will 
then try e2e4 as the first move for the 2 ply search.  Say the 2 ply 
search finds that d2d4 d7d5 is the best line.  Then those two moves
will be tried first for the 3 ply search.

