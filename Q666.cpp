#include<stdio.h>
#include<string.h>

void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

 int main()
 {
	 int d;
	 char str[200]={'\0'};
	 printf("Enter string :");
	 gets(str);
	 printf("Enter d : ");
	 scanf("%d",&d);
	 int len=strlen(str);
	 for(int i=0  ;i<len ; i++ )
	 {
	 	for(int j=i+1 ;j<len;j++ )
	 	{
	 		if(str[i]==str[j])
	 		{
	 		   if(i+d>len)
	 		  {
	 			swap(&str[j],&str[i-d]);
	 	      }
	 	    	else
	 	    	swap(&str[j],&str[i+d]);
	 	    }
	 	}
	 }
	 
	 printf("%s",str);
	 	 return 0 ;
 }
