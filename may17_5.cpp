// Rakesh Singh Rawat
// Chef and subsequence
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
long long L[35][35] ;
int a[35] ;

int C(int n , long long k)
{
	
	//for(int i =0 ;i<=n;i++)  L[i][0] = 1 ;
	
	for(int i=1;i<=n;i++)
	{
		L[i][i-1] = 1 ;
		L[i][i] = a[i-1] ;	
	}
		
    int count=0 ;
    
    for(int i=1;i<=n;i++)
	{	
		for(int j=i;j<=n;j++)
		{
			L[i][j] = a[j-1]*L[i][j-1] ;
			
			if(L[i][j]<=k) count++ ;  
		}
		
    }
    
}
int main()
{
   int n ;
   long long k ;
   
   
   scanf("%d",&n) ;
   scanf("%lld",&k) ;
   
   for(int i=0;i<n;i++)  scanf("%d",&a[i]) ;
   
   printf("%d\n",C(n,k)) ;

  return 0 ;
}

