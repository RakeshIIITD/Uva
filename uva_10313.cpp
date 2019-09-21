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
int a[] = {1,2,3,4} ;
int L[1000][100];
int C(int W , int j)
{
	if(L[W][j]!=0)   return L[W][j] ;
	
	for(int i=0;i<4;i++)
	{
		L[W][j]+=C(W-a[i],j+1) ;
	}
	return L[W][j] ;
}
int main()
{
	for(int i=0;i<1001;i++)
	{
		for(int j = 0 ;j<100 ; j++)
		{
			if(i==0&&j==1)  L[i][j] = 1 ;
			else L[i][j] = 0 ;		}
	}
	cout<<C(11,0) ;
	return 0 ;
}

