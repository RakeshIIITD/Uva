// some test cases are remaining

#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>

using namespace std ;

struct T
{
	string s ;
	int n ;
	T(string s ,int n):s(s),n(n){
	}
};

bool sortByValue(const T &lhs ,const T &rhs)
{
	return lhs.n>rhs.n ;
}
int main()
{   
    
    int t = 0 ;
	while(1)
	{
		map<string,string>m;
		string  str1,str2 ,ve="";
		
	    getline(cin,str1) ;
	    
	    if(str1[0]=='0') break ;
	    
		while(1)
		{   
	    	if(str1=="") getline(cin,str1) ;
		
			if((str1[0]=='1')^(isupper(str1[0])&&isupper(ve[0])))    // problem
			{
			 	if(isupper(str2[0]))
				 { 
				    int t1 = t ;
				    stringstream out ;
				    out<<t1 ;
				    string st = "zero" + out.str() ;
				    t++ ;
				    m[st] = str2 ;
			     	break ;
			     }
		    }
		
			if(isupper(str1[0]))
			{
				str2 = str1 ;
			}
		    else 
			{
		  		if( m.find(str1)!= m.end())
		  		{
		  		   if( m[str1]!=str2 )  m[str1] ="nuLLV" ;
		  		   // else do nothing
		  	    }
		  		else m[str1] = str2 ;
	    	}
	    	ve = str1 ;
	     str1="" ;
	    }
	   
	   map<string,int>m2 ;
	   map<string,string>::iterator it ;
	   
	   for(it = m.begin() ; it!=m.end() ; it++ )
	   {
	   	    if(it->second == "nuLLV" )  m.erase(it->first) ;
	   }
	   
	   for( it = m.begin() ; it!=m.end() ; it++ )
	   {
	   			  m2[it->second] = 0 ;
	   }
	   
	   for( it = m.begin() ; it!=m.end() ; it++)
	   {    
	        string q = it->first;
	        q = q.substr(0,4) ;
	   		if(q!="zero") m2[it->second]++ ;
	   }
	   
	   m.clear() ;
	   map<string,int>::iterator iter ;
	   
	   vector<T>v ;
	   
	   for(iter = m2.begin() ; iter!=m2.end() ; iter++ )
	   {
	   	v.push_back(T(iter->first , iter->second )) ;
	   }
	   
	   m2.clear() ;
	   
	   stable_sort(v.begin(),v.end(),sortByValue) ;
	   
	   for(int i=0 ; i<v.size() ; i++ )
	   {
	   	if(v[i].s!="nuLLV")                            // not needed
	   	printf("%s %d\n",v[i].s.c_str() ,v[i].n ) ;
	   }
	   v.clear() ;
    }
	return 0 ;
}
