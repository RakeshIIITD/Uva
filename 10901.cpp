
// wrong output for following testcases;
/*1
1113 1072 9
8631 left
12526 left
15884 left
19388 left
24635 left
30627 right
30627 left
31757 left
35635 right   <---
*/

#include<stdio.h>
#include<iostream>
#include<queue>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std ;

struct T
{
	int  dep ;
	int timestamp ;
	T(int timestamp ,int dep):timestamp(timestamp),dep(dep)
	{
	}
};

bool sortByKey(const T &lhs , const T &rhs)
{
	return lhs.timestamp < rhs.timestamp ;
}

struct Q
{
	int a , ts ;
	Q(int a , int ts):a(a),ts(ts)
	{
	}
};

int main()
{
	int testcase ;
	scanf("%d",&testcase) ;
	
	while( testcase-- )
	{
			int n ,t , m;
			scanf("%d%d%d",&n,&t,&m) ;
			queue<Q>q0 ;
			queue<Q>q1 ;
			
			vector<T>v ; 
			
			int number = m ;
			int stamp = 0 ;
			while(number--)
			{  
				char dir[10] ={'\0'} ;
				int arrival ;
				scanf("%d",&arrival) ;
				scanf( "%s" , dir ) ;
				
				if( dir[0]=='l')	q0.push(Q(arrival , stamp++ )) ;
				else  q1.push(Q(arrival , stamp++ )) ;
			}
			
			int ferry_time = 0 ;
			int b = 0 , flag = 0;
			int count = n ;
			
			while(!( q0.empty()==1&&q1.empty()==1) )
			{
			       if( q0.empty()!=1&&q1.empty()!=1&&q0.front().a>ferry_time&&q1.front().a>ferry_time )
			       {
			       	  if( q0.front().a>q1.front().a )
			       	  {
			       	  	        if( b==0 )
			       	  	        {
			       	  		          ferry_time= q1.front().a ;
			       	  		          ferry_time+=t ;
			       	  		          b = 1 ;
			       	  	        }
			       	  	        else if( b==1 )
			       	  	        {
			       	  		          ferry_time=q1.front().a ;
			       	  	        }
			       	  }
			       	  
			       	 else {
			       	    	 if(q0.front().a==q1.front().a)
			       	       	{
			       	  	    	  if(b==1)
			       	  	    	{
			       	  	     		ferry_time=q1.front().a ;
			       	  	    	}
			       	  	      	  else ferry_time=q0.front().a ;
			       	       	}
			       	  
			       	     	else
			       	      	{
			       	  	    	     if( b==0 )
			       	  	        	{       
			       	  		        	  ferry_time=q0.front().a ;
			       	  	        	}
			       	  	        	else
			       	  	         	if( b==1 )
			       	  	        	{
			       	  	        	  ferry_time=q0.front().a ;
			       	  	 	          ferry_time+=t ;
			       	  	 	          b = 0 ;
			       	  	        	}
			       	        }
			       	    }
			       }
			       
			       if( q1.empty()==1&&q0.empty()!=1 )
			       {
			       		if((b==0)&&(q0.front().a>ferry_time))
			       		{
			       			ferry_time=q0.front().a ;
			       		}
			       		else if(b==1)
			       		{	
			       		    if(ferry_time<q0.front().a)
			       			ferry_time=q0.front().a ;
			       			ferry_time+=t ;
			       			b=0 ;
			       		}
			       }
			       
			       if( q0.empty()==1&&q1.empty()!=1 )
			       {
			       		if( q1.front().a>ferry_time&&b==1)
			       		{
			       			ferry_time = q1.front().a ;
			       		}
			       		else if(b==0)
			       		{    
			       		     if(ferry_time<q1.front().a)
			       			  ferry_time=q1.front().a ;
			       			ferry_time+=t ;
			       			b=1 ;
			       		}
			       }
			       	  while(( count )&&b==0&&q0.empty()!=1)
			       	  {
			       	  	  if( ferry_time<q0.front().a )    break ;
			       	  	  v.push_back(T(q0.front().ts , ferry_time+t)) ;
			       	  	  q0.pop() ;
			       	  	   count-- ;
			       	  	  //printf("%d\n", ferry_time+t ) ;
			       	  	  
			       	  }
			       	  
			       	  if( b==0 &&count!=n)
			       	  {
			       	  	  ferry_time+=t ;
			       	  	  b=1 ;
			       	  	  count = n ;
			       	  }
			       	  
			       	  while( (count)&&b==1&&q1.empty()!=1 )
			       	  {
			       	  	  if( ferry_time<q1.front().a )   break ;
			       	  	  
			       	  	   v.push_back(T(q1.front().ts , ferry_time+t)) ;
			       	  	   
			       	  	  q1.pop() ;
			       	  	 count-- ;
			       	  	 // printf("%d\n",ferry_time+t ) ;
			       	  }
			       	  if(b==1&&count!=n)
			       	  {
			       	  	  ferry_time+=t ;
			       	  	  b = 0 ;
			       	  	  count = n ;
			       	  }
		    }
		    stable_sort(v.begin(),v.end(),sortByKey) ;
		    
		    for(int i=0;i<v.size();i++)
		    printf("%d\n",v[i].dep) ;
		    
	     printf("\n") ;
	     v.clear() ;
	}
	return 0;
}
