#include "header.h"

void cntsimb(unsigned short int count[SIZE], char simbols[SIZE], char s[SIZE], unsigned short int* k)             //A function that finds unique characters and their frequency.
{
	unsigned short int len = strlen(s);
	for (unsigned short int i = 0; i < len; i++)
	{
		unsigned short int flag = 0;
		for (unsigned short int j = 0; j < len; j++)
		{
			if (simbols[j] == s[i])
			{
				flag = 1;
				count[j]++;
				j = len;
			}
		}
		if (!flag)
		{
			simbols[(*k)] = s[i];
			count[(*k)]++;
			(*k)++;
		}
	}
	count[(*k)]++;
}

queue* push(queue* root, unsigned short int count, char simbol)                                                 //A function that creates a tree queue
{
	if (root)
	{
		if (root->count < count)
		{
			root->next = push(root->next, count, simbol);
		}
		else
		{
			unsigned short int tempcount = root->count;
			char tempsimbol = (root->simbols)[0];
			root->count = count;
			(root->simbols)[0] = simbol;
			root->next = push(root->next, tempcount, tempsimbol);

		}
	}
	else
	{
		root = (queue*)malloc(sizeof(queue));
		root->count = count;
		char temp[SIZE] = { 0 };
		strncpy(root->simbols, temp, SIZE);
		(root->simbols)[0] = simbol;
		root->next = NULL;
		root->left = NULL;
		root->right = NULL;
	}
	return root;
}

void create_child(queue** root)                                                                                //Function that creates children
{
	(*root)->left = (child*)malloc(sizeof(child));
	(*root)->right = (child*)malloc(sizeof(child));
	char temp[SIZE] = { 0 };
	strncpy((*root)->left->simbols, temp, SIZE);
	strncpy((*root)->right->simbols, temp, SIZE);
	(*root)->left->left = NULL;
	(*root)->left->right = NULL;
	(*root)->right->left = NULL;
	(*root)->right->right = NULL;
}

queue* delete(queue** root)                                                                                   //Function to remove a tree from the queue
{
	queue* temproot = (*root)->next;
	free((*root));
	return temproot;
}

queue* copy(queue* root)                                                                                       //Tree Copy Function
{
	queue* temp = NULL;
	temp = (queue*)malloc(sizeof(queue));
	temp->count = root->count;
	char temp2[SIZE] = { 0 };
	strncpy(temp->simbols, temp2, SIZE);
	strcpy(temp->simbols, root->simbols);
	temp->next = NULL;
	temp->left = root->left;
	temp->right = root->right;
	return temp;
}

queue* sort(queue* root)                                                                                       //A function that sorts trees in ascending order of frequency
{
	if (root->next)
	{
		if (root->count > root->next->count)
		{
			queue* temp = copy(root->next);
			root->next = delete(&root->next);
			temp->next = root;
			temp->next = sort(temp->next);
			root = temp;
		}
	}
	return root;
}

