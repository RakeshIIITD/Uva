//Accepted
#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int testcase ;
	scanf("%d\n\n",&testcase) ;
	string line ;
	
	while(testcase--)
	{
		int n , h ;
		scanf("%d",&n);
		scanf("%d",&h) ;
		
		string str = "" ;
		
		for(int i = 0 ; i<n-h ; i++)
			str+='0';
		
		for(int i=0;i<h;i++)
		str+='1' ;
		cout<<str<<endl ;
		while(next_permutation(str.begin(),str.end()))
		{
			cout<<str<<endl ;
		}
		if(testcase>0) printf("\n");
	}
	return 0 ;
}
