#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



#define Thousand 1000
#define TS 3


struct Node
{
	int Num;
	struct Node* Next;
	struct Node* Last;
};
struct Head
{
	int Size;
	int Sign;
	struct Node* First;
	struct Node* Last;
};

struct Node* New();
struct Head* Init();
struct Head* StrToNum(char*, struct Head*);
void Add(struct Head*, struct Head*);
void Sub(struct Head*, struct Head*);
void Mul(struct Head*, struct Head*);
void Show(struct Head*);
void Check(struct Head*);
void Copy(struct Head*, struct Head*);
void Del(struct Head*);


int main(void)
{
	int n;
	int i;
	while (scanf("%d", &n) != EOF)
	{
		struct Head** array = malloc(sizeof(struct Head*) * n);
		struct Head* sum = Init();
		sum->First = sum->Last = New();
		sum->Sign = 1;
		sum->Size = 1;
		sum->First->Num = 0;
		for (i = 0; i < n; i++)
		{
			array[i] = Init();
			array[i]->First = array[i]->Last = New();
			array[i]->Size = 1;
			array[i]->Sign = 1;
			array[i]->First->Num = i + 1;
			if (i != 0)
			{
				Mul(array[i], array[i - 1]);
			}
			Add(sum, array[i]);
		}
		Show(sum);
	}

	return 0;
}




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
	h->Sign = 0;
	h->Size = 0;
	return h;
}
struct Head* StrToNum(char* str, struct Head* h)
{
	struct Node* n;
	int l, i;
	if (h == NULL) h = Init();
	if (str[0] == '-')
	{
		h->Sign = -1;
		l = 0;
		while (str[l] != '\0')
		{
			str[l] = str[l + 1];
			l++;
		}
	}
	else
	{
		h->Sign = 1;
	}
	l = strlen(str);
	while (l >= TS)
	{
		n = New();
		for (i = l - TS; i < l; i++)
		{
			n->Num = n->Num * 10 + str[i] - '0';
		}
		if (h->Size == 0)
		{
			h->First = h->Last = n;
			h->Size++;
		}
		else
		{
			h->Size++;
			h->First->Last = n;
			n->Next = h->First;
			h->First = n;
		}
		l -= TS;
	}
	if (l > 0)
	{
		n = New();
		for (i = 0; i < l; i++)
		{
			n->Num = n->Num * 10 + str[i] - '0';
		}
		if (h->Size == 0)
		{
			h->First = h->Last = n;
			h->Size++;
		}
		else
		{
			h->Size++;
			h->First->Last = n;
			n->Next = h->First;
			h->First = n;
		}

	}

	Check(h);
	return h;
}
void Add(struct Head* h1, struct Head* h2)
{
	struct Head* th1, * th2, * th;
	struct Node* n1, * n2;
	th1 = Init();
	th2 = Init();
	Copy(h1, th1);
	Copy(h2, th2);
	if (h1->Sign == -1)
	{
		if (h2->Sign == -1)
		{
			th1->Sign = 1;
			th2->Sign = 1;
			Add(th1, th2);
			th1->Sign = -1;
			Del(h1);
			Copy(th1, h1);
		}
		else
		{
			th1->Sign = 1;
			Sub(th2, th1);
			Del(h1);
			Copy(th2, h1);
		}
	}
	else
	{
		if (h2->Sign == -1)
		{
			th2->Sign = 1;
			Sub(th1, th2);
			Del(h1);
			Copy(th1, h1);
		}
		else
		{
			if (th1->Size > th2->Size)
			{
				th = th1;
				th1 = th2;
				th2 = th;
			}
			n2 = New();
			th2->First->Last = n2;
			n2->Next = th2->First;
			th2->First = n2;
			th2->Size++;
			n1 = th1->Last;
			n2 = th2->Last;
			while (n1 != NULL)
			{
				n2->Num += n1->Num;
				if (n2->Num >= Thousand)
				{
					n2->Last->Num += n2->Num / Thousand;
					n2->Num %= Thousand;
				}
				n1 = n1->Last;
				n2 = n2->Last;
			}
			Check(th2);
			Del(h1);
			Copy(th2, h1);
		}
	}


	Del(th1);
	Del(th2);
	free(th1);
	free(th2);
}
void Sub(struct Head* h1, struct Head* h2)
{

}
void Mul(struct Head* h1, struct Head* h2)
{
	struct Head* h = Init();
	struct Node* n1, * n2, * n, * tn;
	int i;
	h->Size = i = h1->Size + h2->Size;
	while (i != 0)
	{
		n = New();
		if (h->First == NULL)
		{
			h->First = h->Last = n;
		}
		else
		{
			h->Last->Next = n;
			n->Last = h->Last;
			h->Last = n;
		}
		i--;
	}
	h->Sign = h1->Sign * h2->Sign;

	n2 = h2->Last;
	n = h->Last;
	while (n2 != NULL)
	{
		n1 = h1->Last;
		tn = n;
		while (n1 != NULL)
		{
			tn->Num += n1->Num * n2->Num;
			if (tn->Num >= Thousand)
			{
				tn->Last->Num += tn->Num / Thousand;
				tn->Num %= Thousand;
			}
			n1 = n1->Last;
			tn = tn->Last;
		}
		n2 = n2->Last;
		n = n->Last;
	}
	Check(h);
	Copy(h, h1);
	Del(h);
	free(h);

}
void Show(struct Head* h)
{
	struct Node* n;
	if (h->Sign == -1)
	{
		printf("-");
	}

	n = h->First;
	printf("%d", n->Num);
	n = n->Next;
	while (n != NULL)
	{
		printf("%03d", n->Num);//3==TS
		n = n->Next;
	}
	puts("");
}
void Check(struct Head* h)
{
	struct Node* n = h->Last, * tn;
	int i;
	while (n != NULL)
	{
		if (n->Num >= Thousand)
		{
			if (n->Last == NULL)
			{
				tn = New();
				tn->Next = n;
				n->Last = tn;
				h->First = tn;
				h->Size++;
			}
			n->Last->Num += n->Num / Thousand;
			n->Num %= Thousand;
		}
		n = n->Last;
	}
	n = h->First;
	while (n->Num == 0 && n->Next != NULL)
	{
		tn = n;
		n = n->Next;
		h->First = n;
		h->Size--;
		free(tn);
	}
	i = 0;
	n = h->First;
	while (n != NULL)
	{
		i++;
		n = n->Next;
	}
	h->Size = i;
}
void Copy(struct Head* source, struct Head* dest)
{
	struct Node* n, * tn;
	dest->Sign = source->Sign;
	dest->Size = source->Size;
	dest->First = dest->Last = NULL;
	n = source->First;
	while (n != NULL)
	{
		tn = New();
		tn->Num = n->Num;
		if (dest->First == NULL)
		{
			dest->First = dest->Last = tn;
		}
		else
		{
			dest->Last->Next = tn;
			tn->Last = dest->Last;
			dest->Last = tn;
		}
		n = n->Next;
	}

}
void Del(struct Head* h)
{
	struct Node* n = h->First, * tn;
	while (n != NULL)
	{
		tn = n;
		n = n->Next;
		free(tn);
	}
	h->Sign = 0;
	h->Size = 0;
	h->First = h->Last = NULL;
}