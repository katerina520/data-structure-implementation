#include <stdio.h>
#include <stdlib.h>


typedef int Data;
struct Node {
	struct Node * next;
	struct Node * prev;
	Data data;
};

void list_init(struct Node * list);

void list_insert(struct Node * list, struct Node * t);
void list_insert_before(struct Node * list, struct Node * t);
void list_remove(struct Node * t);

struct Node * list_push_front(struct Node * list, Data d);
struct Node * list_push_back(struct Node * list, Data d);

Data list_pop_front(struct Node * list);
Data list_pop_back(struct Node * list);
Data list_delete(struct Node * t);

void list_print (struct Node * list);
int list_is_empty(struct Node * list);

void list_clear(struct Node * list);

int main ()
{
	int i;
	struct Node x[10];
	struct Node * a = malloc(sizeof(struct Node));
	struct Node * b = malloc(sizeof(struct Node));

	list_init(a);
	list_init(b);
	// End of test 1

	for(i=0; i<10; i++) {
		x[i].data = i;
		list_insert(a, &x[i]);
	}
	list_print(a);
	// 9 .. 0
	// End of test 2

	list_remove(&x[5]);
	list_print(a);
	// 9 8 7 6 4 3 2 1 0
	list_remove(&x[0]);
	list_print(a);
	// 9 8 7 6 4 3 2 1
	list_remove(&x[9]);
	list_print(a);
	// 8 7 6 4 3 2 1
	// End of test 3
    //

	list_insert_before(a, &x[0]);
	list_print(a);
	list_insert(a, &x[9]);
	list_print(a);
	list_insert(&x[6], &x[5]);
	list_print(a);
	// End of test 4

	while(!list_is_empty(a))
		list_remove(a->next);
	// End of test 5

	for(i=0; i<10; i++)
		list_push_back(a, i);
	list_print(a);
	// End of test 6
	/*
	for(i=0; i<10; i++)
		list_push_front(b, list_pop_back(a));
	list_print(b);
	// End of test 7

	for(i=0; i<10; i++) {
		list_push_front(a, i);
		list_pop_front(b);
	}
	list_print(a);
	// End of test 8

	for(i=0; i<10; i++)
		list_push_back(b, list_pop_front(a));
	list_print(b);
	// End of test 9
*/
	list_clear(a);
	list_clear(b);
	// End of test 10

	free(a);
	free(b);

	return 0;
}

void list_init(struct Node * list)
{
	list -> next = list;
	list -> prev = list;
}
void list_print (struct Node * list)
{
	struct Node * t;
	for (t = list -> next; t != list; t = t -> next)
		printf("%d ", t -> data);
	printf("\n");
}

void list_insert(struct Node * list, struct Node * t)
{
	t -> prev = list;
	t -> next = list -> next;
	list -> next -> prev = t;
	list -> next = t;

}

void list_remove(struct Node * t)
{
	t -> prev -> next = t -> next;
	t -> next -> prev = t -> prev;

}

void list_insert_before(struct Node * list, struct Node * t)
{
	t -> next = list;
	t -> prev = list -> prev;
	list -> prev -> next = t;
	list -> prev = t;

}

int list_is_empty(struct Node * list)
{
	return list -> next == list;
}

struct Node * list_push_back(struct Node * list, Data d)
{
	struct Node * new = malloc(sizeof(struct Node));
	new -> data = d;
	list_insert(list, new);
	return list;


}

struct Node * list_push_front(struct Node * list, Data d)
{
	struct Node * new = malloc(sizeof(struct Node));
	new -> data = d;
	list_insert_before(list, new);
	return list;
}

Data list_pop_front(struct Node * list)
{
	return 0;
}
Data list_pop_back(struct Node * list)
{
	return 0;
}
Data list_delete(struct Node * t)
{
	Data x = t->data;
	list_remove(t);
	free(t);
	return x;
}

void list_clear(struct Node * list)
{
	while (!list_is_empty(list))
		list_delete(list->next);
}
