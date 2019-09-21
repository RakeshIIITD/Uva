//Accepted
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std ;

vector<int>pset(30001) ;
int size[30001] ;


void initSet(int _size) 
{ 
	pset.resize(_size) ; 
	for(int i = 1 ; i<=_size ; i++ ) 
	{
	  pset[i] = i ;
	  size[i] = 1 ;
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
		if(size[i]>size[j]) 
		{
	 		pset[i] = j ;
	 		size[j]+= size[i] ;
    	}
	 	else 
	 	{
	  		pset[j] = i ;
	  		size[i]+= size[j] ;
     	}
    }
} 

int getSize(int i)
{
	return size[findSet(i)] ;
}

int main()
{
	int n , m , testcase;
	scanf("%d",&testcase) ;
	while(testcase--)
	{
		int x ,y ;
		scanf("%d%d", &n , &m );
		
		initSet(n+1) ;
		
		
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			unionSet(x,y) ;
		}
		
		int max = -999;
		
		for(int i=1;i<=n;i++)
		{
			if(getSize(i)>max)   max = getSize(i) ;	
		}
		if(m==0) printf("0\n");
		else printf("%d\n",max) ;
	}
	return 0 ;
}
