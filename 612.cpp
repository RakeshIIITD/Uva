//accepted
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

struct str
{
	int inv ;
	string s ;
	str(int inv , string s):inv(inv),s(s){} ;
} ;

bool sortByInv(const str &lhs ,const str &rhs )
{
	return lhs.inv<rhs.inv ;
}

int main()
{
	int testcase ;
	scanf("%d",&testcase);
	while(testcase--)
	{
		
		
		string s ;
		int len , n ;
		scanf("%d%d",&len,&n);
		vector<str>v ;
		getchar();
		for(int i=0;i<n;i++)
		{   
		    int inversion = 0;
		    getline( cin , s ) ;
		    
			for(int k = 0 ; k<len-1 ;k++ )
			{    
			    int inv = 0 ;
				for(int l =k+1 ; l<len ; l++ )
				{
				    if(s[k]>s[l])  inv++ ;	
				}
				inversion+=inv ;				
			}
		//	cout<<inversion ;
			v.push_back(str(inversion,s)) ;
		}
		stable_sort( v.begin() , v.end() , sortByInv ) ;
		
		for(int i=0;i<n;i++)
		{
			cout<<v[i].s<<endl ;
		}
		v.clear() ;
		if(testcase)   printf("\n") ;
	}
	return  0;
}
