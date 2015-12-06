#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#include <string.h>

#include "timers.c"

extern short int Opt1, Opt2;

void Picture (int Image[], int Size)
{
   int Row, Col, Tst;

   for (Row = 0; Row < Size; Row++)
   {
      putchar ('\n');
      Tst = Image[Row];
      for (Col = 0; Col < Size; Col++)
      {
         putchar (' ');
         putchar ( Col == Tst ? 'Q' : '.' );
      }
   }
   putchar('\n');
   putchar('\n');
}

/* Check two vectors for equality; return first inequality (a la strncmp) */
int intncmp (int L[], int R[], int N)
{
   int Idx;

   for (Idx = 0; Idx < N; Idx++)
      if ( L[Idx] - R[Idx] )
         return L[Idx]-R[Idx];
   return 0;
}

/* Rotate +90 or -90: */
void Rotate(int R[], int C[], int N, int Neg)
{
   int Idx, Jdx;

   Jdx = Neg ? 0 : N-1;
   for (Idx = 0; Idx < N; Neg ? Jdx++ : Jdx--)
      C[Idx++] = R[Jdx];
   Jdx = Neg ? N-1 : 0;
   for (Idx = 0; Idx < N; Neg ? Jdx-- : Jdx++)
      R[C[Idx++]] = Jdx;
}

void Vmirror(int R[], int N)
{
   int Idx;

   for (Idx = 0; Idx < N; Idx++)
      R[Idx] = (N-1) - R[Idx];
   return;
}

int SymmetryOps(
    int Board[],               /* The fully-populated board         */
    int Trial[],               /* Used for symmetry checks          */
                               /* Holds its own scratch space too!  */
    int Size)                  /* Number of cells in a row/column   */
{
   int     Row, Col, Idx;      /* Row, Column, string offset        */
   int     Nequiv;             /* Number equivalent boards          */

/* Copy over; now Trial will be subjected to the transformations    */
   for (Idx = 0; Idx < Size; Idx++)
      Trial[Idx] = Board[Idx];

/* 90 degrees --- clockwise */
   Rotate (Trial, &Trial[Size], Size, 0);
   Idx = intncmp (Board, Trial, Size);
   if (Idx > 0) return 0;
   if ( !Idx )
      Nequiv = 1;
   else
   {
/* 180 degrees */
      Rotate (Trial, &Trial[Size], Size, 0);
      Idx = intncmp (Board, Trial, Size);
      if (Idx > 0) return 0;
      if ( !Idx )
         Nequiv = 2;
      else
      {
/* 270 degrees */
         Rotate (Trial, &Trial[Size], Size, 0);
         Idx = intncmp (Board, Trial, Size);
         if (Idx > 0) return 0;
         Nequiv = 4;
      }
   }
/* Reflect -- vertical mirror */
   for (Idx = 0; Idx < Size; Idx++)
      Trial[Idx] = Board[Idx];
   Vmirror (Trial, Size);
   Idx = intncmp (Board, Trial, Size);
   if (Idx > 0) return 0;
/* -90 degrees --- equiv. to diagonal mirror */
   Rotate (Trial, &Trial[Size], Size, -1);
   Idx = intncmp (Board, Trial, Size);
   if (Idx > 0) return 0;
/* -180 degrees --- equiv. to horizontal mirror */
   Rotate (Trial, &Trial[Size], Size, -1);
   Idx = intncmp (Board, Trial, Size);
   if (Idx > 0) return 0;
/* -270 degrees --- equiv. to anti-diagonal mirror */
   Rotate (Trial, &Trial[Size], Size, -1);
   Idx = intncmp (Board, Trial, Size);
   if (Idx > 0) return 0;
/* WE HAVE A GOOD ONE! */
   return Nequiv * 2;
}

void Mark (
     int R, int C, int Size,
     short Col[], short Diag[], short AntiD[])
{
   int Idx;

   Col[C] = 1;
/* Diagonal:  Row-Col == constant */
   Idx = R - C + Size-1;
   Diag[Idx] = 1;
/* AntiDiagonal:  Row+Col == constant */
   Idx = R + C;
   AntiD[Idx] = 1;
}

void Unmark (
     int R, int C, int Size,
     short Col[], short Diag[], short AntiD[])
{
   int Idx;

   Col[C] = 0;
/* Diagonal:  Row-Col == constant */
   Idx = R - C + Size-1;
   Diag[Idx] = 0;
/* AntiDiagonal:  Row+Col == constant */
   Idx = R + C;
   AntiD[Idx] = 0;
}

int Valid (
    int Board[], int Size, int Row,
    short Col[], short Diag[], short AntiD[] )
{
   int  Chk, Idx;

   if (Opt1)
   {
      Chk = Col[Board[Row]];
/*    Diagonal:  Row-Col == constant */
      Idx = Row - Board[Row] + Size-1;
      Chk = Chk || Diag[Idx];
/*    AntiDiagonal:  Row+Col == constant */
      Idx = Row + Board[Row];
      Chk = Chk || AntiD[Idx];
      return !Chk;
   }
   else
   {
      for (Chk = 0; Chk < Row; Chk++)
         if (  Board[Chk] == Board[Row] ||
               abs(Board[Row]-Board[Chk]) == (Row-Chk) )
            return 0;
      return 1;
   }
}
