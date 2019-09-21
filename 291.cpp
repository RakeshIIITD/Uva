// Correct Backtracking code

#include<stdio.h>
#include<iostream>

using namespace std ;

bool a[5][5] = {{0,1,1,0,1} , {1,0,1,0,1},{1,1,0,1,1},{0,0,1,0,1},{1,1,1,1,0}} ;
bool m[5][5] = {0} ;	 	// to mark visited
int sol[9] = {0} ;

void backtrack(int i , int count )
{
	if(count==8)
	{
		printf("1");
		for(int k = 0 ; k<8 ; k++) 
			printf("%d",sol[k]) ;
		printf("\n") ;
		return  ;
	}
	
	for(int j = 0; j<5 ; j++ )
	{
		if(a[i][j]==1&&!m[i][j])
		{
			m[i][j] = 1 ;
			m[j][i] = 1 ;
			sol[count] = j+1 ;
			backtrack( j , count+1 ) ;
			m[i][j] = 0 ;			// backtracking steps ,,  moving one step back and recollecting value of i
			m[j][i] = 0 ;
		}
	}
	
}

int main()
{
	
	backtrack(0, 0) ;
	return  0;
}
