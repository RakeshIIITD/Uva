#include<bits/stdc++.h>

using namespace std ;

int a[10010] ;


int miN(int x,int y)
{
	return x>y?y:x ;
}

int j = 0;
int prev = 9999 ;

;
int C(int K , int i , int n,int c[],int s[])
{
	if( i==n )   
	{
		if(K<prev)
		{
			for(int i=0;c[i]!=0;i++)  s[i] = c[i] ;
			prev = K;
		}
	  return K;
	}
	int n1 = C(K,i+1,n,c,s) ;
	int n2 = 99999;

	if(K-a[i]>=0)  
	{
	  c[j++] =a[i];
	  n2 = C(K-a[i],i+1,n,c,s) ;
	  c[--j] = 0 ;
	}

	return min(  n1,n2 ) ;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif
    int n ;
    int t ;

    while(scanf("%d",&t)>0)
    {
    	scanf("%d",&n) ;


    	int c[1005] = {0} ;
    	int s[1010] ={0} ;
    	prev = 9999;
    	for(int i=0;i<n;i++)    scanf("%d",&a[i]) ;

    		j=0;
    		printf("%d\n",t-C(t,0,n,c,s));

    		for(int i=0;s[i]!=0;i++) { cout<<s[i]<<" ";}
    }

	return 0 ;
}