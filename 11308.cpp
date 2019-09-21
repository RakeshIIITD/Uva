//Accepted

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<sstream>
#include<vector>
#include<string>

using namespace std ;

struct T
{
	string recipe ;
	int cost ;
	T(string recipe,int cost):recipe(recipe),cost(cost){
	}
};

bool sortByKey(const T &lhs , const T &rhs)
{
	return lhs.recipe < rhs.recipe ;
}

bool sortByValue(const T &lhs , const T &rhs)
{
	return lhs.cost < rhs.cost ;
}

int main()
{
	int binders ;
	scanf("%d",&binders) ;
	getchar() ;
	while(binders--)
	{   
	    vector<T> v ;
	    map<string,int>price_map ;
	    
		string binder_name , m_n_b ;
		int m,n,b ;
		
		getline(cin,binder_name ) ;             // get binder_name
		getline(cin , m_n_b) ;
		stringstream ss(m_n_b);
		ss>>m ;
		ss>>n;
		ss>>b ;
		
		while(m--)     // for building price index
		{   
		    string str , item ;
		    int price ;
		    
		    getline( cin , str ) ;
		    
		    stringstream ss(str) ;
		    
		    ss>>item ;
		    ss>>price ;
		    price_map[item] = price ;  
		}
		
		while(n--)        	// for recipe names
		{
		  int k ;
		  string recipe ,line, item ;
		  int quantity ,cost = 0  ;

		  getline(cin , recipe ) ;
		  
	 	  scanf("%d",&k) ;
	 	  
	 	  getchar() ;
		  while(k--) 		// for requirement c
		  {
		  	getline(cin , line ) ;

		  	stringstream ss(line) ;
		  	ss>>item ;
		  	ss>>quantity ;
		  	cost = cost + price_map[item]*quantity ;
		  }
		  if((b-cost)>=0)  
		  {
		  //	b = b - cost ;
		  	v.push_back(T(recipe , cost )) ;
		  }
	    }
	    stable_sort(v.begin() , v.end() , sortByKey);
	    stable_sort(v.begin() , v.end() , sortByValue) ;
	    transform(binder_name.begin(), binder_name.end(), binder_name.begin(), ::toupper);
	    printf("%s\n" , binder_name.c_str());
	    
	    if(v.size()==0)   printf("Too expensive!\n") ;
	    else
	    for(int i=0;i<v.size() ; i++ )
	    	printf("%s\n",(v[i].recipe).c_str()) ;
	   if(binders>0) printf("\n");	
	    v.clear() ;
	    price_map.clear() ;
	}
	printf("\n") ;
	return 0 ;
}
