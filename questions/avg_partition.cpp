#include<bits/stdc++.h>

using namespace std ;



int a[] = {1,2,3,4,5,6,7 } ;

float max_(float a,float b)
{
	return a>b?a:b ;
}

float C(int i,int sum,int k,int K)
{
	if(i<0&&k==0&&K==0)   return 0;
	if(i<0)         return -99999 ;

	float n1 = -999; 

	 n1 = ((sum+a[i])/((k+1)*1.0))+C(i-1,0,0) ;

	return max_( n1 , C(i-1,sum+a[i],k+1)) ;

}

int main()
{
	#ifndef ONLINE_JUDGE
  	freopen("input.txt","r",stdin);
  	freopen("output.txt","w",stdout) ;
	#endif   

  	vector<int> v;
	cout<<C(6,0,0) ;

	return 0 ;
}