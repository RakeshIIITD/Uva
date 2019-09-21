//accepted
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
	int testcase ;
	scanf("%d",&testcase) ;
	
	while(testcase--)
	{
		int v[51] = {0} ;
		int size , t ,temp  , count = 0 , i ,j ;
		scanf("%d",&size) ;
		for( i=0;i<size;i++)
		{   
		   scanf("%d",&t) ;
			v[i] = t ;
		}
		for(int i=0;i<size;i++)
		{
			for(j=0;j<size-i-1;j++)
			{
				if(v[j]>v[j+1])
				{
					temp = v[j] ;
					v[j] = v[j+1] ;
					v[j+1] = temp ;
					count++ ;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n",count );
	}
	return 0;
}
