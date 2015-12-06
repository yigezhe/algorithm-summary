#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
#include <ctype.h>
#include <string.h>
#include "common_s.c"

long int Nunique = 0,
         Ntotal  = 0;

short  Opt1, Opt2;

float *Calc, Lapsed = 0;

void Nqueens (int Board[], int Trial[], int Size, int Row)
{
   int Idx, Lim, Vtemp;
   static short int *Col, *Diag, *AntiD = NULL;

   if ( ! AntiD )
   {
      Col = (short *) calloc (Size, sizeof *Col);
      Diag = (short *) calloc ( 2*Size-1, sizeof *Diag );
      AntiD = (short *) calloc ( 2*Size-1, sizeof *AntiD );
      if ( !AntiD )
      {
         puts ("calloc failed --- out of memory!");
         exit (6);
      }
   }

   if (Row < Size-1)
   {
      if (Valid (Board, Size, Row, Col, Diag, AntiD))
      {
         if (Opt1)
            Mark (Row, Board[Row], Size, Col, Diag, AntiD);
         Nqueens (Board, Trial, Size, Row+1);
         if (Opt1)
            Unmark (Row, Board[Row], Size, Col, Diag, AntiD);
      }
      Lim = Row ? Size : (Size+1)/2 ;
      for (Idx = Row+1; Idx < Lim; Idx++)
      {
         Vtemp = Board[Idx];
         Board[Idx] = Board[Row];
         Board[Row] = Vtemp;
         if (Valid (Board, Size, Row, Col, Diag, AntiD))
         {
            Mark (Row, Board[Row], Size, Col, Diag, AntiD);
            Nqueens (Board, Trial, Size, Row+1);
            Unmark (Row, Board[Row], Size, Col, Diag, AntiD);
         }
      }
/*    Regenerate original vector from Row to Size-1:  */
      Vtemp = Board[Row];
      for (Idx = Row+1; Idx < Size; Idx++)
         Board[Idx-1] = Board[Idx];
      Board[Idx-1] = Vtemp;
   }
   else
   {
      if ( !Valid (Board, Size, Row, Col, Diag, AntiD) )
         return;
      Idx = SymmetryOps (Board, Trial, Size);
      if (Idx)
      {
         Nunique++;
         Ntotal += Idx;
      }
   }

   return;
}

void Nqueens1 (int Board[], int Trial[], int Size, int Row)
{
   int Col;
   int Tst;
   static short int *Cck, *Diag, *AntiD = NULL;

   if ( ! AntiD )
   {
      Cck = (short *) calloc (Size, sizeof *Cck);
      Diag = (short *) calloc ( 2*Size-1, sizeof *Diag );
      AntiD = (short *) calloc ( 2*Size-1, sizeof *AntiD );
      if ( !AntiD )
      {
         puts ("calloc failed --- out of memory!");
         exit (6);
      }
   }

   if (Row == Size)
   {
      Tst = SymmetryOps (Board, Trial, Size);
      if (Tst)
      {
         Nunique++;
         Ntotal += Tst;
      }
   }
   else
      for (Col = 0; Col < Size; Col++)
      {
         Board[Row] = Col;
         if (Valid (Board, Size, Row, Cck, Diag, AntiD))
         {
            if (Opt1)
               Mark (Row, Board[Row], Size, Cck, Diag, AntiD);
            Nqueens1 (Board, Trial, Size, Row+1);
            if (Opt1)
               Unmark (Row, Board[Row], Size, Cck, Diag, AntiD);
         }
      }
}

main(int argc, char *argv[])
{
   int  *Board, *Trial, Idx, Lim, Size;
   FILE *fptr;
   float Clock, CPUscr, ClockScr;

   if (argc < 2)
   {
      fputs ("Size:  ", stdout);
      scanf ("%d", &Size);
   }
   else
   {
      Size = atoi(argv[1]);
   }
   if (argc < 3)
   {
      fputs ("Optimization?  0, 1, 2, or 3:  ", stdout);
      scanf ("%d", &Idx);
   }
   else
   {
      Idx = atoi(argv[2]);
   }
   Opt1 = Idx & 1;
   Opt2 = (Idx>>1) & 1;

   Calc = (float *) calloc (Size, sizeof *Calc);
   Board = (int *) calloc (Size, sizeof *Board);
   Trial = (int *) calloc (Size*2, sizeof *Board);
/* Initial permutation generated. */
   for (Idx = 0; Idx < Size; Idx++)
      Board[Idx] = Idx;

   cputime(&CPUscr);                 /* Zero the counter */
   ClockTime(&ClockScr);
   if (Opt2)
      Nqueens (Board, Trial, Size, 0);
   else
      Nqueens1(Board, Trial, Size, 0);
   Lapsed += cputime(&CPUscr);
   Clock = ClockTime(&ClockScr);

   printf ("%3d ==> %10ld  %10ld  %10.4f  %10.4f\n",
           Size, Nunique, Ntotal, Lapsed, Clock);

   fptr = fopen("Nqueens.out", "a");
   fprintf (fptr, "%3d ==> %10ld  %10ld  %10.4f  %10.4f",
            Size, Nunique, Ntotal, Lapsed, Clock);

   fprintf (fptr, "%5d\n", Opt1 + 2*Opt2);
   fclose (fptr);

   return 0;
}
