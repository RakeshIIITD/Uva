/*Code Awesome*/
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std ;

int strlen(char a[])
{
	int i=0 ;
	while(a[i]!='\0')
	{
		i++ ;
	}
	return i+1 ;
}

int main()
{
	int testcases ;
	scanf("%d",&testcases) ;
	
	while(testcases--)
	{  
	    stack <char> s1 ;
		stack <char> s2 ;
		stack <char> s3  ;
		char exp[10000]={'\0'} ;
		scanf("%s",exp) ;
		int i ;
		int len = strlen(exp) ;
		for( i=0 ; i<len ; i++ )
		{   if( exp[i]==')')
		    {     
		        while( s2.top()!='(' )
		        {
		          s1.push( s2.top() ) ;
		          s2.pop() ;
		        }
		        s2.pop() ;
		    }
			else {
		   		if( isalpha(exp[i]) ) 	s1.push(exp[i]) ;
				else   s2.push(exp[i]) ;
			}
		}
		while(s1.empty()!=1)
		{   s3.push(s1.top()) ;
			s1.pop() ;
		}
	    while(s3.empty()!=1)
	    {
	    	cout<<s3.top() ;
	    	s3.pop() ;
	    }
	    printf("\n") ;
	}
	return 0 ;
}
