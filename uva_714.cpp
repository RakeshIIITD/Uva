#include<stdio.h>
#include<iostream>
#include<sstream>
#include<vector>

using namespace std ;
int a[501] = {0} ;

int main()
{
	int testcase ;
	scanf("%d",&testcase) ;
	while(testcase--)
	{
		int n , groups ;
		scanf("%d%d",&n,&groups) ;
	
		long total_sum ;
		for(int i=0;i<n;i++)
		{
		  scanf("%d",&a[i]) ;
		  total_sum+=a[i] ;
	    }
	    int w =1 , prev_w ;
	    int prev_loss =  total_sum ;
	    
	    while(1)
	    {
	    	
	      int i = 0 , loss = 0;
	    	for(int j=0;j<groups ; j++ )
	    	{
	    		g[j] = 0 ;	
				while(1)
	    		{
	    			if(g[j]+a[i]>w)   break ;
	    			else g[j]+=a[i] ;
	    			i++ ;
	    		}
	    		loss = loss + g[j] - w ;
	    	}
	    	if(loss<prev_loss)
			{
				w = (w+prev_w)/2 ;		
			}
			prev_w = w ;
			w = w*2 ;
			prev_loss = loss ; 
	    }
		
	}
	return 0 ;
}
