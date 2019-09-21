//not completed yet
#include<stdio.h>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<algorithm>

using namespace std ;

struct T
{
	string e1 ;
	set<string>e2 ;
	
	T(string e1,set<string>e2):e1(e1),e2(e2)
	{
	}
};

bool sortByKey(const T &lhs ,const T &rhs)
{
	return lhs.e1<rhs.e1 ;
}


bool sortByValue(const T &lhs ,const T &rhs)
{
	return lhs.e2>rhs.e2 ;
}

int main()
{
		vector<T>v ;
		getchar() ;
		while(1)
		{   
		    
			string str ;
		    getline(cin , str ) ;
		    
		    if(str[0]=='0') break;
		    
		    set<string>s ;
		    getchar() ;
		    if(isupper(str[0]))
		    while(1)
			{
				string str2 ;
				getline( cin , str2 ) ;
				if(isupper(str2[0])||str2[0]=='1')
				{
					v.push_back(T(str,s)) ;
					continue ;		
				}
				if(str2[0]=='1')  break ;
				s.insert(str2) ;
			}
			set<string>::iterator itr ;
			
			for(int i=0;i<v.size();i++)
			{
				for(itr = v[i].e2.begin() ; itr!=v[i].e2.end() ; itr++ )
				{
					if(s.find(*itr)!=s.end())
					 {
					  s.erase(*itr) ;
					  v[i].e2.erase(*itr) ;
				     }
				}
				v.push_back(T(str,s)) ;
			}
			
			sort(v.begin(),v.end(),sortByKey) ;
			sort(v.begin(),v.end(),sortByValue) ;
			
			for(int i=0;i<v.size() ;i++ )
			{
				printf("%s %d\n",v[i].e1.c_str(), v[i].e2.size()) ;
			}		    
		    
	   }
	return 0 ;
}
