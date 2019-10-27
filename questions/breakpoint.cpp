#include<bits/stdc++.h>

using namespace std ;

int maxStr = 0;
int a[] = {8,7,5,4} ;

void C(int l,int k,int i)
{

		if(k==0&&i==-1)   return ;
		if(k<0)  return ; 
		if(i<0)  return ;

		C(l*10+ a[i],k,i-1) ; 

		if(l*10+ a[i]>maxStr)  maxStr = l*10+ a[i] ;

		C(a[i],k-1,i-1) ;
}


int main()
{
	#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout) ;
#endif   

	C(0,2,3) ;

	cout<<maxStr ;
	return 0 ;
}