// NICE QUESTION
// change in way of setting parent set
//accepted
#include<stdio.h>
#include<iostream>
#include<vector>
#include<sstream>
#include<set>

using namespace std ;

vector<int>pset(69) ;

void initSet(int _size) 
{ 
	pset.resize(_size) ; 
	for(int i = 0 ; i<_size ; i++ ) 
	{
	  pset[i] = i ;
	}
}

int findSet(int i)
{
	return (pset[i]==i)?i : pset[i]=findSet(pset[i]) ;
}

void unionSet(int i , int j)
{	
	i = findSet(i) ;
	j = findSet(j) ;
	if(i!=j)
	{
		if(j>i)  pset[i] = j ;
	  	else     pset[j] = i ;
    }
} 

int main()
{   
int flag = 0 ;
	while(1)
	{   
		
	    initSet(69) ;
		set<int>m ;
		int n ;
		char ch ;
		string line ;
		if(!getline(cin,line)||line.empty())   break ;
		if(flag) 
		{
		 printf("\n") ;
	    }
	    flag++ ;
		stringstream ss(line);
		ss>>n ;
		string str1="" , str2="";
		for(int i=0;i<n;i++)
		{
			scanf("\n%c",&ch) ;
			str1+=ch ;
		}
		for(int i=0;i<n;i++)
		{
			scanf("\n%c",&ch) ;
			str2+=ch ;
		}
		for(int i=0;i<n;i++)
		{
				char a = str1[i] , b = str2[i] ;
			if(str1[i]!=str2[i])
			{
			
				unionSet( (a>47&&a<58)?a-'0':a , (b>47&&b<58)?b-'0':b ) ;
				if(a>47&&a<58)  m.insert(a-'0') ;
				if(b>47&&b<58)  m.insert(b-'0') ;	
			}
			 
		}
		
		if(findSet('A')>'A'||findSet('B')>'B'||findSet('C')>'C'||findSet('D')>'D')
		   printf("NO\n");
		else
		{
			set<int>::iterator it ;
			printf("YES\n") ;
			for(it = m.begin() ; it!=m.end();it++)
			{
				if(isupper(findSet(*it)))   // last edited
				printf("%d %c\n", *it , findSet(*it)) ;
			}
		}
		
		scanf("\n");	
	}
	return 0 ;
}
