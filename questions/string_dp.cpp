#include<bits/stdc++.h>

using namespace std ;

int p[] = {1,3,1,1} ;
string str[] = {"aa","ba","ac","ad"} ;

int C(string prev,int i)
{
	if(i<0)   return 0 ;

	int n1 = 99999 ; int n2 = 99999 ;

	reverse(str[i].begin(), str[i].end());
	
	if(str[i]<prev)     n1 = p[i] + C(str[i],i-1) ;
	
	reverse(str[i].begin(), str[i].end()) ;

	if(str[i]<prev) 	n2 = C(str[i],i-1) ;
	
	return min(n1,n2) ;
}


int main()
{
	#ifndef ONLINE_JUDGE
  	freopen("input.txt","r",stdin);
  	freopen("output.txt","w",stdout) ;
	#endif   

	cout<<C("zzzzzz",3) ;

	return 0 ;
}