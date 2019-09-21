// `roCKy FireBirD
//faulty
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<limits.h>
#include<set>
#include<map>
#include<vector>

using namespace std ;
vector<int>v ;
vector<int>L ;
vector<int>a ;

int findLargest(int x)   // log(N) ;
{
	int res =  lower_bound(L.begin(),L.end(),x)-L.begin() ;	
	return res ;
}
 
int C(int n)
{
	for(int i=0;i<=n;i++) 
	{
	  L.push_back(INT_MAX) ;
    }
	L[0] = INT_MIN;
 
	int len=-1;
	for(int i=0;i<n;i++)
	{
		int k = findLargest(v[i]) ;
		if(L[k]>v[i])
		{
			L[k] = v[i] ;
		}
		if(k>len)  len = k ;
		a.push_back(k) ;
	}
	return len ;	
}
 
int main()
{
	int n ;
	int testcase ;
	scanf("%d\n",&testcase) ;
	while(testcase--)
	{
		scanf("\n");
		string str ;
		while(getline(cin,str))
		{
			if(str.empty())   break ;
			stringstream ss(str) ;
			ss>>n ;
			//cout<<n<<endl ;
			v.push_back(n) ;
		}
		int len = C(v.size()) ;
		printf("Max hits: %d\n",len) ;
		int i = 0 ;
		int c = 1 ;
		vector<int>b(len) ;
		do
		{										// start from downward while decreasing length
			if(a[i]==len)
			{
				 b[len-1] = v[i] ;
				 len-- ;
	    	}
			i-- ; 
		}while(len!=0) ;
	
		for(int i=0;i<b.size() ; i++)
		printf("%d\n",b[i]) ;
		
		v.clear() ;
		L.clear() ;
		a.clear() ;
		b.clear() ;
		
		if(testcase)   printf("\n") ;
	}
 	return 0;
}