queue* create_child_for_child(queue* currroot, queue* nextroot)                                                 //No comments
{
	if (currroot->left)
	{
		char temp[SIZE] = { 0 };
		char temp1[SIZE] = { 0 };
		char temp2[SIZE / 2] = { 0 };
		strcpy(temp1, currroot->left->simbols);
		strcpy(temp2, currroot->right->simbols);
		sprintf(temp1, "%s%s", temp1, temp2);
		if (nextroot->left)
		{
			char temp3[SIZE] = { 0 };
			char temp4[SIZE / 2] = { 0 };
			strcpy(temp3, nextroot->left->simbols);
			strcpy(temp4, nextroot->right->simbols);
			sprintf(temp3, "%s%s", temp3, temp4);
			child* addtree1 = (child*)malloc(sizeof(child));
			child* addtree2 = (child*)malloc(sizeof(child));
			strncpy(addtree1->simbols, temp, SIZE);
			strncpy(addtree2->simbols, temp, SIZE);
			strncpy(addtree1->simbols, temp1, SIZE);
			strncpy(addtree2->simbols, temp3, SIZE);
			addtree1->left = currroot->left;
			addtree1->right = currroot->right;
			addtree2->left = nextroot->left;
			addtree2->right = nextroot->right;
			currroot->left = addtree1;
			currroot->right = addtree2;
		}
		else
		{
			char temp3[SIZE] = { 0 };
			strcpy(temp3, nextroot->simbols);
			child* addtree1 = (child*)malloc(sizeof(child));
			child* addtree2 = (child*)malloc(sizeof(child));
			strncpy(addtree1->simbols, temp, SIZE);
			strncpy(addtree2->simbols, temp, SIZE);
			strncpy(addtree1->simbols, temp1, SIZE);
			strncpy(addtree2->simbols, temp3, SIZE);
			addtree1->left = currroot->left;
			addtree1->right = currroot->right;
			addtree2->left = nextroot->left;
			addtree2->right = nextroot->right;
			currroot->left = addtree1;
			currroot->right = addtree2;
		}
	}
	else
	{
		char temp1[SIZE] = { 0 };
		char temp[SIZE] = { 0 };
		strcpy(temp1, currroot->simbols);
		if (nextroot->left)
		{
			char temp3[SIZE] = { 0 };
			char temp4[SIZE / 2] = { 0 };
			strcpy(temp3, nextroot->left->simbols);
			strcpy(temp4, nextroot->right->simbols);
			sprintf(temp3, "%s%s", temp3, temp4);
			child* addtree1 = (child*)malloc(sizeof(child));
			child* addtree2 = (child*)malloc(sizeof(child));
			strncpy(addtree1->simbols, temp, SIZE);
			strncpy(addtree2->simbols, temp, SIZE);
			strncpy(addtree1->simbols, temp1, SIZE);
			strncpy(addtree2->simbols, temp3, SIZE);
			addtree1->left = currroot->left;
			addtree1->right = currroot->right;
			addtree2->left = nextroot->left;
			addtree2->right = nextroot->right;
			currroot->left = addtree1;
			currroot->right = addtree2;
		}
		else
		{
			char temp3[SIZE] = { 0 };
			strcpy(temp3, nextroot->simbols);
			child* addtree1 = (child*)malloc(sizeof(child));
			child* addtree2 = (child*)malloc(sizeof(child));
			strncpy(addtree1->simbols, temp, SIZE);
			strncpy(addtree2->simbols, temp, SIZE);
			strncpy(addtree1->simbols, temp1, SIZE);
			strncpy(addtree2->simbols, temp3, SIZE);
			addtree1->left = currroot->left;
			addtree1->right = currroot->right;
			addtree2->left = nextroot->left;
			addtree2->right = nextroot->right;
			currroot->left = addtree1;
			currroot->right = addtree2;
		}
	}
	return currroot;
}

queue* pop(queue* root)                                                                                               //Main function
{
	while (root->next)
	{
		char temp1[SIZE] = { 0 };
		char temp2[SIZE / 2] = { 0 };
		strcpy(temp1, root->simbols);
		strcpy(temp2, root->next->simbols);
		if ((!root->left) && (!root->next->left))
		{
			create_child(&root);
			strcpy(root->left->simbols, temp1);
			strcpy(root->right->simbols, temp2);
		}
		else
		{
			root = create_child_for_child(root, root->next);
		}
		sprintf(temp1, "%s%s", temp1, temp2);
		strcpy(root->simbols, temp1);
		root->count = root->count + root->next->count;
		root->next = delete(&root->next);
		if (root->next)
		{
			root = sort(root);
		}
		int i = 0;
	}
	return root;
}

void code(child* tree, char simbols[SIZE], char currcode[SIZE][SIZE], unsigned short int k, unsigned short int* q, unsigned short int i, unsigned short int codiki[SIZE])                       //Function that encodes characters by tree
{
	if (tree->left)
	{
		char temp[SIZE] = { 0 };
		strcpy(temp, currcode[(*q)]);
		currcode[(*q)][i] = '0';
		i++;
		code(tree->left, simbols, currcode, k, q, i, codiki);
		(*q)++;
		i--;
		strcpy(currcode[(*q)], temp);
		currcode[(*q)][i] = '1';
		i++;
		code(tree->right, simbols, currcode, k, q, i, codiki);
		(*q)++;
	}
	else
	{
		unsigned short int len = strlen(simbols);
		for (int j = 0; j <= len; j++)
		{
			if (tree->simbols[0] == simbols[j])
			{
				codiki[j] = *q;
				j = len + 1;
			}
		}
	}
}