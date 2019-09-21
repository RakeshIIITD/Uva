#include<conio.h>
#include<stdio.h>
void main()
{clrscr();
int n,a,b,c,d,e;
printf("enter the no,");
scanf("%d",&n);
a=n%10;
n=n/10;
b=n%10;
n=n/10;
c=n%10;
n=n/10;
d=n%10;
n=n/10;
e=n%10;
printf("the desired no. is %d%d%d%d%d",e+1,d+1,c+1,b+1,a+1);
getch();
}


