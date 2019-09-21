//------tree implementation using arrays----------------
#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char data;
	struct node *left;
	struct node *right;
}node;
 node *buildtree(int);
 void inorder(node *);
 node *root=NULL;
char ar[]={'A','B','C','D','E','F','G','\0','\0','H'};
int lc[]={1,3,5,-1,9,-1,-1,-1,-1,-1};
int rc[]={2,4,6,-1,-1,-1,-1,-1,-1,-1};
int main()
{
root=buildtree(0);
printf("\n");
inorder(root);
return 0;
}
 node *buildtree(int index)
{ node *t=NULL;
if(index!=-1)
{t=(node*)malloc(sizeof( node));
t->left=buildtree(lc[index]);
t->data=ar[index];
printf("%c ",t->data);
t->right=buildtree(rc[index]);
}
return t;
}
//----unnecessary lines-------
void inorder(node *root)
{ if(root!=NULL)
{inorder(root->left);
printf("%c ",root->data);
inorder(root->right);
}
}
