//Accepted
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std ;

vector<int>pset(100) ;
int size[100] ;

struct T
{
	int i ;
	float x ,y ,r ;
	T(int i , float x ,float y ,float r):i(i),x(x),y(y),r(r){
	}
} ;

void initSet(int _size) 
{ 
	pset.resize(_size) ; 
	for(int i = 0 ; i<_size ; i++ ) 
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
	int n ;
	while(1)
	{
		scanf("%d", &n );
		if(n==-1)   break ;
		float x,y,r ;
		
		initSet(n) ;
		
		vector<T>v ;
		
		for(int i=0;i<n;i++)
		{
			scanf("%f%f%f",&x,&y,&r);
			v.push_back(T(i,x,y,r)) ;
		}
		
		float d ;
		for(int m=0;m<n;m++)
		{
			for(int s = m+1 ; s<n;s++)
			{
				d = sqrt( pow( v[s].x - v[m].x , 2 ) + pow( v[s].y - v[m].y , 2 )) ;
				
				if(( d<=(v[s].r + v[m].r))&&(d>=fabs(v[s].r - v[m].r)))                                    // = sign removed
				 		unionSet( v[s].i , v[m].i ) ;
			}
		}
		
		int max = 0 ;
		
		for(int i=0;i<n;i++)
		{
			if(getSize(i)>max)   max = getSize(i) ;	
		}
		if(max==1)		printf("The largest component contains 1 ring.\n") ;
		else printf("The largest component contains %d rings.\n", max ) ;
		v.clear() ;
	}
	return 0 ;
}
