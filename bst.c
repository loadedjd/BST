#include "bst.h"
#include <stdlib.h>
#include <stdio.h>


static void incrementSizeOfAllParents(struct Node *child) {
	struct Node *currentNode = child;



	while (currentNode && currentNode->parent) {
		if (currentNode->parent) {
			int currentParentSize = currentNode->parent->size;
			currentNode->parent->size = currentParentSize + 1;
			currentNode = currentNode->parent;
		}
	}
}


static struct Node* allocateNewNode(void *data, int position, struct Node *parent){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	
	if (newNode) {
		newNode->data = data;
		newNode->position = position;
		newNode->size = 1;		
		newNode->parent = parent;

		incrementSizeOfAllParents(newNode);
			

		newNode->left = NULL;
		newNode->right = NULL;
	}

	return newNode;
}





int insert (struct Node **head, void *data, ComparisonFunction compare) {


	struct Node *currentNode;
	struct Node *lastNode;

	if (  !(*head)  ) {
		*head = allocateNewNode(data, 0, NULL);
		if (*head) {
			return 0;
		} else {
			return -1;
		}	
	} else {
		currentNode = *head;
		
		while (currentNode) {
			int compareResult = compare(data, currentNode->data);
			
			if (compareResult < 0 ) {  /* Less than, go to the left */
				lastNode = currentNode;
				currentNode = currentNode->left;
				continue;
			} else {
				lastNode = currentNode;
				currentNode = currentNode->right;
				continue;
			}
		}	


		if ( compare(data, lastNode->data) <0 ) {
			lastNode->left = allocateNewNode(data, (lastNode->position) + 1, lastNode);
		} else {
			lastNode->right = allocateNewNode(data, (lastNode->position) + 2, lastNode);
		}
	}
}





void* kthOrder( struct Node *head, int k ) {
	
	register int i = k;
	struct Node *currentNode = head;
	int difference = k;
	


	/* To Do: speicla conditions for head is null or too small */

	if (head && head->size >= k) {
		int leftSubTreeSize = head->left ? head->left->size : 0;
		int rightSubTreeSize = head->right ? head->right->size : 0;
		
		if ( k == leftSubTreeSize + 1 ) {
			return head->data;
		} else if ( k <= leftSubTreeSize ) {
			/* Coninue looking in the left subtree */
			currentNode = currentNode->left;	
		} else {
			/* Continue looking in the right subtreee */
			
			difference = k - leftSubTreeSize - 1;
			currentNode = head->right;
			
		}



		while (currentNode) {
			int leftSize = currentNode->left ? currentNode->left->size : 0;
			int rightSize = currentNode->right ? currentNode->right->size : 0;


			if ( difference == leftSize + 1 ) { /* We are at the kth smallest node */
				return currentNode->data;
			} else if ( difference > leftSize ) { /* Left tree is too small, subtract size of left sub tree from difference and traverse the right sub tree */
				difference = difference - leftSize - 1;
				currentNode = currentNode->right;
			} else {
				currentNode = currentNode->left;
			}
		}

	} else {
		return NULL;
	}

}
