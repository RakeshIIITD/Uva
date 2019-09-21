#include<stdio.h>   //calculation power with log(n) algorithm 
int main()
{int n,t,temp;
int a;
n=6;
a=2;
t=n%2;
if(t)
{n=n-1;
temp=a;
}
while(n>1)
 {n=n/2;
 a=a*a;
 }
 if(t)
 printf("Expo : %ld",a*temp);
 else
 printf("Expo : %ld",a);
 return 0;
}
