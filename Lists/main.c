#include <stdio.h>
#include <malloc.h>

struct MyStruct
{
	int a;
	struct MyStruct* next;
};
typedef struct MyStruct LOS;

LOS* create(int);
void show(LOS*);
void delete(LOS*);
void add(LOS*, LOS, int);
void deleteItem(LOS*, int);
void changeItems(LOS*, int, int);


int main(void)
{
	system("chcp 1251>nul");
	LOS* list = create(10);
	show(list);
	printf("\n");
	LOS str = {25, NULL};
	add(list, str, 5);
	show(list);
	printf("\n");
	delete(list);
	list = create(10);
	show(list);
	printf("\n");
	deleteItem(list, 2);
	show(list);
	printf("\n");
	changeItems(list, 1, 2);
	show(list);
}

LOS* create(int n)
{
	LOS* first = malloc(sizeof(LOS));
	first->a = 1;
	first->next = NULL;

	LOS* l, * q;
	l = first;
	for (int i = 0; i < n - 1; i++)
	{
		q = malloc(sizeof(LOS));
		q->a = l->a + 1;
		l->next = q;
		l = q;
	}
	l->next = NULL;
	return first;
}

void show(LOS* list) 
{
	while (list)
	{
		printf("%d ", list->a);
		list = list->next;
	}
}

void delete(LOS* list)
{
	LOS* nextElem = list;
	while(nextElem)
	{
		nextElem = list->next;
		free(list);
		list = nextElem;
	}
}

void add(LOS* list, LOS item, int k)
{
	LOS* element = malloc(sizeof(LOS));
	element->a = item.a;
	for (int i = 0; i < k; i++)
	{
		list = list->next;
	}
	void* address = list->next;
	list->next = element;
	element->next = address;
}

void deleteItem(LOS* list, int k)
{
	LOS* element = list;
	for (int i = 0; i < k; i++)
	{
		list = list->next;
	}
	void* address = list->next;
	free(list);
	list = element;
	for (int i = 0; i < k-1; i++)
	{
		list = list->next;
	}
	list->next = address;
}

void changeItems(LOS* list, int a, int b)
{
	LOS* element = list;
	void* addressB = NULL;
	void* addressAfterB = NULL;
	void* addressA = NULL;
	void* addressAfterA = NULL;
	if (a > b)
	{
		int c = b;
		a = b;
		b = c;
	}
	if (a == 1 && b == 2)
	{
			addressA = list;
			addressB = list->next;
			list = list->next;
			addressAfterB = list->next;
			list = addressB;
			list->next = addressA;
			list = list->next;
			list->next = addressAfterB;
	}
	else
	{

		for (int i = 0; i < b; i++)
		{
			list = list->next;
			if (i == b - 2)
			{
				addressB = list->next;
			}
			if (i == b - 1)
			{
				addressAfterB = list->next;
			}
			if (i == a - 2)
			{
				addressA = list->next;
			}
			if (i == a - 1)
			{
				addressAfterA = list->next;
			}
		}
		list = element;
		for (int i = 0; i < b; i++)
		{
			list = list->next;
			if (i == a - 2)
			{
				list->next = addressB;
			}
			if (i == a - 1)
			{
				list->next = addressAfterA;
			}
			if (i == b - 2)
			{
				list->next = addressA;
			}
			if (i == b - 1)
			{
				list->next = addressAfterB;
			}

		}
	}
}