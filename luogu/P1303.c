#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>




#define Thousand 1000
#define First Next
#define Size Num

struct Node
{
	int Num;
	struct Node* Last;
	struct Node* Next;
};
typedef struct Node* pNode;
typedef pNode Head;

void Show(Head);


pNode New()
{
	pNode n = malloc(sizeof(struct Node));
	n->Last = NULL;
	n->Next = NULL;
	n->Num = 0;
	return n;
}
Head Init()
{
	Head h = malloc(sizeof(struct Node));
	h->First = NULL;
	h->Last = NULL;
	h->Size = 0;
	return h;
}
void StrToNum(char* str, Head h)
{
	int l = strlen(str);
	int i;
	pNode pn;
	while (l >= 3)
	{
		pn = New();
		for (i = l - 3; i < l; i++)
		{
			pn->Num = pn->Num * 10 + (str[i] - '0');
		}
		if (h->First == NULL)
		{
			h->First = h->Last = pn;
			h->Size++;
		}
		else
		{
			pn->Next = h->First;
			h->First->Last = pn;
			h->First = pn;
			h->Num++;
		}
		l -= 3;
	}
	if (l > 0)
	{
		pn = New();
		for (i = 0; i < l; i++)
		{
			pn->Num = pn->Num * 10 + (str[i] - '0');
		}
		if (h->First == NULL)
		{
			h->First = h->Last = pn;
			h->Size++;
		}
		else
		{
			pn->Next = h->First;
			h->First->Last = pn;
			h->First = pn;
			h->Size++;
		}
	}
//	printf("Get:");
//	Show(h);
}
void Check(Head h)
{
	pNode n = h->Last, tn;
	while (n != NULL)
	{
		if (n->Num >= Thousand)
		{
			if (n->Last != NULL)
			{
				n->Last->Num += n->Num / Thousand;
				n->Num %= Thousand;
			}
			else
			{
				tn = New();
				n->Last = tn;
				h->Last = tn;
				h->Num++;
				tn->Next = n;
				n->Last += n->Num / Thousand;
				n->Num %= Thousand;

			}
		}
		n = n->Last;
	}
}
void Show(Head h)
{
	pNode n = h->First;
	int f = 1;
	while (n != NULL)
	{
		if (f)
		{
			if (n->Num != 0||n->Next==NULL)
			{
				printf("%d", n->Num);
				f = 0;
			}
		}
		else printf("%03d", n->Num);
		n = n->Next;
	}
	puts("");
}
void Caculation(Head h1, Head h2)
{
	Head h = Init();
	pNode n,n1,n2,a,b;
	int i;
	for (i = 0; i < h1->Size + h2->Size; i++)
	{
		n = New();
		if (h->Size == 0)
		{
			h->First = h->Last = n;
			h->Size++;
		}
		else
		{
			h->Size++;
			h->Last->Next = n;
			n->Last = h->Last;
			h->Last = n;
		}
	}
	n2 = h2->Last;
	a = b = h->Last;
	while (n2 != NULL)
	{
		a = b;
		n1 = h1->Last;
		while (n1 != NULL)
		{
			a->Num += n1->Num * n2->Num;
			if (a->Num >= Thousand) 
			{
				a->Last->Num += a->Num / Thousand;
				a->Num %= Thousand;
			}
			n1 = n1->Last;
			a = a->Last;
		}
		n2 = n2->Last;
		b = b->Last;
	}
	Check(h);
	Show(h);
}
void Del(Head h)
{
	pNode n = h->Last, tn;
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
		Head h1 = Init();
		Head h2 = Init();
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
