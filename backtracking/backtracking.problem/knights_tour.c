#include<stdio.h>
#define N 30


/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N],int size) {
    int x,y;
    for (x = 0; x < size; x++) {
        for (y = 0; y < size; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}


/* A recursive utility function to solve Knight Tour problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N],int size) {
    //printf("solveKTUtil(%d,%d,%d,%d)\n",x,y, movei,size);
    //x,y当前马的位置，
    //movei，移动的第几步！
    int k, nx, ny;
    if (movei == size*size)
        return 1;
    int mx[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int ym[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    /* Try all next moves from the current coordinate x, y */
    for (k = 0; k < 8; k++) {
        nx = x + mx[k];
        ny = y + ym[k];
        if ( nx >= 0 && nx < size && ny >= 0 && ny < size && sol[nx][ny] == -1) {
            sol[nx][ny] = movei;
            if (solveKTUtil(nx, ny, movei+1, sol,size) == 1)
                return 1;
            else
                sol[nx][ny] = -1;// backtracking
        }
    }

    return 0;
}
/* This function solves the Knight Tour problem using Backtracking.  This
   function mainly uses solveKTUtil() to solve the problem. It returns false if
   no complete tour is possible, otherwise return true and prints the tour.
   Please note that there may be more than one solutions, this function
   prints one of the feasible solutions.  */
void solveKT(int size) {
    int sol[N][N];
    /* Initialization of solution matrix */
    int x,y;
    for (x = 0; x < N; x++)
        for (y = 0; y < N; y++)
            sol[x][y] = -1;

    /* xMove[] and ym[] define next move of Knight.
              xMove[] is for next value of x coordinate
                 ym[] is for next value of y coordinate */

    // Since the Knight is initially at the first block
    sol[0][0]  = 0;

    /* Start from 0,0 and explore all tours using solveKTUtil() */
    if(solveKTUtil(0, 0, 1, sol,size) == 0) {
        printf("Solution does not exist");
    } else
        printSolution(sol,size);
}

/* Driver program to test above functions */
int main() {
    int n=8;
    int i;
    for(i=0; i<n; i++) {
        printf("\n%d:\n",i);
        solveKT(i);
    }
    return 0;
}
