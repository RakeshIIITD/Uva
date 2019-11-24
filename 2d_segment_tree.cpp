// Rakesh Singh Rawat
//excludes one y - coordinate
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

vector<vector<int> > arr(20) ;
vector<vector<int> > xtree(2000) ;
int y_size ;


void build_y(int node_x , int start_x , int end_x , int node_y , int start_y , int end_y )
{
	if(start_y==end_y)
	{
		if(start_x==end_x)   xtree[node_x][node_y]=arr[start_x][start_y] ;
		else   				 xtree[node_x][node_y]=xtree[2*node_x][node_y] + xtree[2*node_x+1][node_y] ;
	}
	else
	{
		int mid = (start_y+end_y)/2 ;
		
		build_y(node_x,start_x,end_x,2*node_y , start_y , mid );		 // (starty,mid)
		build_y(node_x,start_x,end_x,2*node_y+1, mid+1 , end_y ) ;		 // (mid+1,end)
		
		xtree[node_x][node_y]=xtree[node_x][2*node_y]+xtree[node_x][2*node_y+1] ;
	}
}

void build_x(int node_x ,int start_x ,int end_x)
{
	if(start_x!=end_x)
	{
		int mid = (start_x+end_x)/2 ;
		build_x(2*node_x,start_x,mid) ;
		build_x(2*node_x+1,mid+1,end_x) ;
	}
	
	build_y(node_x,start_x,end_x,1,1,y_size-1) ;     // buildy(nodex,startx,endx,nodey,starty,endy)
}

int sum_y(int node_x, int node_y, int y_left, int y_right, int start_y, int end_y ) 
{
	if(start_y>y_right||y_left>end_y)	return 0 ;
	
	if(start_y>=y_left&&y_right>= end_y)    return xtree[node_x][node_y] ;
	
	int mid = (start_y+end_y)/2 ;
	
	return ( sum_y(node_x,node_y*2   , y_left , y_right , start_y , mid ) +
	         sum_y(node_x,node_y*2+1 , y_left , y_right ,  mid+1  , end_y) 
	       ) ;
}


int sum_x(int node_x , int start_x, int end_x ,int x_left, int x_right , int start_y , int end_y) 
{
	//cout<<"hi again"<<endl;
	if(start_x>x_right||x_left>end_x)      return 0 ;
	
	if( start_x>=x_left&&x_right>=end_x)  
	{    
	//cout<<"hi again"<<endl;
			return sum_y(node_x,1,start_y,end_y,1,y_size-1) ; //sumy(nodex,nodey,yleft,y_right,starty,endy)
    }
	int mid = (start_x+end_x)/2 ;
	
	return  sum_x(node_x*2 , start_x , mid , x_left , x_right , start_y, end_y )
		   +sum_x(node_x*2+1, mid+1 , end_x ,x_left , x_right , start_y, end_y ) ;
}
		
int main()
{
 	vector<int>v ;
 	y_size=11 ;
	for(int j=0;j<=10;j++ )
	{
 
 		for(int i=0;i<=10;i++)   v.push_back(i) ;
  
  		if(j!=0)                arr[j] = v ;
  
  		v.clear() ;
	}

for(int i=1;i<=10;i++)
{
	for(int j=0;j<=10;j++)
	{
		if(j!=0) cout<<arr[j][i]<<" ";
	}
	cout<<endl ;
}

for(int i=0;i<=20;i++)   xtree[i].resize(200) ;


build_x(0,1,10) ;    // build(nodex , startx , endx )

int x1 , x2 , y1 , y2 ;

	x1 = 2 ;
	x2 = 3 ;
	y1 = 1 ;
	y2 = 9 ;
cout<<sum_x(1,1,10,x1-1,x2,y1,y2) ; 	//sumx( nodex , startx , endx , xleft , xright , starty , endy )
// x1-1 is done because it excludes 2
  return 0 ;
}

