#include<stdio.h>
#include<malloc.h>
struct node 
 { 
 	int data;
 	struct node *next ;
};

typedef struct node nd;
int main()
 {  nd *n1,*n2,*n3;
     n1 = (nd *)malloc(sizeof(nd));
     n2 = (nd *)malloc(sizeof(nd));
     n3 = (nd *)malloc(sizeof(nd));
     
     n1->data = 30;
     n2->data = 20;
     n3->data = 10;
     
     n1->next = n2;
     n2->next = n3;
     n3->next = NULL;
     
 	 nd *head = n1;
 	
 	printf("%d\n%d\n%d",head->data,head->next->data,head->next->next->data );
 //	nd *z =head ;
 //	while(z!=NULL)
 //	{
 //		printf("%d\n",z->data);
 //		z=z->next;
 //	}
 	return 0 ;
 }
