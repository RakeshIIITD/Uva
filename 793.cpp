#include<stdio.h>
#include<iostream>
#include<vector>
#include<sstream>
using namespace std ;
        
vector<int>pset(1000) ;

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
	  pset[i] = j ;
    }
} 

bool isSameSet(int i , int j )
{
	return findSet(i)==findSet(j) ;
}

int main()
{
	int testcase ;
	scanf("%d",&testcase);
	
	while(testcase--)
	{
		int size  , i,n ,j ,success=0 , unsuccess=0 ;
		char type ;
		scanf("%d\n",&n) ;
		initSet(n+1) ;
		string line ;
		while(1)
		{
		   if(!getline(cin,line)||line.empty())  break  ;
		   stringstream ss(line);
		   ss>>type ;
		   ss>>i ;
		   ss>>j ;
		   if(type=='c')   unionSet(i,j) ;
		   else if(isSameSet(i,j)==1)  success++ ;
		        else unsuccess++ ;
		}
		printf("%d,%d\n",success,unsuccess);
		if(testcase>0)  printf("\n") ;
	}
	return 0 ;
}
