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


int main(void)
{
	system("chcp 1251>nul");
	LOS* list = create(10);
	show(list);
	printf("\n");
	LOS str = {25, NULL};
	add(list, str, 5);
	show(list);
	delete(list);
	
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