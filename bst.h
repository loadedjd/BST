struct Node {
	struct Node *left;
	struct Node *right;
	void *data;
	int position;

}


typedef int (*ComparisonFunction) (void *data1, void *data2);



int insert (struct Node **root, void *data, ComparisonFunction compare) {


	struct Node *currentNode;
	struct Node *lastNode;

	if (!root) {
		*head = allocateNewNode(data, 0);
		return 0;
			
	} else {
		currentNode = *head;
		
		while (currentNode) {
			int compareResult = compare(data, currentNode->data;
			
			if (comporeResult < 0 ) {  /* Less than, go to the left */
				lastNode = currentNode;
				currentNode = currentNode.left;
				continue;
			} else {
				lastNode = currentNode;
				currentNode = currentNode.right;
				continue;
			}
		}	


		if ( compare(data, lastNode->data) <0 ) {
			lastNode->left = allocateNewNode(data, (lastNode->position) + 1;
		} else {
			lastNode->right = allocateNewNode(data, (lastNode->position) + 2);
		}
	}
}


