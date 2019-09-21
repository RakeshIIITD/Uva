// Rakesh Singh Rawat
// Title - Chef and his daily routine
// Problem -CHEFROUT
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std ;
//================================================================================
#define INF 100000000
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)					// for
#define LL signed long long int
#define fre 	freopen("0.in","r",stdin);freopen("0.out","w",stdout)
#define print(x) printf("%d\n",x)											//printf
#define printll(x) printf("%lld\n",x)
#define scanll(x) scanf("%lld",&x)
#define scan(x) scanf("%d",&x)												// scanf
#define ln  scanf("\n")														//consume \n
#define SS(a) stringstream ss(a)
#define ii pair<int,int>
#define F first
#define S second
#define abs(x) ((x)>0?(x):-(x))
#define RESET(arr,val) memset(arr, val, sizeof(arr))
#define ret return
#define ITERM(v) for(map<int,int>::iterator it = v.begin() ; it!=v.end() ; it++ )
#define ITERV(v)  for(vector<int>::iterator it = v.begin() ; it!=v.end() ; it++ )
#define VPUSH(v,b) v.push_back(b)												// push_back()
#define VI vector<int>
//=================================================================================

int main()
{
 int testcase ;
 cin>>testcase ;
 char act[] = {'C','E','S'} ;
 
 while(testcase--)
 {
 	string str ;
 	cin>>str ;
 	char c ;
 	int j=0,i=0;
 	int flag = 0 ;
 	
 	while(i<=str.size()-1)					// run till end of string is reached
 	{
 		 c = act[j] ;					
 		 	
 		if(str[i]!=c)   j++ ;				// if characters do not match then slide the 'j'
 		else			i++ ;				//  else increase the 'i'
 		
 		if(j>2)  							// if it exceeds activity array length
 		{
 			flag = 1 ;
 			break ;
 		}
 	}
 	
 	if(!flag) 		printf("yes\n") ;
 	else 			printf("no\n") ;
 	
 }

  return 0 ;
}

