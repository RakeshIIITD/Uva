//    Accepted
//   `roCKy FireBirD

#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std ;
int a[50001] = {0} ;
int lower ;
int higher ;

void B(int low ,int high , int query)
{
	if(low>high)    return ;
	int mid = (low+high)/2 ;

	if(mid==lower&&a[mid]>query) 
	{
	  printf("X %d\n",a[mid])   ;
	  return ;
    }
    
	if(mid==higher&&a[mid]<query) 
	{
	   printf("%d X\n",a[mid]) ;
	   return ;
    }
    if(a[mid]==query)
	{
		int left = mid ,right = mid ;
		while(left>=0&&a[left]==query)   left-- ;
		while(right<=higher&&a[right]==query)   right++;
		
		if(left<0&&right>higher)   printf("X X\n");
		else if(left<0)            printf("X %d\n",a[right]) ;
		else if(right>higher)      printf("%d X\n",a[left]) ;
		else  printf("%d %d\n",a[left],a[right]) ;
		return ;
	}
	
	if(mid+1<=higher&&a[mid]<query&&a[mid+1]>query)    // remaining
	{
		printf("%d %d\n",a[mid],a[mid+1]) ;
		return ;
	}
	
	if(mid-1>=0&&a[mid]>query&&a[mid-1]<query)
	{
		printf("%d %d\n",a[mid-1],a[mid]) ;
		return ;
	}

	if(a[mid]>query)   B(low,mid-1,query) ;
	else 			   B(mid+1,high,query) ;
}
//     roCKy `FireBirD
int main()
{
	int n ,q ;
	scanf("%d",&n) ;
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	lower = 0 ;
	higher = n-1 ; 
	scanf("%d",&q) ;
	int query ;
	for(int i=0;i<q;i++)
	{
		scanf("%d",&query) ;
		B(0,n-1,query) ;
	}
	
	return 0 ;
}
