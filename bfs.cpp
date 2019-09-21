#include <stdio.h>
#include <malloc.h>
#define NODE 4

int Queue[NODE]={0} , visited[NODE] = {0} ;
int front = -1 , rear = -1 ;

typedef struct node
{
  int data ;
  struct node *next ;
}node;

 typedef struct list
 { int data;
  node *next;
 }list;

 void enqueue(int n)
 {     front++ ;
 	   Queue[front] = n;
 	   
 }
 
 void bfs(list *adj)
 { int u ;
   node *crawl = NULL;
   enqueue(0);
   printf("\nGraph traversal is : ");
   while( rear!=front )
   {  rear++ ;
  	u = Queue[rear];
  	
  	printf("%d\n", u ) ;
  	visited[u] = 2 ;
  	crawl = adj[u].next ;
  	while( crawl!=NULL )
  	 {
  	 	if( !(visited[crawl->data]) )
  	 	 { 
  	 	     enqueue(crawl->data ) ;
			 visited[crawl->data] = 1 ;
  	 	 }
  	 	 crawl = crawl->next ; 
  	 }
  }
  
 }

 int main()
 { 
  int i,j,v[NODE][NODE];
  list adj[NODE];
  for(i = 0 ; i < NODE ; i++ )
   for(j = 0 ; j< NODE ; j++ )
     {   if(i!=j)
	     {
	      printf("\n enter for ( %d , %d ) : ",i,j );
          scanf("%d",&v[i][j]) ;
         }
     }
  for(i = 0 ; i < NODE ; i++ )
   { 
    node *t = NULL ;
    node *head = NULL;
    
    for(j = 0 ; j< NODE ; j++ )
     { if((v[i][j]==1)&&i!=j) 
       { if(t==NULL)
         { t = (node *)malloc(sizeof(node)) ;
           head = t ; 
         }
        else
         {
	      t->next = (node *)malloc(sizeof(node)) ;
	      t=t->next;
         }
          t->data = j ;
          t->next = NULL ;
       } 
     }
    adj[i].next = head ;
    adj[i].data = i ;
   }
   
  bfs(adj);
  return 0;
}
