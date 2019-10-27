#include<bits/stdc++.h>

using namespace std ;



int a[] = {0,2,2,3,1} ;



int C(int i,int prev,int n,vector<int> &v)
{
	
	if(prev==0&&i==n) 
	{
		for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
		cout<<endl ;
		return 1 ;
	}

	if(i>=n)    return 0 ;

	int n1 = 0,n2 = 0;

	if(a[prev]*10+a[i]<=26&&a[prev]*10+a[i]>0)         
	{
       v.push_back(a[prev]*10+a[i]) ;
	   n1 = C(i+1,0,n,v) ;
	   v.pop_back() ;
	}

	n2 = C(i+1,i,n,v);

	return n1 + n2 ;
}

int main()
{
	#ifndef ONLINE_JUDGE
  	freopen("input.txt","r",stdin);
  	freopen("output.txt","w",stdout) ;
	#endif   

  	vector<int> v;
	cout<<C(1,0,5,v) ;

	return 0 ;
}