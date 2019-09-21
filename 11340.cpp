#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{   
   int testcase ;
   scanf("%d",&testcase) ;
   
   while(testcase--)
   {
   	long long sum = 0 ;
   	int a[128]={0};
   	int line ;
   	scanf("%d",&line);
   	getchar();  
   	while(line--)
   	{   string s ;
   		char ch ;
   	    int x ;
		
   		getline(cin,s);
   		stringstream ss(s);
        ss>>ch ;
        ss>>x ;
        a[ch] = x ;
   	}
   	int sentence ;
   	scanf("%d",&sentence ) ;
   	getchar();
   	while(sentence--)
   	{
   		string s ;
   		int i = 0 ;
   		
   		getline(cin,s);
   		
   		while(s[i]!=0)
   		{
   			sum+= a[s[i]] ;
   			i++ ;
   		}
   	}
   	printf("%.2f$\n" , sum/100.0 ) ;
   }
	return 0 ;
}
