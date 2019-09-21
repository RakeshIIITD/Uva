#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>

using namespace std; 

struct T
{
	string name ;
	int attack ;
	int defend ;
	T(string name ,int attack ,int defend):name(name),attack(attack),defend(defend){
	}
} ;

bool sortByName(const T &lhs , const T &rhs)
{
	return lhs.name<rhs.name ;
}

bool sortByAttack(const T &lhs , const T &rhs)
{
	return lhs.attack>rhs.attack ;
}

bool sortByDefend(const T &lhs , const T &rhs)
{
	return lhs.defend<rhs.defend ;
}

int main()
{
	int t ;
	int testcase=0 ; 
	
	scanf("%d",&t) ;
	
	while(t--)
	{
		testcase++ ;
		int a,d ;
		vector<T>v ;
		set<string>attackers ;
		set<string>defenders ;
		string name ;
		for(int i=0;i<10;i++)
		{
			cin>>name ;
			cin>>a>>d ;
			v.push_back(T(name,a,d)) ;
		}
		
		stable_sort(v.begin() , v.end() , sortByName ) ;
		stable_sort(v.begin() , v.end() , sortByDefend ) ;
		stable_sort(v.begin() , v.end() , sortByAttack) ;
		
		
		for(int i=0;i<5 ; i++)
		{
			attackers.insert(v[i].name) ;
		}
		for(int i=5;i<10 ; i++)
		{
			defenders.insert(v[i].name) ;
		}
		
		set<string>::iterator it = attackers.begin() ;
		
		printf("Case %d:\n(",testcase) ;
		
		int i = 0 ;
		while(i!=5)
		{
			cout<<(*it) ;
			if(i!=4)  cout<<", " ;
			i++ ;
			it++ ;
		}
		set<string>::iterator itr = defenders.begin() ;
		printf(")\n(") ;
		while(i)
		{
			cout<<(*itr) ;
			if(i!=1)  cout<<", " ;
			i-- ;
			itr++ ;
		}
		printf(")\n") ;
		v.clear() ;
	}
	return  0 ;
}
