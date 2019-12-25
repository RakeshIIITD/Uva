#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

vector<int> pset ;
vector<int> _size;
vector<int> _sum ;

int init(int n)
{
	for(int i=0;i<n;i++) 
	{
	 _size.push_back(1) ;
	 pset.push_back(i);
	}

}

int findSet(int i) { return pset[i]==i?i:pset[i] = findSet(pset[i]) ; }

void unionSet(int i,int j)
{ 
    i = findSet(i) ;
    j = findSet(j) ;
    
    if(i!=j)
    {
        if(_size[j]>_size[i])
        {
            pset[i] = j ;
            _size[j]+= _size[i] ;
            _sum[j]+= _sum[i] ;
        }
        else
        {
            pset[j] = i ;
            _size[i]+= _size[j] ;
            _sum[i]+=_sum[j] ;
        }
    }
    
}

int main()
{


	int testcase,n,m, temp,u,v ;

	cin>>testcase ;
	//cout<<testcase ;
	while(testcase--)
	{
		cin>>n>>m;

		for(int i=0;i<n;i++)
		{
			cin>>temp ;
			_sum.push_back(temp) ;
		}
		init(n) ;

		for(int i=0;i<m;i++)
		{
			cin>>u>>v;

			unionSet(u,v) ;
		}
		int flg = 1 ;

		for(int i=0;i<n;i++)
		{
			if(_sum[findSet(i)]!=0)
			{
				flg = 0 ;
				cout<<"IMPOSSIBLE"<<endl;
				break;
			}
		}
		if(flg)  cout<<"POSSIBLE"<<endl;

		pset.clear() ;
		_size.clear() ;
		_sum.clear() ;

	}

	return 0 ;
}