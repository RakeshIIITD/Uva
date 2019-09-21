/*Code Awesome*/
#include<stdio.h>

int reverse(int num )
{
   int rev =0;
   while(num!=0)
   {
   	rev = rev*10 ;
   	rev = rev + num%10 ;
   	num = num/10 ;
   }
   return rev ;
}

int main()
{
	int testcase ;
	scanf("%d",&testcase) ;
	while(testcase--)
	{
		int num1 , num2 ;
		scanf("%d%d",&num1 , &num2 ) ;
		printf("%d\n" , reverse( reverse(num1) + reverse(num2)) ) ;
	}
}
