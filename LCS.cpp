#include<stdio.h>
int L[8][7];

int max(int a,int b)
 {
  return (a>b?a:b);
 }

int LCS(int,int);

char a[]={'A','B','C','B','D','A','B'};
char b[]={'B','D','C','A','B','A'};

int main()
 {
	for(int i=0;i<8;i++)      //memo
	for(int j=0;j<7;i++)
	L[i][j]=0;
	printf("%d",LCS(8,7));
	return 0;
 } 

int LCS(int m,int n)
 {
	for(int i=0;i<m;i++)
	for(int j=0;j<n;j++) 
	{  if(a[i]==b[j])
	     L[i][j]=1+L[i-1][j-1];
	
	   if(a[i-1]!=b[j-1])
		 L[i][j] = max( L[i-1][j] , L[i][j-1] );
		
	}
    for(int i=1;i<m;i++)
	{
	for(int j=1;j<n;j++)
	printf("%d  ",L[i][j]);
    printf("\n");
	}
 }
