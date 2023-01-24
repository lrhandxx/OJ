#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define Million 1000000

struct Node
{
	int Num;
	struct Node* Last;
	struct Node* Next;
};
struct Head
{
	int Size;
	struct Node* First;
	struct Node* Last;
};
struct Node* New()
{
	struct Node* n = malloc(sizeof(struct Node));
	n->Last = NULL;
	n->Next = NULL;
	n->Num = 0;
	return n;
}
struct Head* Init()
{
	struct Head* h = malloc(sizeof(struct Head));
	h->First = NULL;
	h->Last = NULL;
	h->Size = 0;
	return h;
}
void StrToNum(char* str, struct Head* h)
{
	int l = strlen(str);
	int i;
	struct Node* n;
	while (l >= 6)
	{
		n = New();
		for (i = l - 6; i < l; i++)
		{
			n->Num = n->Num * 10 + (str[i] - '0');
		}
		if (h->Last == NULL)
		{
			h->First = h->Last = n;
			h->Size++;
		}
		else
		{
			n->Next = h->First;
			h->First->Last = n;
			h->First = n;
			h->Size++;
		}
		l -= 6;
	}
	if (l > 0)
	{
		n = New();
		for (i = 0; i < l; i++)
		{
			n->Num = n->Num * 10 + (str[i] - '0');
		}
		if (h->Last == NULL)
		{
			h->First = h->Last = n;
			h->Size++;
		}
		else
		{
			n->Next = h->First;
			h->First->Last = n;
			h->First = n;
			h->Size++;
		}
	}
}
void Check(struct Head* h)
{
	struct Node* n = h->Last, * tn;
	while (n != NULL)
	{
		if (n->Num >= Million)
		{
			if (n->Last != NULL)
			{
				n->Last->Num += n->Num / Million;
				n->Num %= Million;
			}
			else
			{
				tn = New();
				n->Last = tn;
				h->First = tn;
				h->Size++;
				tn->Next = n;
				n->Last += n->Num / Million;
				n->Num %= Million;

			}
		}
		n = n->Last;
	}
}
void Show(struct Head* h)
{
	struct Node* n = h->First;
	printf("%d", n->Num);
	n = n->Next;
	while (n != NULL)
	{
		printf("%06d", n->Num);
		n = n->Next;
	}
	puts("");
}
void Caculation(struct Head* h1, struct Head* h2)
{
	struct Head* th;
	struct Node* tn2, * tn1;
	if (h2->Size > h1->Size)
	{
		th = h1;
		h1 = h2;
		h2 = th;
	}
	tn1 = h1->Last;
	tn2 = h2->Last;
	while (tn2 != NULL)
	{
		tn1->Num += tn2->Num;
		tn1 = tn1->Last;
		tn2 = tn2->Last;
	}
	Check(h1);
	Show(h1);
}

void Del(struct Head* h)
{
	struct Node* n = h->First,*tn;
	while (n != NULL)
	{
		tn = n; 
		n = n->Next;
		free(tn);
	}
	free(h);
	h = NULL;
}
int main(void)
{
	char* str = malloc(sizeof(char) * 505);
	while (scanf("%s", str) != EOF)
	{
		struct Head* h1 = Init();
		struct Head* h2 = Init();
		StrToNum(str, h1);
		scanf("%s", str);
		StrToNum(str, h2);
		Caculation(h1, h2);
		Del(h1);
		Del(h2);
	}
	free(str);
	return 0;
}
