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

int a[] = {5,10,20,50,100,200} ;
int h[201] ;

int L[1000][201][10] ;

int C(int W,int j)
{
	if(W==0)   return 0 ;
	if(W<0)    return 9999 ;
	if(L[W][a[j]][h[j]]!=100000)   return L[W][a[j]][h[j]] ;
	
	for(int i=0;i<6;i++)
	{
		if(h[i])
		{
			h[i]--;
			L[W][a[i]][h[i]] = min(L[W][a[i]][h[i]], 1+C(W-a[i] ,i )) ;
			h[i]++ ;
		}
	}
	return L[W][a[j]][h[j]] ;
}

int main()
{		
		for(int i=0;i<200;i++)
		{
			for(int j=0;j<201;j++)
			{
				for(int k=0;k<201;k++)
				{
					L[i][j][k] = 100000 ;
				}
			}
		}
		h[5] = 2 ;
		h[10] = 4 ;
		h[20] = 2 ;
		h[50] = 0 ;
		h[100] = 1 ;
		h[200] = 0 ;
		
		int min = 100000 ;
		
		C(40,0) ;
		
			for(int j=0;j<201;j++)
			{
				for(int k=0;k<201;k++)
				{
					if(L[40][j][k]<min)  min = L[40][j][k] ;
				}
		}
		
		cout<<min ;
	return 0 ;
}

