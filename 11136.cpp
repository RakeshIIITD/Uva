//Accepted
#include<stdio.h>
#include<iostream>
#include<set>
#include<sstream>
#include<string>

using namespace std ;

int main()
{
	while(1)
	{
		int testcase ;
		scanf("%d",&testcase) ;
		if(testcase==0) break;
	//	getchar() ;
		
		multiset<int>m ;
		long sum = 0 ;
		while(testcase--)
		{
			//multiset<int>::iterator it ;
			int t ,i , begin , end ;
			//string line ;
			int n ;
			
			scanf("%d",&t) ;
		//	cout<<"given"<<endl ;
			
			for(i=0;i<t;i++)  
			{
			   scanf("%d",&n);
			   m.insert(n);
		    }
			
			begin = *(m.begin()) ;
			end = *(--m.end()) ;
			m.erase(m.begin()) ;
			m.erase(--m.end()) ;
			sum+= (end - begin ) ;
		}
		printf("%ld\n",sum);
		m.clear() ;
	}
	return 0;
}
