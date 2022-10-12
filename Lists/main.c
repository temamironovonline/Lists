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
LOS* changeItems(LOS*, int, int);


int main(void)
{
	system("chcp 1251>nul");
	LOS* list = create(10);
	show(list);
	
	LOS str = {25, NULL};
	add(list, str, 5);
	show(list);
	
	deleteItem(list, 2);
	show(list);
	
	delete(list);
	printf("\n");

	list = create(10);
	show(list);
	
	list = changeItems(list, 3, 4);
	show(list);
}

LOS* create(int n)
{
	printf("Создание: ");
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
	printf("\n");
}

void delete(LOS* list)
{
	printf("Удаление ЛОС: ---");
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
	printf("Добавление: ");
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
	printf("Удаление элемента: ");
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

LOS* changeItems(LOS* list, int a, int b)
{
	printf("Смена элементов местами: ");
	LOS* element = list;
	void* addressB = NULL;
	void* addressAfterB = NULL;
	void* addressA = NULL;
	void* addressAfterA = NULL;
	if (a > b)
	{
		int c = a;
		a = b;
		b = c;
	}
	
	if (a == 1 && b == 2)
	{
		//LOS* forFirstElement = list->next;
		addressA = list;
		addressB = list->next;
		addressAfterB = list->next->next;
		list = addressB;
		list->next = addressA;
		list->next->next = addressAfterB;
		list = addressB;

	}

	else if (a == 1)
	{
		a -= 1;
		b -= 1;
		addressA = list;
		addressAfterA = list->next;
		for (int i = 0; i < b; i++)
		{
			list = list->next;
			if (i == b - 1) 
			{
				addressB = list;
				addressAfterB = list->next;
			}

		}
		list = element;
		list = addressB;
		list->next = addressAfterA;
		for (int i = 0; i < b; i++)
		{
			list = list->next;
			if (i == b - 2)
			{
				list->next = addressA;
				list->next->next = addressAfterB;
			}
		}
		list = addressB;

	}
	else if (a == 2) 
	{
		if (b - a == 1)
		{
			addressA = list->next;
			addressB = list->next->next;
			addressAfterB = list->next->next->next;
			list->next = addressB;
			list->next->next = addressA;
			list->next->next->next = addressAfterB;

		}
		else
		{
			addressA = list->next;
			addressAfterA = list->next->next;
			for (int i = 0; i < b; i++)
			{
				list = list->next;
				if (i == b - 2)
				{
					addressB = list;
					addressAfterB = list->next;
				}
			}
			list = element;
			list->next = addressB;
			list->next->next = addressAfterA;
			for (int i = 0; i < b; i++)
			{
				list = list->next;
				if (i == b - 3)
				{
					list->next = addressA;
					list->next->next = addressAfterB;
				}

			}
			list = element;
		}
	}
	else
	{
		a -= 1;
		b -= 1;
		if (b - a == 1)
		{
			for (int i = 0; i < b; i++)
			{
				list = list->next;
				if (i == a-1)
				{
					addressA = list;
					addressB = list->next;
					addressAfterB = list->next->next;
				}
			}
			list = element;
			for (int i = 0; i < b; i++)
			{
				list = list->next;
				if (i == a-2)
				{
					list->next = addressB;
					list->next->next = addressA;
					list->next->next->next = addressAfterB;
				}
			}
			list = element;
		}
		else
		{
			for (int i = 0; i < b; i++)
			{
				list = list->next;

				if (i == a - 1)
				{
					addressA = list;
					addressAfterA = list->next;
				}
				else if (i == b - 1)
				{
					addressB = list;
					addressAfterB = list->next;
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
			list = element;
		}
	}
		
	return list;
}