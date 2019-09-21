/*
created by : rakesh
26/5/2018
*/
#include<bits/stdc++.h>
#include<string>
using namespace std ;

int t,n;
int a[110] ;
int j ;
int flag ;

set<string > s;
void C(int i,int W,vector<int> v)
{
	if(W==0&&i==n)
	{
		flag = 0 ;
		ostringstream sstr ;
		string st ="";
		for(int k=0;k<v.size();k++)
		{
			sstr<<v[k] ;

		 st = st+sstr.str();
		}
		if(s.find(st)==s.end())
		{
		for(int k=0;k<v.size();k++)
		{
			printf("%d",v[k]);
			if(v.size()!=k+1)  printf("+");
		}

		s.insert(st);
		printf("\n");
		}
		return ;
	}

	if(i>n)  return ;
	
	if(W-a[i]>=0)
	{
		v.push_back(a[i]) ;
	    C(i+1,W-a[i],v) ;
		v.pop_back() ;
	}
    C(i+1,W,v);
}

int main()
{

	 #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout) ;
    #endif


    while(1)
    {
    	scanf("%d%d",&t,&n);

    	if(t==0&&n==0)   break ;
    	vector<int> v;

    	for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    	
    	j=0;
    	flag = 1;
    	
    	printf("Sums of %d:\n",t);
    		C(0,t,v);
    	s.clear();
    	if(flag)  printf("NONE\n");

    }
	return 0 ;
}