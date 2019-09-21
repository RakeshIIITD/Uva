#include<bits/stdc++.h>

using namespace std;

int size ;
/*   Program to construct heap  */

void swap(int a[],int i,int j)
{
	int temp = a[i] ;
	a[i] = a[j] ;
	a[j] = temp ;
}

void max_heapify(int a[],int i,int n)
{
	if(i<n)
	{
		int left = 2*i+1 ;
		int right = 2*i+2 ;
		int tmp ,largest ;

		if(a[left]>a[i])  largest = left ;
		else              largest = i ;

		if(a[right]>a[largest])  largest = right ;

		if(largest!=i)
		{
			swap(a,i,largest) ;

			max_heapify(a,largest,n) ;
		} 
	}
}


void build_heap(int a[],int size)
{
	for(int i=size/2;i>=0;i--)				// check upper bound
	{
		max_heapify(a,i,size) ;
	}
}


void heapsort(int a[],int n)
{
	for(int i=n-1;i>=0;i--)
	{
		swap(a,1,i) ;
		n--;
		max_heapify(a,1,n) ;
	}
}

int extract_max(int a[])
{
	int max = a[1] ;

	a[1] = a[size-1] ;
	size-- ;

	max_heapify(a,1,size) ;

	return max ;
}

void insert(int a[],int key)
{
	a[size] = key ;
    size = size+1 ;

    int i = size-1 ;

    while(i>=0 && a[i/2]<a[i])
    {
    	swap(a[],i/2,i) ;
    	i = i/2 ;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin) ;
	freopen("output.txt","w",stdout) ;
	#endif
	
	int a , b ,c ;

	cin>>a>>b>>c;

	cout<<a*b<<"  :  "<<c<<endl ;

	return 0 ;
}