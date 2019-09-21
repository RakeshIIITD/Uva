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

int  a[] = {500,1000,2000} ;
//int pay ;
int L[100000] ={0} ;
int L2[10001]  ;
int C2(int W)  // correction to be done
{
	if(W==0)  return 0 ;
	//if(W<0)  return 99999 ;
	if(L2[W]!=9999)  return L2[W] ; 
	for(int i=0;i<3;i++)
	{
		L2[W] = min(L2[W],1+C2(W-a[i])) ;
	}
	return L2[W] ;
}
int C(int W)
{
	if(W==0)   return 1 ;
	if(W<0)    return 0 ;
	if(L[W]!=0)    return L[W] ;
	for(int i=0;i<3;i++)
	{
		L[W] = L[W]||C(W-a[i]) ;
	}
	return L[W] ;
}
int main()
{
	int pay = 1400 ;
	int i ;

memset(L2,9999,sizeof(L2)) ;
		for(i=pay;C(i)!=1;i++)
		{
		//	memset(L,0,sizeof L);
		}
		cout<<i<<" "<<C2(i) ;  
	return 0 ;
}

