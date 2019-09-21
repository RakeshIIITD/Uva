
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<math.h>
#include<algorithm>
#include<string>

using namespace std ;

int main()
{
	int t ;
	scanf("%d",&t);
	
	while(t--)
	{
		int posx,posy ;
		scanf("%d%d",&posx,&posy);
		
		int a[9] ={0,1,2,3,4,5,6,7,8} ;
		int temp[9] = {0} ;
		a[posx] = posy ;
		a[posy] = posx ;
		
		int j = 1 ;
		for(int i=1;i<=8;i++)
		{
			if(i!=posx)     temp[j++]=a[i] ;
		}
		
		sort(temp+1,temp+8);
		j=1;
		for(int i=1;i<=8;i++)
		{
			if(i==posx)
			{
				i++ ;
			}
			else
			{
				a[i] = temp[j++] ;
			}
		}
		int testcase = 0 ;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		do
		{
			int flag = 0 ;
			if(a[posx]==posy)
				{
			
					for(int i=1 ; i<=8;i++)
					{
						for(int j=1;j<=8;j++)
						{
							if(i!=j)
							if((fabs(i-j)==fabs(a[i]-a[j])))
							flag++ ;
						}
					}	
					if(!flag)
					{
						testcase++ ;
						printf(" %d      ",testcase) ;
						for(int i = 1 ; i<=8;i++) 
						{
				 			 printf("%d",a[i]) ;
				  			if(i!=8)   printf(" ");
			   			}
						printf("\n") ;
						
					}
				}
	    }while(next_permutation(a+1,a+9)) ;
	    if(t>0) printf("\n"); 
	}
	return 0 ;
}
