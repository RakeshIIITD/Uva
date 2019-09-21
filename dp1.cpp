#include<bits/stdc++.h>
// longest repeated subsequence
using namespace std;
int L[1000] = {0} ;

int C(int a[],int n,int W,int m)
{
		if(n<0)   return 0 ;
		if(W!=0&&W%m==0)  return 1 ;
		return C(a,n-1,W+a[n],m)||C(a,n-1,W ,m);
}



int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout) ;
  #endif 
  int a[] = {1,6} ;
  int n = sizeof(a)/sizeof(int);
  int m =5;

  	cout<<C(a,n-1,0,m);
	return 0;
}