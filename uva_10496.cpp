/*
created by : rakesh
26/5/2018
*/

#include<bits/stdc++.h>
using namespace std ;

int a[21][21] = {0} ;
int beepers,x,y;

int C(int i,int j , int count , int collect)
{

	int n1,n2,n3,n4 ;

	if(collect==beepers&&a[i][j]==4)  return count-1 ;

    if(i>x||j>y||i<1||j<1||a[i][j]==1||a[i][j]==5)  return 9999 ;


	if(a[i][j]==2)
	{
		collect = collect+1 ;
		a[i][j] = 5 ;
	}

	else a[i][j] = 1 ;           //visited

	n1 = C(i+1, j , count+1 , collect) ;
	n2 = C(i, j+1 , count+1 , collect) ;
	n3 = C(i-1, j , count+1 , collect) ;
	n4 = C(i, j-1 , count+1 , collect) ;
/*------------------------------------------------------------*/

	if(a[i][j]==5)
	{
		collect = collect-1 ;
		a[i][j] = 2 ;
	}

	else if(a[i][j]==1) a[i][j] = 0 ;      // backtrack


	return min(n1,min(n2,min(n3,n4))) ;
}

int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout) ;
    #endif

    int testcase ;

    scanf("%d",&testcase);

    int s1,s2,n,u,v ;

    while(testcase--)
    {

    	scanf("%d%d",&x,&y);

    	cout<<x<<" "<<y<<endl ;
    	for(int i=0;i<=x;i++)
    	{
    		for(int j=0;j<=y;j++)
    		{
    			a[i][j] = 0 ;
    		}
    	}
		scanf("%d%d",&s1,&s2);

		scanf("%d",&n);

		beepers = n ;
		cout<<n<<endl ;

		for(int i=0;i<n;i++) 
			{
				scanf("%d%d",&u,&v);
				a[u][v] = 2 ;
			}

			a[s1][s2] = 4 ;

			cout<<C(s1,s2 , 0 , 0 );

    }

	return 0;
}