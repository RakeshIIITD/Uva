// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<math.h>

using namespace std ;
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)

int main()
{
    char c;
    //cout<<pow(2,100) ;
    while(c = getchar())
    {
    	if(c==-1)   break ;
    	long long num = 0;
    	num = c-'0' ;
    	long long j = 2 ;
    	
    	while(c = getchar())
    	{
    		if(c=='#')  break ;
    		num  = (num + (c-'0')*j) ;
    		if(num>=131071)   num = num%131071 ;
    		j = (j<<1) ;
    	}
    	if(num==0)   printf("YES\n") ;
    	else printf("NO\n") ;
    }
	return 0 ;
}

