// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

/* Structure for a linked list node */
struct Node {
	int data;
	struct Node* next;
};

/* A helper function to remove zeros from
the start of the linked list */
Node* removeLeadingZeros(struct Node* a)
{
	if (a != NULL && a->data == 0)
		return removeLeadingZeros(a->next);
	else
		return a;
}

/* A helper function to find the length of
linked list*/
int getSize(struct Node* a)
{
	int sz = 0;
	while (a != NULL) {
		a = a->next;
		sz++;
	}
	return sz;
}

/* Given a reference (pointer to pointer) to the
head of a list and an int, push a new node on the
front of the list. */
void push(struct Node** head_ref, int new_data)
{
	/* Allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* Set the data */
	new_node->data = new_data;

	/* Link the old list after the new node */
	new_node->next = (*head_ref);

	/* Set the head to point to the new node */
	(*head_ref) = new_node;
}

// Function to compare the numbers
// represented as linked lists
int compare(struct Node* a,
			struct Node* b)
{

	// Remover leading zeroes from
	// the linked lists
	a = removeLeadingZeros(a);
	b = removeLeadingZeros(b);

	int lenA = getSize(a);
	int lenB = getSize(b);

	if (lenA > lenB) {

		/* Since the number represented by a
		has a greater length, it will be greater*/
		return 1;
	}
	else if (lenB > lenA) {
		return -1;
	}

	/* If the lengths of two numbers are equal
		we have to check their magnitudes*/
	while (a != NULL && b != NULL) {
		if (a->data > b->data)
			return 1;
		else if (a->data < b->data)
			return -1;

		/* If we reach here, then a and b are
		not NULL and their data is same, so
		move to next nodes in both lists */
		a = a->next;
		b = b->next;
	}

	// If linked lists are identical, then
	// we need to return zero
	return 0;
}

// Driver code
int main()
{
	/* The constructed linked lists are :
	a: 5->6->7
	b: 2->3->3 */
	struct Node* a = NULL;
	push(&a, 7);
	push(&a, 6);
	push(&a, 5);

	struct Node* b = NULL;
	push(&b, 3);
	push(&b, 3);
	push(&b, 2);

	cout << compare(a, b);

	return 0;
}
