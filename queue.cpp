/*---------------QUEUE--------------------------------------*/
#include<stdio.h>
#include<conio.h>
int main()
{
int q[5],ch,n,rear,front;
front=rear=-1;
while(1){
printf("enter the choice\n");
 printf("1.Insert\n2.Delete\n3.display\n4.exit\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:  //-------insertion---------------
 if(rear==4)
 printf("Queue is full\n");
 else
 printf("enter the element\n");
 scanf("%d",&n);
 rear++;
 q[rear]=n;
           break;
 case 2: //--------deletion-----------
         if(front==-1)
        printf("queue is empty\n");
        else
        if(front==rear)
        front=rear=-1;
        else
        front++;
         break;
case 3: //-------display--------------
        for(int i=front;i<=rear;i++)
        printf("%d\n",q[i]);
        break;
case 4: return 0;
        break;
default:printf("\nWrong Choice");
                        }
                        }                             
getch();
return 0;
}
