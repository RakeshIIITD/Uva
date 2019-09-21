// use of mystring.c_str() ;
#include<iostream>
#include<stdio.h>
#include<map>

using namespace std ;

int main()
{
	int testcase ;
	scanf("%d",&testcase) ;
	getchar() ;
	getchar();
	while(testcase--)
	{
		int count = 0 ;
		map<string,double> m ;
		while(1)
		{
			
		 	string str ;
			getline(cin,str) ;
			
			if(str.empty()) break ;
			count++ ;
			if(m.find(str)==m.end())   m[str]=1 ;
			else  m[str]+=1 ;
		}
		map<string,double>::iterator itr ;
		for(itr = m.begin() ; itr!=m.end() ; itr++ )
		{
			itr->second = ((itr->second)/count)*100 ;
		}
		
		for(itr = m.begin() ; itr!=m.end() ; itr++ )
		{   
		    //cout<< itr->first <<" ";
			printf("%s %.4lf\n",(itr->first).c_str(),itr->second) ;
		}
		if(testcase>0) printf("\n") ;
	}
	return 0 ;
}
