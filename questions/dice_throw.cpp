#include<bits/stdc++.h>

using namespace std ;

int a[] = {8,7,5,4} ;

long long L[200][100] = {0} ;

int C(int X,int j,int m,int n)
{
	if(j>n&&X==0)   return 1 ;
	if(j>n)   		return 0 ;
	if(X<0) 		return 0;
	if(L[X][j]!=0)  return L[X][j] ;
	
	long long p = 0;
	
	for(int i=1 ;i<=m;i++ )       p+= C(X-i,j+1,m,n) ;
	return  L[X][j] = p ;
}


int main()
{
	#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout) ;
#endif   

  int n,m ;
  
    
   m = 80 ;
   n =  80;
   int X = 300 ;
	cout<<C(X,1,n,m)<<endl ;

	
	return 0 ;
}