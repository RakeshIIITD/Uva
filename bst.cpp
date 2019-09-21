#include<stdio.h>
#include<malloc.h>
struct node
{int data;
struct node *left;
struct node *right;
};
struct node *num=NULL;
struct node *bt=NULL;
void insert(struct node * , int);
void inorder(struct node *);
//int ar[]={20,17,6,8,10,7,18,13,12,5};
int main()
{int no,num,i;
i=0;
printf("Enter the number of elements : ");
scanf("%d ",&no);
printf("exec");
do{ printf("Enter the element :\n");
scanf("%d",&num);
insert(bt,num);
inorder(bt);
}while(no>i++);
return 0;
}
void insert(struct node *t,int num)
{if(t==NULL)
{t=(struct node *)malloc(sizeof(struct node));
t->left=NULL;
t->right=NULL;
t->data=num;
}
else
{if(num<t->data)
insert(t->left,num);
else
insert(t->right,num);
}
}
void inorder(struct node *root)
{if(root!=NULL)
{inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
}
