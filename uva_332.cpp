// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<set>

using namespace std ;
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)

long gcd(long a ,long b){ return b==0?a:gcd(b,a%b) ; }

int str_to_num(char d[])
{
	int s = 0 ;
	
	for(int i=0;d[i];i++)
	{
		s = s*10 + d[i] -'0' ;
	} 
	return s ;
}

int main()
{
int j , t= 0;
double d , m ;
char str[10] ;
while(1)
{
	t++ ;
	scanf("%d %*d.%s",&j,str) ;
	int count = 0 ;
	if(j==-1)  break ;
	
	int n ;
	int temp = str_to_num(str) ;
	n = temp ;
	while(n)
	{
		n/=10 ;
		count++ ;
	}
	int num ,den ;
	num = temp-temp/(int)pow(10,j) ;
	den = (int)(pow(10,count) - pow(10,count - j));
	int g = gcd(num,den) ;
	printf("Case %d: %d/%d\n",t,num/g ,den/g ) ;	
}
	return 0 ;
}

