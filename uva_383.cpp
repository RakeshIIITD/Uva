// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std ;
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)

map< vector<string> > vii ;
queue<int>q ;
int main()
{
	
	int testcase ,m ,n , p ;
	
	scanf("%d",&testcase) ;
	while(testcase--)
	{
		queue<string>q ;
		scanf("%d %d %d\n",&m,&n,&p) ;
		string str ,str1 ,str2 ,st ;
		getline(cin,str) ;
		stringstream ss1(str) ;
		for(int i=0;i<m;i++)
		{
			ss1>>st ;
			m[st] = -1 ;
		}
		
		for(int i=0;i<n;i++)
		{
			scanf("%s %s\n",str1,str2) ;
			vii[str1].push_back(str2) ;
			vii[str2].push_back(str1) ;
		}
		string source , destination  , s;
		int a  , s1 , distance;
		for(int i=0;i<p;i++)
		{
		 	getline(cin ,s ) ;
		 	stringstream ss(s) ;
		 	ss>>a ;
		 	ss>>source ;
		 	ss>>destination ;
			
			m[source] = 0 ;
			q.push(source) ;
			int flag = 1 ;
			while(q.empty()!=1)
			{
				if(flag==0)   break ;
				s1 = q.front() ; q.pop() ;
				int size  = vii[s1].size() ;
				for(int i=0;i<size ; i++ )
				{
					
					if(m[vii[s1][i]]==-1)
					{
						m[vii[s1][i]] = m[s1]+1 ; 
						q.push(vii[s1][i]) ;
					}
					if(vii[s1][i]==destination)
					{
					 distance = m[s1] ;
					 flag=0;
					 break ;
				    }
					
				}	
			}
			printf("$%d\n",distance*a*100) ;
			m.clear() ;
		}
		
    }
	return 0 ;
}
