// Rakesh Singh Rawat

//Problem - CHEFCODE

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
int L[31] ;
long long a[31];
long long c = 0 ;

void C(int n,int d,long long k)
{
	
	long long mul = 1 ;
	int flag = 0 ;
	if(n==-1)
	{
		
	for(int i = 0 ;i<d ; i++)
	{
		if(L[i]==1) 
		{
		  mul = mul*a[i] ;
	    }
	    if(mul>k)
	    {
	    	flag = 1 ;
	    	break ;
	    }
	}
	
	if(flag==0&&mul<=k)  
	{
	  c++ ;
	}
	return ;
	}
	C(n-1,d,k) ;
	L[n] = 1 ;
	C(n-1,d,k) ;
	L[n] = 0 ;
}

int main()
{
   int n ;
   long long k ;
   scan(n) ;
   scanf("%lld",&k) ;
   
   FOR(i,0,n-1)  scanf("%lld",&a[i]) ;
   FOR(i,0,n-1)  L[i] = 0 ;
   C(n-1,n,k) ;
   
   printf("%lld",c-1) ;
   
  return 0 ;
}

