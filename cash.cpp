#include<conio.h>
#include<stdio.h>
void main()
{clrscr();
int n,a,b,c;
printf("enter the no,");
scanf("%d",&n);
a=n/100;
b=(n-a*100)/50;
c=(n-(a*100+b*50))/10;
printf("100 NOTE=%d\n50 NOTE=%d\n10 NOTE=%d\n",a,b,c);
getch();
}


