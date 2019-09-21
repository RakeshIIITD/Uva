/*Code Awesome*/
#include<iostream>
#include<string>
#include<cstdio.h>

using namespace  std ;

int Hash(char key[])
{
	return h(key)%101 ;
}

int h(char key[])
{
	int i ;
	int sum = 0 ;
	for(i=1 ; i<=strlen(key) ; i++ )
		sum = sum + key[i-1]*i ;
	
	return sum ;
}
int main()
{
	int testcase  ;
	
	scanf("%d",&testcase) ;
	while(testcase--)
	{
		
	}
	return 0 ;
}
