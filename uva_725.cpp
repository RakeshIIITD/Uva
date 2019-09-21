// Accepted
#include<stdio.h>
#include<iostream>

using namespace std ;

bool isfive(int i)
{
	int count = 0 ;
	while(i)
	{
		i = i/10 ;
		count++ ;	
	}
	
	if(count==5)  return 1 ;
	else return  0 ;
}

bool unique(int i , int k)
{
	int a[10] = {0} ;
	int n ;
	int m ;
	int count = 0 ;
	while(count<5)
	{
		n = i%10 ;
		m = k%10 ;
		a[n]++ ;
		a[m]++ ;
		i = i/10 ;
		k = k/10 ;
		count++ ;
	}
	for(int j = 0 ;j<10 ; j++) 
	{
		if(a[j]>1||a[j]<1) return 0 ; 
	}
	return 1 ;
}

int main()
{
	int N ;
	int count = 0 ;
	while(1)
	{
		scanf("%d",&N) ;
		
		if(!N) break ;
		if(count)   printf("\n") ;
		count++ ;
		int i = 01234 ;
		int k = N*i ;
		int flag = 0 ;
		
		while(k<99999)
		{
			if(unique(i,k))   
			{
				flag++ ;
				if(isfive(i)) printf("%d / %d = %d\n",k,i,N) ;
			  	else          printf("%d / 0%d = %d\n",k,i,N) ;
			}
			i++ ;
			k = i*N ;
		}
		if(!flag)   printf("There are no solutions for %d.\n",N) ;
	}
	return 0 ;
}
