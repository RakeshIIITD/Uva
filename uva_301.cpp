/*
created by : rakesh
26/5/2018
*/
#include<bits/stdc++.h>
using namespace std ;

int s[25],d[25],o[25] ;

int cap,city,orders ;

int C(int i,int a[],int cost)
{


	if(i==orders+1)
	{
		return cost ;
	}

	int n1,n2 ;

	n1 = C(i+1,a,cost);

	n2 = 0;

	int flag = 1 ;
	for(int j=s[i];j<d[i];j++) 
		{	
			if(a[j]-o[i]<0)  
			{
				flag=0;
				break;
			}
		}

	if(flag)
		{
			for(int j=s[i];j<d[i];j++)		a[j] = a[j] - o[i] ;

			n2 = C(i+1 , a , cost + (d[i]-s[i]) * o[i] );

			for(int j=s[i];j<d[i];j++)		a[j] = a[j] + o[i] ;
		}
	else
	{
		//n2 = cost ;
	}
	

	return max(n1,n2) ;
}


int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout) ;
    #endif

	 
    while(1)
    {
    	scanf("%d%d%d",&cap,&city,&orders) ;

    	if(cap==0&&city==0&&orders==0)  break;

    	for(int i=1;i<=orders;i++)
    	{
    		scanf("%d%d%d",&s[i],&d[i],&o[i]);
    	}

    	//cout<<s[2]<<" "<<d[2]<<endl;
    	int a[8];

    	for(int i=0;i<8;i++) a[i] = cap ;

    	printf("%d\n",C(1,a,0));
    }

    return 0 ;
}