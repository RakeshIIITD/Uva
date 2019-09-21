#include <stdio.h>
#include<string.h>
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {  int i,len,j,n;
    char str[100][100];
    scanf("%d",&n);
   for(i=0;i<n;i++)
   scanf("%s",&str[i][0]);
   for(i=0;i<n;i++)
   { len = strlen(&str[i][0]);
   	for(j=0;j<len;j++)
   	{  switch(str[i][j])
   	    { case 'a': case 'b' : case 'c': printf("2"); break;
   	      case 'd': case 'e' : case 'f': printf("3"); break;
   	      case 'g': case 'h' : case 'i': printf("4"); break;
   	      case 'j': case 'k' : case 'l': printf("5"); break;
   	      case 'm': case 'n' : case 'o': printf("6"); break;
   	      case 'p': case 'q' : case 'r': case 's': printf("7"); break;
   	      case 't': case 'u' : case 'v': printf("8"); break;
   	      case 'w': case 'x' : case 'y': case 'z': printf("9"); break;
   	       }         //end of switch
   		
   	}
   	printf("\n");
   }
   	
   }
    return 0;
}

