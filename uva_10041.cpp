// Rakesh Singh Rawat
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<map>
#include<math.h>
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
void random_shuffle(int arr[],int n)
{
    srand(time(NULL));
    int i, j, temp;
    for (i = n - 1; i > 0; i--)
    {
        j = rand()%(i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
 
void swap(int a[] , int i ,int j)
{
	int temp ;
	temp = a[i] ;
	a[i] = a[j] ;
	a[j] = temp ;
}

int partition(int a[] , int low ,int high )
{
	int pivot , i , j ;
	i = low-1 ;
	
	pivot = a[high] ;
	for(j = low ; j<=high ; j++ )
	{
		if(a[j]<=pivot)
		{
			i++ ;
			swap(a,i,j) ;
		}
	}	
	return i ;
}

int random_select(int a[] , int low ,int high ,int i)
{
	if(low==high)   return a[low] ;
	int q = partition(a,low,high) ;
	
	if(i==q)  return a[i] ;
	else {
		if(i<q)   return random_select(a , low , q-1 , i ) ;
		else      return random_select(a , q+1 , high , i) ;
	}
}

int main()
{
  int t ;
  scan(t) ;
  int a[505] ;
  
  while(t--)
  {
  	int n , med ;
  	scan(n);
  	long long sum = 0;
  	
  	FOR(i,0,n-1)  scan(a[i]) ;
  	
  	random_shuffle(a,n) ;
  	
    med = random_select(a,0,n-1,(n-1)/2) ;
    
    FOR(i,0,n-1)   sum+=fabs(a[i]-med) ;
     
   	printf("%lld\n",sum);
  }

  return 0 ;
}

