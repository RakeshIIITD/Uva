#include<bits/stdc++.h>

using namespace std ;

int x[] = {6,9,12,14} ;
int r[] = {5,6,3,7} ;
int t = 2 ;
int M = 20 ;

long long L[2000] = {0} ;

int C(int i,int prev)
{
	if(i<0)   return  0;
	
	int n1 = -99999 ;
	int n2 ;

	if(prev-x[i]>t)         n1 = r[i] + C(i-1,x[i]) ;
	n2 = C(i-1,prev) ;


	return max(n1,n2) ;
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
	cout<<C(4,M)<<endl ;

	
	return 0 ;
}