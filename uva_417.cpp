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

using namespace std ;
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)
int pos = 1 ;
map<string,int> m ;

void C(string str , int n)
{
	if(str.size()==n)
	{
		m[str] = pos++ ;
		return;
	}
	char i ;
	if(str=="")  i = 'a' ;
	else i = str[str.size()-1]+1 ;
	for( ;i<='z' ; i++ )
	{
		C(str+i,n);
	}
}
int main()
{
	for(int i=1;i<6;i++)
	{
		C("",i) ;
	}
	string str ;
	while(getline(cin,str))
	{
		printf("%d\n",m[str]) ;
	}
	return 0 ;
}

