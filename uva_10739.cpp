// `roCKy FireBirD

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
string str ;
int L[1005][1005] ;
int C(int i,int j)
{
	if(i>j)   return 0 ;
	if(str[i]==str[j])    return C(i+1,j-1) ;
 	if(L[i][j]!=0)   return L[i][j] ;
	
	if(str[i]!=str[j])
	 L[i][j] = min(1+C(i+1,j-1),1+min(C(i+1,j),1+C(i,j-1))) ;
	return L[i][j] ;
}
int main()
{
	int t ;
	scan(t);
	ln;
	while(t--)
	{
		RESET(L,0) ;
		getline(cin,str);
		printf("%d\n",C(0,str.size()-1)) ;
	}
	return 0 ;
}

