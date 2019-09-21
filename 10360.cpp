//Accepted

#include<stdio.h>
#include<iostream>

using namespace std ;

int killed[1025][1025] ;

int C(int n)
{
	if(n<0)  return 0 ;
	if(n>1024)  return 1024 ;
	else return n ;
}

int main()
{
	int t ;
	scanf("%d",&t) ;
	
	while(t--)
	 {	
		for(int i = 0 ; i<1025 ; i++)
		{
		   for(int j = 0 ; j<1025 ; j++)
		   {
			killed[i][j] = 0 ;
		   }
	    }
	    
		int d , n ,y_limit , x_limit;
		int x ,y , rat_size ;
		scanf("%d%d",&d,&n) ;
		
		for(int i = 0 ; i<n ; i++ )
		{
			scanf("%d%d%d",&x,&y,&rat_size ) ;
			y_limit = C(y+d) ;
			x_limit = C(x+d) ;
			for(int l = C(y-d) ; l<=y_limit ; l++ )
				{
					for(int m = C(x-d) ; m<=x_limit ; m++  )
					{
						killed[l][m]+=rat_size; 
					}
				}
		}
		
		int max_rat = -999 ;
		int max_x ;
		int max_y ;
		
		for(int i = 0 ; i<1025 ; i++)
		{
			for(int j =0 ; j<1025 ; j++)
			{	
				if(killed[i][j]>max_rat)
				{
					max_rat = killed[i][j] ;
					max_x = j ;
					max_y = i ;
				}
			}
		}
		
		for(int i = 0 ; i<1025 ; i++)
		{
			for(int j =0 ; j<1025 ; j++)
			{	
				if(killed[i][j]==max_rat)
				{
					max_rat = killed[i][j] ;
					if(max_x>j)
					{
						max_x = j ;
						max_y = i ;
					}
					else{
						if(max_x==j&&max_y>i)
						{
							max_x = j ;
							max_y = i ;
						}
					}
				}
			}
		}
		
		
		printf("%d %d %d\n",max_x,max_y,max_rat);
	}
	return 0 ;
}
