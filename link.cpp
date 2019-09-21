#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
node *head=NULL;
node *z,*t;
void insbeg(int n)
  {
	t=(node *)malloc(sizeof(node));
	t->data=n;
	if(head==NULL)
	{
		t->next=NULL;
		head=t;
	}
	else{
	
	t->next=head;
	head=t; }
  }
void insbet(int n,int p)
{	int i;
    t=(node *)malloc(sizeof(node));
    t->data=n;
    z=head;
    for(i=0;i<p;i++)
    {
	 z=z->next;
    }
    z->next=t;    // 
    t->next=z->next;    //
	} 
void insend(int n){
	t=(node*)malloc(sizeof(node));
	t->next=NULL;
	while(z!=NULL)
	{z=z->next;
	}
	z->next=t;
}	
void Delete()
   {
   z=head;
   while(z->next->next!=NULL)
   {z=z->next;
   }
   t=z->next->next;
   z->next=NULL;
   free(t);
   }
   void display()
   {z=head;
   while(z!=NULL)
   {printf("\n%d",z->data);
   z=z->next;
   }
   }
int main()
{
	int n,ch,p;
	while(1){
	printf("Enter your choice :\n1.Insbeg\n2.insbet\n3.insend\n4.delete\n5.display\n6.Exit\n  :");
	scanf("%d",&ch);
	switch(ch)
	{  case 1:printf("\nEnter the element in BEGINING : ");
	          scanf("%d",&n);
	          insbeg(n);
	          break;
	   case 2:printf("\nEnter the Element and Position :");
	          scanf("%d\n%d",&n,&p);
		      insbet(n,p);
		      break;
	   case 3:printf("Enter the Element in END :\n");
	          scanf("%d",&n);
	          insend(n);
	          break;
	   case 4:printf("\nElement Deleted !!");
	          Delete();
	          break;
	   case 5:display();
	          break;
	   case 6:return 0;
	   default:printf("\nWRONG CHOICE!!");
	}
}
}
