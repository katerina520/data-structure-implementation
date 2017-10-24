#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define max(a,b) ((a) > (b) ? (a) : (b))

typedef int Data;
struct Node {
    Data val;            // data in a node
    struct Node * left;  // left child
    struct Node * right;
};

struct List {
	struct List * next;
	struct List * prev;
	struct Node * val;
	
};


void tree_print (struct Node * p);
struct Node * tree_add (struct Node * p, Data x);
void tree_destroy (struct Node * tree);
int depth (struct Node * tree);
void leaves(struct Node * tree);
int balanced(struct Node * tree);
void level(struct Node * tree, int n);
void bfs (struct Node * tree);

void list_init(struct List * list);

void list_insert(struct List * list, struct List * t);
void list_insert_before(struct List * list, struct List * t);
void list_remove(struct List * t);

struct List * list_push_front(struct List * list, struct Node * d);
struct List * list_push_back(struct List * list, struct Node * d);

struct Node * list_pop_front(struct List * list);
struct Node * list_pop_back(struct List * list);
struct Node * list_delete(struct List * t);

void list_print (struct List * list);
int list_is_empty(struct List * list);

void list_clear(struct List * list);



int main()
{
	int x = 1;
	struct Node * tree=NULL;
	while (1)
	{
		scanf("%d", &x);
		if (x == 0)
			break;
		tree = tree_add(tree, x);
	}
	bfs(tree);
	tree_destroy(tree);
	return(0);
}


void tree_print (struct Node * p)
{
    if (p != NULL ) {
        tree_print (p->left);
        printf ("%d ", p->val);
        tree_print (p->right);
    }
}

struct Node * tree_add (struct Node * p, Data x) {
    if (p == NULL ) {
        p = malloc (sizeof(struct Node));
        p->val = x;
     p->left = p->right = NULL;
    } else if (x < p->val) 
        p->left = tree_add (p->left, x);
    else if (x > p->val) 
        p->right = tree_add (p->right, x);
    return p;
}

void tree_destroy (struct Node * p)
{
		if(p==NULL)
			return;

        tree_destroy (p->left);
        tree_destroy (p->right);
        free(p);
}

int depth (struct Node * tree)
{
	int h1=0, h2=0;
	if (tree == NULL) return 0;
	else {
	if (tree->left)
		h1 = depth(tree->left);
	if (tree->right)
		h2 = depth(tree->right);
	return (1+max(h1,h2)); }
}


void leaves(struct Node * tree)
{
	if (tree)
	{
		leaves(tree->left);
		if (!tree->left && !tree->right)
			printf("%d ", tree->val);
		leaves(tree->right);
	}
}

int balanced(struct Node * tree)
{
	if (tree == NULL) 
		return 1;
	if (abs(depth(tree->left)-depth(tree->right))<2 && (balanced(tree->left)) && (balanced(tree->right)))
		return 1;
	return 0;
}

void level(struct Node * tree, int n)
{
	if (tree == NULL)
		return;
	if (n >= 0)
	{
		level(tree->left, n - 1);
		if (n == 0)
			printf("%d ", tree->val);
		level(tree->right, n - 1);
	}
}

void bfs (struct Node * tree)
{
	struct Node * t;
	struct List * a = malloc(sizeof(struct List));
	list_init(a);
	list_push_back(a, tree);
	while (!list_is_empty(a))
	{
		t = list_pop_front(a);
		printf("%d ", t -> val);
		if (t->left != NULL)
			list_push_back(a, t->left);
		if (t->right != NULL)
			list_push_back(a, t->right);
		t = (a->prev)->val;
	
	}
	list_clear(a);
	free(a);
}

void list_init(struct List * list)
{
	list -> next = list;
	list -> prev = list;
}


void list_insert(struct List * list, struct List * t)
{
	t -> prev = list;
	t -> next = list -> next;
	list -> next -> prev = t;
	list -> next = t;

}

void list_remove(struct List * t)
{
	t -> prev -> next = t -> next;
	t -> next -> prev = t -> prev;

}

void list_insert_before(struct List * list, struct List * t)
{
	t -> next = list;
	t -> prev = list -> prev;
	list -> prev -> next = t;
	list -> prev = t;

}

int list_is_empty(struct List * list)
{
	return list -> next == list;
}

struct List * list_push_back(struct List * list, struct Node * d)
{
	struct List * new = malloc(sizeof(struct List));
	new -> val = d;
	list_insert_before(list, new);
	return list;


}

struct List * list_push_front(struct List * list, struct Node * d)
{
	struct List * new = malloc(sizeof(struct List));
	new -> val = d;
	list_insert(list, new);
	return list;
}

struct Node * list_pop_front(struct List * list)
{
    struct Node * y = list_delete(list->next);
	return y;
}
struct Node * list_pop_back(struct List * list)
{
    struct Node * z = list_delete(list->prev);
	return z;
}
struct Node * list_delete(struct List * t)
{
	struct Node * x = t->val;
	list_remove(t);
	free(t);
	return x;
}

void list_clear(struct List * list)
{
	while (!list_is_empty(list))
		list_delete(list->next);
}
