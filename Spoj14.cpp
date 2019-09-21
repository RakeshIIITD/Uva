/*Code Awesome*/
#include<iostream>
#include<map>
#include<stdio.h>
#include<cstdio>
#include<string>

using namespace std ;

int main()
{
	int testcases ; 
	scanf("%d",&testcases ) ;
	while(testcases--)
	{   
	    long n , i;
	    map <string,int> mp ;
	    scanf("%ld",&n);
		for(i=0;i<n;i++)
	    {
	      string s;
	      
		  getline(cin , s) ;
		  
		  if(mp[s]==1)  mp[s]++ ;
		  else mp[s]=1 ;
	   }
	   map <string,int>::iterator it ;
	   
	   for(it = mp.begin() ; it!=mp.end() ; it++ )
	   cout<<it->first<<" "<<it->second<<endl ;
     }
	return  0; 
}
