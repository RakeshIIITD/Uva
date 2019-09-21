#include<bits/stdc++.h>

using namespace std ;

int L[101] = {0} ;

int C(int a[],int l,int i,int x ,int y,int n)
{
	if(l==y&&i<0)  return 1 ; 
	if(i<0)   return 0 ;
	//if(l<0) return 0 ;
	//if(l>n)   return 0;
	if(L[l]!=0)  return L[l] ;

	return L[l] = C(a,l+a[i] ,i-1,x,y,n) + C(a,l,i-1,x,y,n);
}

int main()
{

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout) ;
  #endif 

int x = 1 ;
int y = 2 ;
int n = 6 ;

  int a[] = {1,1,-1,1,-1,1} ;
  cout<<C(a,x,5,x,y,n) ;
	
	return 0 ;
}