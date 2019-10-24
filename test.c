#include "bst.h"
#include <stdlib.h>




int compare( void *data1, void *data2) {
	int *a = (int*)data1;
	int *b = (int*)data2;

	return *a < *b ? -1 : 1;
}


int main() {
	

	struct Node *head = NULL;
	int newNumber = 10;
	void *dataPtr = (void*)&newNumber;

	insert(&head, dataPtr, compare);


	return 0;

}
