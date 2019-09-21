//prune
//worst test case = 8 8
// 2 3 4 5 0 7
// unable to reach from current path
// if path is blocked then return

#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>

using namespace std ;

int r,c ,x1,y1,x2,y2,x3,y3;
int path ;
int visited[21][21] = {0} ;

void C(int i ,int j , int steps , int total_steps)
{
	if(i<0||i>=r||j<0||j>=c)   return ;
	if(visited[i][j]==1)   return;
	
	if((steps==(int)(total_steps/4))&&(i!=x1||j!=y1))  return ;
	if((steps==(int)(total_steps/2))&&(i!=x2||j!=y2))  return ;
	if((steps==((int)(3*total_steps)/4))&&(i!=x3||j!=y3))  return ;
	if( (i==x1&&j==y1) && (steps!=(int)(total_steps/4)) )  return ;
	if( (i==x2&&j==y2) && (steps!=(int)(total_steps/2)) )  return ;
	if( (i==x3&&j==y3) && (steps!=((int)(3*total_steps)/4)) ) return ;
	//if(visited[x1][y1]==0&&(fabs(x1-i)+fabs(y1-j)))	
	if(i==0&&j==1&&steps==total_steps)  
	{
		path++ ;
		return ;
	}
	
	visited[i][j] = 1 ;
	
	C( i+1 , j , steps+1 , total_steps ) ;
	C( i , j+1 , steps+1 , total_steps ) ;
	C( i-1 , j , steps+1 , total_steps ) ;
	C( i , j-1 , steps+1 , total_steps ) ;
	
	visited[i][j] = 0 ;
}

int main()
{
	int testcase = 0 ;
	
	while(1)
	{
		string line ;
		testcase++ ;
		getline(cin,line) ; 
		
		stringstream ss(line) ;
		ss>>r;
		ss>>c;
		if(r==0)   break ;
		
		string check_points ;
		getline(cin,check_points) ;
		
		stringstream ss2(check_points) ;
		
		ss2>>x1 ;
		ss2>>y1 ;
		ss2>>x2 ;
		ss2>>y2 ;
		ss2>>x3 ;
		ss2>>y3 ;
		path = 0 ;
		C(0,0,1,r*c) ;
		
		printf("Case %d: %d\n",testcase,path) ;
	}
	return 0;
}
