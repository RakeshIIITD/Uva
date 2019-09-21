// `roCKy FireBirD
// Accepted
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<vector>

//#define MAX

using namespace std ;

int main()
{
	string line ;
	
	while(getline(cin,line))
	{
		stringstream ss(line) ;
		string s ,t ;
		ss>>s ;
		ss>>t ;
		int i =0 ;
		int j = 0 ;
		int flag=0;
		while(1)
		{
			if(i==s.size())  
			{
				flag++ ;
				break ;
			}
			if(j==t.size())   break ;
			if(s[i]==t[j])  i++ ;
		    j++ ;
		}
		if(flag)   printf("Yes\n") ;
		else printf("No\n");
	}
	
 	return 0;
}

