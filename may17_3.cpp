// Rakesh Singh Rawat
// Title - Median of adjacent maximum numbers
// Problem -MXMEDIAN
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
	int testcase , n ;
	
	scan(testcase) ;
	int a[50005] ;
	int b[50005] ;
	
	while(testcase--)
	{
		scan(n) ;
		
		int size = (n<<1) - 1 ;
		int j = size , median ;
		
		
		for(int i=0;i<=size;i++)    scan(a[i]) ;
		
		sort(a,a+size+1) ;
		
		for(int i=size;i>=0;i=i-2)
		{
			b[i] = a[j] ;
			j-- ;
		}
		
		for(int i = 0 ; i<=size ; i=i+2)
		{
			b[i] = a[j] ;
			j-- ;
		}
		
		median = max(b[n],b[n-1]) ;
		
		printf("%d\n",median) ;
		
		for(int i=0;i<=size ; i++)   printf("%d ",b[i]) ;
		
		printf("\n") ;
	}


  return 0 ;
}

