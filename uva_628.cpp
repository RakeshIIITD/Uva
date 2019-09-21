//Accepted
// permutation

#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>

using namespace std ;

string dictionary[200] ;
string rule[200] ;

void C(int j , int n , int m)
{
	if(j==m)
	{
		for(int k = 0 ; k<m ; k++)
		{
		  cout<<rule[k];
		  if((k+1)%m==0)  cout<<endl ;
	    }
		return ;
	}
	
	int len , bit = 1;
	if(rule[j]=="0")  
	{
		bit=0; 
		len = 10 ;
	}
	else len = n ;
	
	for(int i=0;i<len ; i++)
	{
		stringstream ss ;
		ss<<i ;
		rule[j] = bit?dictionary[i]:ss.str() ;	
		C(j+1 , n , m ) ;
		rule[j] = bit?'#':'0' ;
	}
}	

int main()
{
	string line ;
	int c = 0 ;
	while(1)
	{
		c++ ;
		getline(cin,line) ;
		stringstream ss(line) ;
		
		if(line.empty())   break ;
		
		printf("--\n");
		int n , m ;
		ss>>n ;
		
		for(int i=0;i<n ; i++)
		{
			getline(cin,dictionary[i]) ;
		}
		
		getline(cin,line) ;
		stringstream ss1(line) ;
		ss1>>m ;
		
		for(int i=0;i<m;i++)
		{
			string rule_line ;
			getline(cin , rule_line ) ;
		
			int len = rule_line.size() ;
		 	for(int i=0;i<len;i++)
			{
				rule[i] = rule_line[i] ;
			}
			C(0,n,len) ;
	    }
	}	
	return 0 ;
}
