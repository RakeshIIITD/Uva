//Accepted
#include<stdio.h>
#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std ;

int n ;         // for number of sets
vector<int>pset(50001) ;

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
	  n=n-1 ;                   // decrease number of sets by 1 , each time a union is formed
	  pset[i] = j ;
	}
} 

int numberOfSets()
{
		return n ;
}
int main()
{
	int N , m ,cs=1;
	while(1)
	{
		int p1,p2 ;
		scanf("%d%d",&N,&m) ;
		n = N ;
		if(N==0&&m==0)   break ;
		
		initSet(N+1) ;
		
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&p1,&p2) ;
			unionSet( p1 , p2 ) ;
		}
		printf("Case %d: %d\n",cs,numberOfSets()) ;
		cs++ ;
	}
	return 0 ;
}
