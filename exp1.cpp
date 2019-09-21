	 #include<stdio.h>
#include<conio.h>
int main()
{
	 int a,*c,*p;
	 a=8;
	 p=&a;
	 p=p+1;
	 *p=88;
	 c=p;
	 printf("%d",c);
    getch();
    return 0;
}
