
#include<stdio.h>
#include<vector>
#include<sstream>
#include<iostream>
#include<string>

using namespace std ;

vector<int>f_set(10000) ;
vector<int>e_set(10000) ;

void initSet( int size )
{
	f_set.resize(size) ;
	e_set.resize(size) ;
	
	for( int i=0;i<size;i++ )
	{
		f_set[i] = i ;
		e_set[i] = i ;
	}
}

int findSet( int type , int i )
{
	if( type==1 )		return f_set[i]==i?i:f_set[i] = findSet( 1 , f_set[i] ) ;
	else 				return e_set[i]==i?i:e_set[i] = findSet( 0 , e_set[i] ) ;
}

void unionSet( int type , int i ,int j )
{
	i = findSet( type , i ) ;
	j = findSet( type , j ) ;
	
	if( i<j )
	{
		if( type==1 )     f_set[j] = i ;
		else e_set[j] = i ;
	}
	else
	{
		if( type==1 )     f_set[i] = j ;
		else e_set[i] = j ;
	}
	
}

bool isSameSet(int type , int i ,int j)
{
	return findSet(type,i)==findSet(type,j) ;
}

int setFriends( int i , int j )
{
	if ( findSet( 1 , findSet(0,i))!= findSet(1,j))   unionSet(1,i,j) ;
	else return -1 ; 
}

int setEnemies(int i , int j )
{
	if(findSet(0,i)==findSet(0,j)||findSet(1,i)==findSet(1,j))   return -1 ;
	else unionSet( 0 , i , j ) ;
}

bool areFriends( int i , int j )       
{
	if( findSet(1,i)==findSet(1,j)||(( findSet(0,i)==findSet(0,j))&&i!=j ))  return 1 ;
	else return 0 ;
}

bool areEnemies( int i , int j )     
{
	if(findSet(1,i)==findSet(1,j)||((findSet(0,i)==findSet(0,j))&&(i!=findSet(0,i)&&j!=findSet(0,j)))) return 0 ; // counter case remaining
	else if((findSet(1,i)==i&&findSet(1,j)==j)) return 0 ;   // case 8,9 
			else return 1 ;
}

int main()
{
	int number , c , x , y ;
	
	scanf("%d",&number) ;
	initSet(number ) ;
	scanf("%d",&c) ;
	scanf("%d",&x) ;
	scanf("%d",&y) ;
	
	while( c!=0 )
	{
		if(c==1&&setFriends(x,y)==-1)   printf("-1\n") ;
		if(c==2&&setEnemies(x,y)==-1)   printf("-1\n") ;
		if(c==3) printf("%d\n" , areFriends(x,y)) ;
		if(c==4) printf("%d\n" , areEnemies(x,y)) ;
		
		scanf("%d",&c) ;
		scanf("%d",&x) ;
		scanf("%d",&y) ; 
	}
	return 0 ;
}

/* testcases
10
4 4 1
1 6 5
4 2 3
3 1 0
2 5 3
1 2 5
2 9 8
1 8 0
4 9 3
2 3 0
4 7 3
2 4 9
1 4 2
2 6 3
1 6 9
1 2 1
1 7 5
2 1 8
1 3 0
1 7 0
1 2 8
3 5 6
4 2 7
2 0 3
1 6 7
2 4 8
4 4 6
1 9 4
4 2 1
4 3 0

----sol---

0
0
0
0
0
-1
-1
-1
1
0
-1
0
-1
0
1
*/
