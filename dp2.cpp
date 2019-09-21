#include<bits/stdc++.h>
// longest repeated subsequence
using namespace std;
int L[1000] = {0} ;

int C(int a[],int n,int bit,int j)
{
		
	//	if(j==n)   return 0 ;
		int p = 0	 ;
		for(int i=j+1;i<n;i++)
		{
			if(!bit&&a[i]>a[j])
			{
				 p =max(p , a[i]+C(a,n,bit,i)) ;
			}

			else if(!bit&&a[i]<a[j])
			{
				p = max(p , a[i]+C(a,n,!bit,i)) ;
			}

			else if(bit&&a[i]<a[j])
			{
				p = max(p , a[i]+ C(a,n,bit,i));
			}
		}


		return p ;
}



int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout) ;
  #endif 
  int b[] = {80, 60, 30, 40, 20, 10} ;
  int a[] = {1, 15, 51, 45, 33, 100, 12, 18, 9} ;
  int n = sizeof(a)/sizeof(int);
  

  	cout<<C(a,n,0,0);
	return 0;
}