#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std ;

int main()
{
	vector<int> v1 ;
	vector<string> v2 ;
	
	string s, t, str;
	
	int test , ind ;
	cin>>test ;
	
	getchar();
	
	while(test--)
	{
		
		getchar();
        getline(cin,s);
        stringstream ss(s);
        while(ss>>ind) v1.push_back(ind);
        getline(cin,str);
        stringstream sst(str);
        while(sst>>t) v2.push_back(t);
        
	    vector<int>v3(v1.size()+1) ;
	    
	    
	    for(int i=0;i<v1.size() ; i++ ) //hash it
	    {
	    	v3[v1[i]] = i ;
	    }
	    
	    for(int i=1 ;i<=v1.size() ; i++ )
	    {
	    	cout<<v2[v3[i]]<<endl;
	    }
	    v1.clear() ;
	    v2.clear() ;
	    v3.clear() ;
	    if(test)
	      printf("\n") ;
	}
	return 0 ;
}
