//Accepted
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<stack>

using namespace std ;

int main()
{
	int n ;
	while(1)
	{
		scanf("%d",&n) ;
		if(n==0) break ;
		while(1)
		{
			vector<int> v ;
			vector<int> stck ;
			string s ;
		    int ind ;
		    
		    scanf("%d",&ind);
		    
		    if(ind==0) 
			{
			  printf("\n");
			  break ;
		    }
		    
			v.push_back(ind) ;
			 
		    for(int j=1;j<n;j++)
		    {
		    	scanf("%d",&ind) ;
		    	v.push_back(ind) ;
		    }
		
			int counter = 1 ;
			int i = 0 ;
			int flag = 0 ;
			
			while(1)
			{   
			    if(i==v.size()&&stck.empty()==1)
			    {
			    	flag++ ;
			    	break ;
			    }
			    
			   if(stck.empty()!=1)
			   {
			   	if(v[i]!=stck.back()&&v[i]<counter) break ;
			   }
			    
			    if(v[i]>counter)
			    {
			    	stck.push_back(counter) ;
			    	counter++ ;
			    }
			    
			    if(v[i]==counter)
			    {
			    	counter++ ;
			    	i++ ;
			    }
			    
			    if(stck.empty()!=1)
			    if(v[i]==stck.back())
			    {
			    	stck.pop_back() ;
			    	i++ ;
			    }
			}
		 if(flag&&ind!=0)	printf("Yes\n") ;
		 if(!flag==1&&ind!=0) printf("No\n") ;
		 v.clear() ;
		}	
	}
	return 0;
}
