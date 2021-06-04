#ifndef KP9_H
#define KP9_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct _Key
{
	int key;
} Key;


typedef struct _Val
{
	char val[81];
} Val;

void printTable(const Key* k, const Val* v, const int size);
int binSearch(const Key* k, const Val* v, const int size, const Key key);
void sort(Key* k, Val* v, const int size);
void scramble(Key* k, Val* v, const int size);
void reverse(Key* k, Val* v, const int size);
void swap(Key* k1, Key* k2, Val* v1, Val* v2);
void sift(Key* k, Val* v, int start, int end);


void getRow(FILE* stream, char* str, const int size);
void swapRows(Key* k, Val* v, const int a, const int b);
int comparator(const Key k1, const Key k2);
int isEqualKeys(const Key k1, const Key k2);
int randomAB(const int a, const int b);
int isSorted(const Key* k, const int size);



#endif
