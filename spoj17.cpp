/*Code Awesome*/
#include<stdio.h>

int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = a % b;

        a = b;
        b = temp;
    }
    return a;
}

int main()
{
	int testcase ;
	scanf("%d",&testcase ) ;
	while(testcase--)
	{
		long long a , b ;
		scanf("%lld%lld",&a ,&b ) ;
		long long div = gcd(a,b) ;
		printf("%lld %lld\n" , b/div ,a/div ) ;
	}
	return  0; 
}
