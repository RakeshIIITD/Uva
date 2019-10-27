#include<bits/stdc++.h>

using namespace std ;

string S = "geeksforgeeksgegegegegegegegege" ;
string T = "ge" ;

long long L[100][100] = {0} ;

int C(int i,int j)
{
	if(i<0&&j>=0)   return  0;
	if(j<0)   return 1 ;
	if(L[i][j]!=0)  return L[i][j] ;
	
	if(S[i]!=T[j])   return C(i-1,j) ;

	return L[i][j] =  C(i-1,j-1) + C(i-1,j) ;
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
	cout<<C(S.length()-1,T.length()-1)<<endl ;

	
	return 0 ;
}