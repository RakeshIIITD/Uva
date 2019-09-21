// Accepted
#include<iostream>
#include<stdio.h>
#include<stack>
#include<string>
#include<algorithm>
#include<sstream>
#include<vector>

using namespace std ;

int main()
{
	int testcase ;
	scanf("%d",&testcase) ;
	string s ;
	scanf("\n") ;
	while(testcase--)
	{
		vector<char>stck ;
		getline(cin,s) ;
		stck.push_back(s[0]) ;
		for(int i=1 ;i<s.size() ; i++ )
		{
			 if(stck.empty()!=1&&(stck.back()=='('&&s[i]==')'||stck.back()=='['&&s[i]==']'))     
			 	 stck.pop_back() ;
			 else stck.push_back(s[i]) ;
		}
		if(stck.empty()==1||s.empty()==1)   printf("Yes\n") ;
		else printf("No\n") ;
		stck.clear() ;		
	}
	return 0 ;
}
