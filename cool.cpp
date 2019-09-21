
#include<stdio.h>

int cool(int n)
{
 int i, k, andmask,count ;
 int c=0;
 count=0;
 for ( i = 31 ; i >= 0 ; i-- )
 { 
 andmask = 1 << i ;
 k = n & andmask ;
        if(c==0&&k==1)  c++;
        if(c==1&&k==0)  c++;
        else if(c==1&&k!=1)  c=0;
        if(c==2&&k==1)
        { c=1;
          count++;
        }
        else if(c==2&&k!=1) c=0;
 }
return count ;
}

int main()
{
	int testcase ,count=0;
	scanf("%d",&testcase);
	while(testcase--)
	{
		int n,r;
		count=0;
		scanf("%d%d",&n,&r);
		for(int i=1;i<=n;i++)
		{
			if(cool(i)>=r)
			count++;
		}
		printf("%d\n",count);
	}
	return 0 ;
}
