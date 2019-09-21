#include<stdio.h>
#include<conio.h>
int main()
{
int arr[5],ch,n,top;
top=-1;
while(1){
printf("enter the choice\n");
 printf("1.Insert\n2.Delete\n3.display\n4.exit\n");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:   if(!top)
           printf("\nStack is FULL!!!");
           else
           {printf("\nEnter the number");
           scanf("%d",&n);
           arr[top]=n;
           top++;
           }
           break;
 case 2: if(top==4)
         printf("\nStack is empty");
         else
         top--;
         break;
case 3: for(int i=top;i<5;i++)
        printf("%d\n",arr[i]);
        break;
case 4: return 0;
default:printf("\nWrong Choice");
 }                       }
}                        }                             
}
