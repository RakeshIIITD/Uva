#include<stdio.h>

int main()
 {
 	int c[1025]={0};
 	int a[]={45,222,869,31,56,94};
 	int b[]={435,345,222,45,56};
 	int i=0 , j=0;
 	
 	for(int i=0;i<6;i++)
 	{ if(c[a[i]]==0)
 	    c[a[i]]++;
     }
     
    for(int i = 0 ;i<5 ;i++ )
    {
    	if((c[b[i]]==1)&&(b[i]<1025))  c[b[i]]++;
    }
    
    for(int i =0 ;i<1025 ;i++ )
       if(c[i]==2)  printf("%d\n",i);
    
 	return 0 ;
 }
