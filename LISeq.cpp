//dynamic programming
// Longest increasing Subsequence - Partial Solution
#include <stdio.h>
#include<malloc.h>
int main() {
    int i;
    int a[]={9,100,22,23,1,2,24};
    int L[9]={0};
        L[0]=1;
    for(i=0;i<9;i++)
        for(int j=i+1;j<9;j++)
        {  
		 if((a[i]<a[j])&&(L[i]>L[j])) 
            L[j]=L[i]+1;
        }
    printf("%d",L[8]);    
    return 0;
}
