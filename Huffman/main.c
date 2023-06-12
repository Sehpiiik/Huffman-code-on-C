#include "header.h"

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		printf("Enter the name of file");
		return -1;
	}
	FILE* f = fopen(argv[1], "r");
	if (!f) 
	{
		printf("Can`t open the file!");
		return -1;
	}
	queue* root = NULL;
	char s[SIZE] = { 0 };
	fgets(s, SIZE, f);
	fclose(f);
	unsigned short int count[SIZE] = { 0 };
	unsigned short int k = 0;
	unsigned short int len = strlen(s);
	char simbols[SIZE] = { 0 };
	cntsimb(count, simbols, s, &k);
	for (unsigned short int i = 0; i <= k; i++) 
	{
		root = push(root, count[i], simbols[i]);
	}
	root=pop(root);
	unsigned short int q = 0;
	char currcode[SIZE][SIZE] = { {0} };
	unsigned short int codiki[SIZE] = { 0 };
	currcode[0][0] = '0';
	code(root->left, simbols, currcode, 0, &q, 1, codiki);
	currcode[q][0] = '1';
	code(root->right, simbols, currcode, q, &q, 1, codiki);
	char result[SIZE*10] = { 0 };
	char rescode[SIZE*10] = { 0 };
	char temp[SIZE*10] = { 0 };
	for (unsigned short int i = 0; i <= len; i++)
	{
		for (unsigned short int j = 0; j <= k; j++) 
		{
			if (s[i] == simbols[j]) 
			{
				sprintf(result, "%s%s", result, currcode[codiki[j]]);
				j = k + 1;
			}
		}
	}
	simbols[k] = 126;
	for (unsigned short int i = 0; i <= k; i++)
	{
		sprintf(temp, "%c%s%s%s", simbols[i]," is ", currcode[codiki[i]]," \n");
		sprintf(rescode, "%s%s", rescode, temp);
	}
	simbols[k] = 0;
	sprintf(rescode, "%s%s", rescode, "Where ~ is the end of line character");
	FILE* res = fopen("output.txt", "w");
	fputs(result, res);
	fclose(res);
	FILE* c = fopen("codes.txt", "w");
	fputs(rescode, c);
	fclose(c);
	printf("Encoding completed successfully!");
	return 0;
}
