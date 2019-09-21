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
#define INF 100000
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
int A[101][101] ;
int main()
{
	int a , b ,c=0;
	while(1)
	{
		int m = -99999 ;
		c++ ;
		FOR(i,0,100)
			FOR(j,0,100)
				A[i][j]=INF ;
		scanf("%d %d",&a,&b);
		if(a==0&&b==0) break ;
		while(1)
		{
			m = max(m,max(a,b)) ;
			A[a][b] = 1 ;
			scanf("%d %d",&a,&b) ;
			if(a==0&&b==0)   break ;
		}
		FOR(k,1,m)
			FOR(i,1,m)
				FOR(j,1,m)
					A[i][j] = min(A[i][j],A[i][k]+A[k][j]) ;
		float sum = 0  ;
		int count = m*(m-1) ;
		FOR(i,1,m)
			FOR(j,1,m)
			{
				if(A[i][j]<INF)     sum+=A[i][j] ;
			}
		printf("Case %d: average length between pages = %.3f clicks\n",c,sum/((float)count)) ;
	}
	return 0 ;
}

