// contains ignoreline input method
#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std ;

int n ;         // for number of sets
vector<int>pset(27) ;


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
	int testcase ;
	string high ;
	scanf("%d\n\n",&testcase);
	while(testcase--)
	{   
	
	 getline(cin,high);
		
		initSet(high[0]-'A'+1) ;
		n = high[0]-'A'+1 ;  
		while(1)
		{
			if(!getline(cin,high)||high.empty())  break ;
			unionSet(high[0]-'A',high[1]-'A') ;
		}
		printf("%d\n",numberOfSets());
		if(testcase>0)  printf("\n") ;
	}
	return 0 ;
}
