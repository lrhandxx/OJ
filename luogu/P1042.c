#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int abs(x)
{
	return x > 0 ? x : -x;
}

struct Node
{
	int W;
	int L;
	struct Node* Next;
};

struct Head {
	struct Node* Next;
	struct Node* Last;
};

struct Head* Init()
{
	struct Head* h = malloc(sizeof(struct Head));
	h->Last = NULL;
	h->Next = NULL;
	return h;
}
void Add(int W, int L, struct Head* h)
{
	struct Node* n = malloc(sizeof(struct Node));
	n->L = L;
	n->W = W;
	n->Next = NULL;
	if (h->Next == NULL)
	{
		h->Next = h->Last = n;
	}
	else
	{
		h->Last->Next = n;
		h->Last = n;
	}
}
int End11(int W, int L)
{

	if ((W >= 11 || L >= 11) && abs(W - L) >= 2) return 1;
	else return 0;
}
int End21(int W, int L)
{
	if ((W >= 21 || L >= 21) && abs(W - L) >= 2) return 1;
	else return 0;
}
void Show(struct Head* h)
{
	struct Node* n = h->Next;
	while (n != NULL)
	{
		printf("%d:%d\n", n->W, n->L);
		n = n->Next;
	}
}
void Del(struct Head* h)
{
	struct Node* n = h->Next, * tn;
	while (n != NULL)
	{
		tn = n;
		n = n->Next;
		free(tn);
	}
	free(h);
}
int main(void)
{
	char s[30];
	int W11 = 0, L11 = 0, W21 = 0, L21 = 0;
	struct Head* h11, * h21;
	h11 = Init();
	h21 = Init();
	int f = 1;

	while (scanf("%s", s) != EOF)
	{
		int l = 0;
		while (s[l] != '\0')
		{
			if (s[l] == 'W')
			{
				W11++; W21++;
				if (End11(W11, L11))
				{
					Add(W11, L11, h11);
					W11 = 0; L11 = 0;
				}
				if (End21(W21, L21))
				{
					Add(W21, L21, h21);
					W21 = 0; L21 = 0;
				}
			}
			else if (s[l] == 'L')
			{
				L11++; L21++;
				if (End11(W11, L11))
				{
					Add(W11, L11, h11);
					W11 = 0; L11 = 0;
				}
				if (End21(W21, L21))
				{
					Add(W21, L21, h21);
					W21 = 0; L21 = 0;
				}
			}
			else if (s[l] == 'E')
			{
				Add(W11, L11, h11);
				Add(W21, L21, h21);
				Show(h11);
				puts("");
				Show(h21);
				Del(h11);
				Del(h21);
				return 0;
			}
			l++;
		}
	}


	return 0;
}
