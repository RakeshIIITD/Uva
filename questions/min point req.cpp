#include<bits/stdc++.h>

using namespace std ;

int p[3][3] = { {-2, -3,   3}, 
                {-5, -10,  1}, 
                {10,  30, -5} 
              };

int C(int i,int j,int sum)
{
	if(i==3&&j==2||j==3&&i==2)   return 0 ;
	if(i>2||j>2)                 return INT_MAX ;

	int val = sum + p[i][j] ;

	if(val<=0)   return 1 + abs(val) + min( C(i+1,j,1) , C(i,j+1,1) ) ;
	else 		 return min( C(i+1,j,val) , C(i,j+1,val) ) ;
}


int main()
{  
	cout<<C(0,0,0)<<endl ;	
	return 0 ;
}
