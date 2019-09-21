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
//================================================================================
#define INF 100000000
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)					// for
#define LL signed long long int
#define fre 	freopen("0.in","r",stdin);freopen("0.out","w",stdout)
#define print(x) printf("%d\n",x)											//printf
#define printll(x) printf("%lld\n",x)
#define scanll(x) scanf("%lld",&x)
#define scan(x) scanf("%d",&x)												// scanf
#define ln  scanf("\n")														//consume \n
#define SS(a) stringstream ss(a)
#define ii pair<int,int>
#define F first
#define S second
#define abs(x) ((x)>0?(x):-(x))
#define RESET(arr,val) memset(arr, val, sizeof(arr))
#define ret return
#define ITERM(v) for(map<int,int>::iterator it = v.begin() ; it!=v.end() ; it++ )
#define ITERV(v)  for(vector<int>::iterator it = v.begin() ; it!=v.end() ; it++ )
#define VPUSH(v,b) v.push_back(b)												// push_back()
#define VI vector<int>
//=================================================================================

int main()
{
	string str ;
	map<string,int> m ;
	int c = 0	;
	
	while(cin>>str&&str.empty()!=1)
	{
		m[str] = 0 ;
		c++ ;
	}

		for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
		FOR(i,0,(it->first).size()-1)
		{
			str=(it->first) ;
			//cout<<str.substr(0,i)<<endl;
			if((m.find(str.substr(0,i+1))!=m.end())&&(m.find(str.substr(i+1))!=m.end()))  
			{
			  if(m[str]==0) 
			  {
			    cout<<str<<endl;
				m[str]++ ;
			  }
			}
		}
	return 0 ;
}

