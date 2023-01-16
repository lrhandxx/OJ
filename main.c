#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


struct li {
	int a;
	int b;
	int s;
	struct li* Last;
	struct li* Next;

};
struct li* New(int a, int b)
{
	struct li* l = malloc(sizeof(struct li));
	l->a = a;
	l->b = b;
	l->s = b - a;
	l->Next = NULL;
	l->Last = NULL;
	return l;
}
struct li* Final(struct li* Head)
{
	while (Head->Next != NULL) Head = Head->Next;
	return Head;
};
void Del(struct li* Head)
{
	struct li* t;
	while (Head != NULL)
	{
		t = Head;
		Head = Head->Next;
		free(t);
	}
}
int main(void)
{
	char* str = malloc(sizeof(char) * 20005);
	int* stack = malloc(sizeof(int) * 20005);
	int a, b;
	while (scanf("%s", str) != EOF)
	{
		struct li* Head = NULL,*fin,*tem;
		int k = 0;
		int top = 0;
		int l = 0;
		int tempS;
		int S = 0;
		while (str[l] != '\0')
		{
			if (str[l] == '\\')
			{
				stack[top++] = l;
			}
			else if (str[l] == '/' && top != 0)
			{
				a = stack[--top];
				b = l;
				tempS = b - a;
				S += tempS;
				if (Head == NULL)
				{
					Head = New(a, b);
					k++;
				}
				else
				{
					fin = Final(Head);
					while (fin!=NULL&&fin->a > a)
					{
						tempS += fin->s;
						fin = fin->Last;
						k--;
					}
					if (fin == NULL)
					{
						Head = New(a, b);
						Head->s = tempS;
						k++;
					}
					else
					{
						Del(fin->Next);
						tem = New(a, b);
						tem->s = tempS;
						fin->Next = tem;
						tem->Last = fin;
						k++;
					}
				}
			}
			l++;
		}
		printf("%d\n%d",S,k);
		tem = Head;
		while (tem != NULL)
		{
			printf(" %d", tem->s);
			tem = tem->Next;
		}
		puts("");
		Del(Head);
	}

	free(str);
	free(stack);
	return 0;
}
