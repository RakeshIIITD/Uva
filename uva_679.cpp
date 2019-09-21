#include<stdio.h>
#include<math.h>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std ;

int max_node ;

int C(int node, int balls)
{
    int left = node * 2, right = left + 1 ;
    
    if (left<max_node && right<max_node)
    {
        if (balls%2==0) 	C(right, balls/2);
        else 				C(left, balls/2 + 1); 
    }
    else return node; 
}

int main()
{
	int testcase ;
	scanf("%d",&testcase) ;
	
	while(testcase--)
	{
		int d , i ;
		scanf("%d%d",&d,&i) ;
		int items = pow(2,d) ;
		max_node = items ;
		printf("%d\n",C(1,i)) ;
	}

	return 0 ;
}
