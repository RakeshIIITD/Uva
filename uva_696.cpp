#include<bits/stdc++.h>
#include<string>

using namespace std ;


int main()
{
	// #ifndef ONLINE_JUDGE
 //  freopen("input.txt","r",stdin);
 //  freopen("output.txt","w",stdout) ;
	// #endif  

	int ans,m,n ,res;

  	while(1)
  	{


  		cin>>m>>n;

  		if(m==0&&n==0)  break ;
  		if(m==0 or n==0) ans = 0 ;
		else
  		if(m==1||n==1)   ans = max(m,n);
  		else 
  		if(m==2 or n==2)
  		{ 
  			res = max(m,n);
  			if(m==1 or n==1)  ans = 2 ;
  			else
  			{

  				if(res%2)   ans = res+1 ;
  				else
  				{
  					ans = res + (res%4) ;
  				}
  			}
  		}
  		else ans = (m*n+1)/2 ;

  			cout<<ans<<" knights may be placed on a "<<m<<" row "<<n<<" column board."<<endl;
  	}

	return 0 ;
}