//Accepted
// Exhaustive search

#include<stdio.h>
#include<iostream>

using namespace std ;

int sol[16] = {0} ;

int m[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}} ;

int max_length ;

void unmark(int n)
{
	for(int i = 0 ; i<n ; i++)
	{
		for(int j = 0 ; j<n ; j++)
		{
			if(m[i][j]!=2)	m[i][j] = 0 ;
		}
	}
}

void mark(int x , int y , int n )
{	
	int i = x ;
	int j = y ;
	while(i<n&&m[i][j]!=2)	// y - axis ,  right
	{
		  m[i][j] = 1 ;
		  i++ ;
	}
	i = x ;
	while(i>-1&&m[i][j]!=2 )		// y - axis , left
	{
		m[i][j] = 1 ;
		i-- ;
	}
	i = x ;
	while(j<n&&m[i][j]!=2)		// x-axis , right
	{
		m[i][j] = 1 ;
		j++ ;
	}
	j = y ;
	while(j>-1&&m[i][j]!=2)		// x-axis , left
	{
		m[i][j] = 1 ;
		j-- ;
	}
}

int check(int n)
{
	int index ;
	int count = 0 ;
	
	for(int i = 0 ; i<n ; i++)
	{
		for(int j = 0 ; j<n ; j++ )
		{
			index = n*i+j	;
			if(sol[index]==1&&m[i][j]==0) 
			{
				count++ ;
			   	mark(i,j,n);
		    }
			else
			{
				if(sol[index]==1)
				return -1 ;
			} 		
		}
	}
	return count ;
}

void C(int i ,int size , int n )
{
	if(size==i)
	{
		/*for(int j = 0 ; j<size ; j++ )
			printf("%d",sol[j]) ;
		printf("\n") ;
		*/
			
		unmark(n) ;
		int k =  check(n) ;
		
		if(k>max_length)  max_length = k ;
		
		return ;
	}
	sol[i] = 0 ;
	C(i+1,size , n  ) ;
	sol[i] = 1 ; 
	C(i+1,size , n  ) ;
	
}

int main()
{
	int n ;
	while(1)
	{
		max_length = -1 ;
		char ch ;
		scanf("%d",&n) ;
		if(!n)  break ;
		for(int i = 0 ; i<n ; i++)
		{
			for(int j = 0 ; j<n ; j++)
			{
				scanf("\n%c",&ch) ;
				if(ch=='.')  m[i][j] = 0 ;
				else m[i][j] = 2 ;
			}
		}
		C(0,n*n , n) ;
		printf("%d\n",max_length) ;
	}
	return 0 ;
}
