#include <stdio.h>
#include <stdlib.h>
// Kevin Frazier

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int i = 0;
	
	node* walker = head;

	
	while( head!= NULL && walker->next != NULL) 
	{
		
		walker = walker->next;
		i++;

	}

	return i;
	
	
		
			


	
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int length1 = length(head);
	char* str = (char*)malloc(sizeof(char)*length1+1);
	int i = 0;
	node *temp = head;

	while (temp != NULL){
		str[i++] = temp ->letter;
		 temp = temp->next;
	}
		str[i] = '\0';
	
	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	struct node* temp = (node*) malloc(sizeof(node));
	temp->next = NULL;
	temp->letter = c;

 if(*pHead == NULL){
	*pHead = temp;
	return;
 }
	node* walker = *pHead;
	while (walker->next != NULL){
		walker = walker->next;
	}
		walker->next = temp;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	
	node* tmp = *pHead;
    while (tmp != NULL) {
        *pHead = tmp->next;
        free(tmp);
        tmp = *pHead;
    }
    *pHead = NULL;

	
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}

