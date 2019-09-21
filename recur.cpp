#include<stdio.h>
#define UNKNOWN -1
int q;
int L[9];
int max(int a,int b)
{printf(" max called\n");
if(a>b) return a;
else return b;
}
int best(int*,int);
int main()
{int p[]={0,1,5,8,9,10,17,17,20};
for(int i=0;i<=9;i++)
L[i]=UNKNOWN;
printf("%d",best(p,4));
return 0;
}
int best(int *p,int n)
{if(L[n]>=UNKNOWN+1)   return L[n];
if(n==0)
q=0;
else q=UNKNOWN;
for(int i=1;i<=n;i++)
{
q=max(q,p[i]+best(p,n-i));
}
L[n]=q;
return q;
}
