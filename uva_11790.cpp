// `roCKy FireBirD
// O(NlogN)
//Not Accepted
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std ;

vector<int>b ;
vector<int>w ;
vector<int>L ;
vector<int>L1 ;
vector<int>a ;

bool cmp(int n,int k)
{
	return n>k ;
}

int findSmallest(int x)
{
	int res =  lower_bound(L.begin(),L.end(),x,cmp)-L.begin() ;	
	return res ;
}
int findLargest(int x)   // log(N) ;
{
	int res =  lower_bound(L.begin(),L.end(),x)-L.begin() ;	
	return res ;
}

int C1(int n)
{
	for(int i=1;i<=n;i++) 
	{
	  L[i] = 999999 ;
	  L1[i] = -999999;
    }
	L[0] = -999999;
 
	int len=-1,flag;
	for( int i=0;i<n;i++ )
	{
	  flag = 0 ;
		int k = findLargest(b[i]) ;
		if(L[k]>=b[i]&&L1[k]<=w[i])
		{
			L[k] = b[i] ;
			L1[k] = w[i] ;
			flag = 1 ;
		}
		if(k>len)  len = k ;
		if(flag) a.push_back(k) ;
		else a.push_back(-1) ;
	}
	return len ;	
}
 
int C2(int n)
{
		for(int i=1;i<=n;i++) 
	{
	  L[i] = -999999 ;
	  L1[i] = -999999;
    }
	L[0] = 999999;
 
	int len=-1, flag;
	
	for( int i=0;i<n;i++ )
	{
	  flag = 0;
		int k = findSmallest(b[i]) ;
		
		if(L[k]<=b[i]&&L1[k]<=w[i])
		{
			L[k] = b[i] ;
			L1[k] = w[i] ;
			flag = 1 ;
		}
		if(k>len)  len = k ;
		if(flag)  a.push_back(k) ;
		else a.push_back(-1) ;
	}
	return len ;
}

int main()
{
	int t ;
	scanf("%d",&t);
	int c = 0 ;
	while(t--)
	{
		c++ ;
		int n ,k ;
		scanf("%d",&n) ;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&k) ;
			b.push_back(k) ;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&k);
			w.push_back(k) ;
		}
		L.resize(n+1) ;
		L1.resize(n+1) ;
		int sum1 = 0 , sum2 = 0 ;
		int len1 = C1(b.size()) ;
		int i = a.size()-1 ;
		a.push_back(999999) ;
		int len ;
		len = len1 ;
		do
		{										// start from downward while decreasing length
			if(a[i]==len&&a[i+1]!=a[i])
			{
			 	sum1+=w[i] ;
			 	len-- ;
	   		}
		i-- ; 
		}while(len!=0) ;
		a.clear() ;
		int len2 = C2(b.size()) ;
		i = a.size()-1 ;
		a.push_back(99999);
		len = len2 ;
		
		do
		{										// start from downward while decreasing length
			if(a[i]==len&&a[i+1]!=a[i])
			{
			 	sum2+=w[i] ;
			 	len-- ;
	   		}
		i-- ; 
		}while(len!=0) ;
		//cout<<sum1<<" "<<sum2<<endl ;
		if(sum1>=sum2)   printf("Case %d. Increasing (%d). Decreasing (%d).\n",c,sum1,sum2);
		else             printf("Case %d. Decreasing (%d). Increasing (%d).\n",c,sum2,sum1) ;
		b.clear() ;
		w.clear() ;
		L.clear() ;
		L1.clear();
		a.clear() ;
	}
 	return 0;
}
