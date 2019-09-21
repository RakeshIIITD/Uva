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
int P[1005][1005] ;
string s ;
int Pal(int i,int j)
{
	
	if(i==j)  return 1 ;
	if(i+1==j) 
	{
	  if(s[i]==s[j]) return 2 ;
	  else return 1 ;
    }
	if(P[i][j]!=-1)   return P[i][j] ;
	if(s[i]==s[j])  return 2+Pal(i+1,j-1) ;
	
	else return P[i][j] = max(Pal(i+1,j),Pal(i,j-1)) ;
}
int main()
{
  
  int n ;
  scanf("%d\n",&n);
  while(n--)
  {
  	memset(P,-1,sizeof(P)) ;
  	getline(cin,s) ;
  	if(s.empty()==1)   printf("0\n") ;
  	else printf("%d\n",Pal(0,s.size()-1)) ;
  	s.clear() ;
  }
	return 0 ;
}

