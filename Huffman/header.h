#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 255

typedef struct C
{
	char simbols[SIZE];
	struct C* left;
	struct C* right;
}child;

typedef struct Q
{
	char simbols[SIZE];
	unsigned short int count;
	struct Q* next;
	child* left;
	child* right;
}queue;

void cntsimb(unsigned short int count[SIZE], char simbols[SIZE], char s[SIZE], unsigned short int* k);
queue* push(queue* root, unsigned short int count, char simbol);
void create_child(queue** root);
queue* delete(queue** root);
queue* copy(queue* root);
queue* sort(queue* root);
queue* create_child_for_child(queue* currroot, queue* nextroot);
queue* pop(queue* root);
void code(child* tree, char simbols[SIZE], char currcode[SIZE][SIZE], unsigned short int k, unsigned short int* q, unsigned short int i, unsigned short int codiki[SIZE]);