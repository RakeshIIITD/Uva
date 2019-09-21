/*Code Awesome*/
#include<stdio.h>

long long fact(int n)
{  
    long long f =1 ;
	while(n)
	{
	  f = f* n ;
	  n-- ;	
	}
	return f ;
}
int main()
{
	
	int testcase ;
	scanf("%d",&testcase) ;
	while(testcase--)
	{
		int n ;
		scanf("%d",&n) ;
		printf("%lld\n" ,fact(n)) ;
	}
	return 0 ;
}
