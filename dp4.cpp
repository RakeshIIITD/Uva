#include<bits/stdc++.h>
// longest repeated subsequence
using namespace std;
int L[1000] = {0} ;

int C(int a[],int n,int j)
{
		if(j==n-1) return 0;  
		if(j>n)   return 99999 ;
		if(L[j]!=0)   return L[j] ;
		int p = 99999	 ;

		for(int k=1;k<=a[j];k++)    p = min(p , 1 + C(a,n,j+k)) ;

		return L[j] = p ;
}



int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout) ;
  #endif 
  int a[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9, 3, 5, 8, 9, 2, 6, 8, 9, 2, 6, 7, 6, 8, 9, 3, 5, 8, 9, 2, 6};
  int b[] = {1, 2, 3} ;
  int n = sizeof(a)/sizeof(int);
  

  	cout<<C(a,n,0);
	return 0;
}