#include<stdio.h>
#include<conio.h>
int main()
{
	int b,*d;
	 b=22;
	 d=&b;
	 d=d+1;
	 printf("%d",*d);
	 getch();
    return 0;
}

