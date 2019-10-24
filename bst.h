struct Node {

	struct Node *left;
	struct Node *right;
	struct Node *parent;

	void *data;

	int position;
	int size;

};


typedef int  (*ComparisonFunction) (void *data1, void *data2);



int insert (struct Node **root, void *data, ComparisonFunction compare);

void*  statFor( struct Node *head, int k);





