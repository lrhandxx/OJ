#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Node {
	int status;
	struct Node* A;
	struct Node* G;
	struct Node* C;
	struct Node* T;
};
typedef struct Node* pNode;
typedef pNode Tree;
Tree MakeEmpty()
{
	Tree t = malloc(sizeof(struct Node));
	t->status = 0;
	t->A = NULL;
	t->C = NULL;
	t->G = NULL;
	t->T = NULL;

	return t;
}
pNode Insert(char* str, Tree t)
{
	int l=0;
	while (str[l] != '\0')
	{
		if (str[l] == 'A')
		{
			if (t->A == NULL)
			{
				t->A = MakeEmpty();
			}
			t = t->A;
		}
		else if (str[l] == 'C')
		{
			if (t->C == NULL)
			{
				t->C = MakeEmpty();
			}
			t = t->C;
		}
		else if (str[l] == 'T')
		{
			if (t->T == NULL)
			{
				t->T = MakeEmpty();
			}
			t = t->T;
		}
		else if (str[l] == 'G')
		{
			if (t->G == NULL)
			{
				t->G = MakeEmpty();
			}
			t = t->G;
		}

		if (str[l + 1] == '\0')
		{
			t->status = 1;
			break;
		}
		else l++;
	}
	return t;
}
int Find(char* str, Tree t)
{
	int l=0;
	while (str[l] != '\0')
	{
		if (str[l] == 'A')
		{
			t = t->A;
		}
		else if (str[l] == 'G')
		{
			t = t->G;
		}
		else if (str[l] == 'C')
		{
			t = t->C;
		}
		else if (str[l] == 'T')
		{
			t = t->T;
		}
		if (t == NULL) return 0;
		l++;
	}
	return t->status;
}

int main(void)
{
	int n;
	int i;
	char command[10],str[20];
	while (scanf("%d", &n) != EOF)
	{
		Tree t = MakeEmpty();

		for (i = 0; i < n; i++)
		{
			scanf("%s", command);
			scanf("%s", str);
			if (strcmp(command, "insert")==0)
			{
				Insert(str, t);
			}
			else if (strcmp(command, "find")==0)
			{
				if (Find(str, t) == 1) puts("yes");
				else puts("no");
			}
		}
	}
	
	return 0;
}