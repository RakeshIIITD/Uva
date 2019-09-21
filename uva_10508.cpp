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

int dif(string str1 ,string str2 , int len)
{
	int count = 0 ;
	FOR(i,0,len-1)
	{
		if(str1[i]!=str2[i])  count++ ;
	}
	return count ;
}
int main()
{
	vector<pair<string,int> >v;
	int n , m ;
	string str ,source ,dest;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		cin>>source;
		cin>>dest;
		v.push_back(make_pair(dest,0)) ; 
		FOR(i,0,n-3)
		{
			cin>>str ;
			v.push_back(make_pair(str,0)) ;
		}
		cout<<source<<endl;
		int flag = 0 ;
		FOR(i,0,n-2)
		{
			FOR(j,0,n-2)
			{
				
				if(v[j].S==0)
				{
					//cout<<dif(v[j].F,source,m);
					if(dif(v[j].F,source,m)==1) 
					{
						
						(v[j].S)=1 ;
						source = v[j].F ;
						cout<<source<<endl ;
						continue ;
					    if(v[j].F==dest) {
					    flag = 1 ;
					    break ;
					}
					}
					
				}
			}
			if(flag)  break ;
		}
		v.clear() ;
	}
	
	return 0 ;
}

