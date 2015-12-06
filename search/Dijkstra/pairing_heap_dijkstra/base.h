#ifndef _BASE_H
#define _BASE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VERTEXNUM 7
#define FALSE (0)
#define TRUE (1)
#define MAXSIBLINGS ((VERTEXNUM)+1)

typedef int BOOL;
typedef double ValueType;

typedef struct {
	int vindex;
	ValueType dist;
} Item;

#endif

