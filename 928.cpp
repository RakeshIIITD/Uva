// Incomplete
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<sstream>
#include<queue>

using namespace std ;


struct T
{
   int n1,n2 ,cost ;
   T(int n1, int n2 ,int cost):n1(n1),n2(n2),cost(cost){
   }	
}
int main()
{
	while(1)
	{
		int n ;
		int n1,n2,cost ;
		vector<T>v ;
		string str ;
		scanf("%d",&n) ;
		scanf("%d\n") ;
		
		for(int i=0;i<n-1;i++)
		{
			getline(cin,str) ;
			stringstream ss(str) ;
			ss>>n1 ;
			ss>>n2 ;
			ss>>cost ;
			v.push_back(T(n1,n2,cost))  ;
		}
	}
	return 0 ;
}
