// Accepted
// Aliter - Do it by recursion

#include<stdio.h>
#include<string>
#include<iostream>

using namespace std ;


int main()
{	
    int count = 0 ;
	while(1)
	{
		int t ;
		int s[50] ;
	 	
	 	
		scanf("%d",&t) ;
		if(!t)   break ;
		
		if(count)   printf("\n") ;
	 	count++ ;
		
		for(int i = 0 ;i<t ; i++) 
			scanf("%d",&s[i]) ;
	
		for(int i = 0 ; i<t ; i++ )
			for(int j = i+1 ; j<t ; j++ )
				for(int k = j+1 ; k<t ; k++ )
					for(int l = k+1 ; l<t ; l++ )
						for(int m = l+1 ; m<t ; m++ )
							for(int n = m+1 ; n<t ; n++ )
								printf("%d %d %d %d %d %d\n",s[i],s[j],s[k],s[l],s[m],s[n]) ;
		
	}
	return 0 ;
}
