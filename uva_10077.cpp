//Accepted

#include<iostream>
#include<stdio.h>

using namespace std ;

void C(int ln,int ld , int rn , int rd , int en , int ed)
{
	int mn = ln+rn , md = rd+ld ;
	if(mn==en&&md==ed)    return ;
	
	if(((double)mn/md)<((double)en/ed))  
	{
	  printf("R") ;
	  C(mn,md,rn,rd,en,ed) ;
    }
    else
    {
    	printf("L") ;
      C(ln,ld,mn,md,en,ed) ;
    }
}
int main()
{
	int n , d ;
	while(1)
	{
		scanf("%d %d",&n,&d) ;
		if(n==1&&d==1)   break ;
		C(0,1,1,0,n,d);
		printf("\n") ;
	}
	
	return 0 ;
}
