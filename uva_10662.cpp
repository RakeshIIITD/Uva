//Accepted

#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>

using namespace std ;

int T[21][22] = {0} ;
int R[21][22] = {0} ;
int H[21][22] = {0} ;

int main()
{
	while(1)
	{
		string line ;
		scanf("\n") ;
		getline(cin,line) ;
		if(line.empty())  break ;
		
		int t,r,h,n ;
		
		stringstream ss(line) ;
		ss>>t ;
		ss>>r ;
		ss>>h ;
		
		for(int i = 0 ; i<t ; i++)
		{
			for(int j = 0 ;j<r+1 ; j++)
			{
				scanf("%d",&n) ;
				T[i][j] = n ;
			}
		}
		
		for(int i = 0 ; i<r ; i++)
		{
			for(int j = 0 ;j<h+1 ; j++)
			{
				scanf("%d",&n) ;
				R[i][j] = n ;
			}
		}
		
		for(int i = 0 ; i<h ; i++)
		{
			for(int j = 0 ;j<t+1 ; j++)
			{
				scanf("%d",&n) ;
				H[i][j] = n ;
			}
		}
		int min_cost = 999999 ;
		int min_t , min_r , min_h ;
		int cost ;
		int flag = 0 ;
		
		for(int i = 0 ; i<t ; i++ )
		{
			for(int j= 0 ; j<r ; j++)
			{
				for(int k = 0 ; k<h ; k++)
				{
					if(T[i][j+1]==0&&R[j][k+1]==0&&H[k][i+1]==0)
					{
						flag++; 
						cost = T[i][0]+R[j][0]+H[k][0] ;
						
						if(cost<min_cost)
						{
							min_cost = cost ;
							min_t = i ;
							min_r = j ;
							min_h = k ;
						}
					}							
				}
			}
		}
		if(flag)   printf("%d %d %d:%d\n",min_t,min_r,min_h,min_cost) ;
		else printf("Don't get married!\n") ;
	}
	return 0 ;
}
