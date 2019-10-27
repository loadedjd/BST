#include <stdio.h>
#include "bst.h"
#include <stdlib.h>





int compareInts(void *data1, void *data2) {
	int *a = (int*)data1;
	int *b = (int*)data2;

	return *a < *b ? -1 : 1;
}




void readDataIntoBST(FILE *fp, struct Node **head) {

	int *readInValue = malloc(sizeof(int));
	

	if (readInValue) { 
		while (fscanf(fp, "%d", readInValue) > 0 && readInValue) {
			void *dataPtr = (void *)readInValue;
			insert(head, (void*)readInValue, compareInts);
			readInValue = malloc(sizeof(int));
		}
	}
}

void findAndPrintKthOrderStatisticFromFile(FILE *positionFile, struct Node *head) {

	int readInValue = 0;

	while(fscanf(positionFile, "%d", &readInValue) > 0) {
		void *stat = statFor(head, readInValue);
		int *intStat = (int*)stat;
		
		printf("The %d stat is %d", readInValue, *intStat);
		
	}
} 

void cleanUp(FILE *fp1, FILE *fp2) {
	fclose(fp1);
	fclose(fp2);
}


int main(int argc, char **argv) {

	char *dataX = argv[1];
	char *positionX = argv[2];
	struct Node *head = NULL;
	
	FILE *dataFile;
	FILE *positionFile;

	dataFile = fopen(dataX, "r");
	positionFile = fopen(positionX, "r");

	if (dataFile && positionFile) {
		readDataIntoBST(dataFile, &head);
		findAndPrintKthOrderStatisticFromFile(positionFile, head);
	}

	cleanUp(dataFile, positionFile);

	return 0;	
		
}

