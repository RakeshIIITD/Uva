#include<conio.h>       /*--------RAKESH-CSE Ist year---------------*/
#include<stdio.h>
int func(int n,int y)   /*------FUNCTION-----*/
{ static int c;
switch(n)
{ case 1: case 3: case 5: case 8: case 10: case 12: c=31; break;
case 2:if(y%4==0)
		 c=29;
else  c=28; break;
case 4: case 6: case 9: case 11: c=30; break;
}
return(c);
}
int main()              /*----MAIN FUNCTON STARTS HERE----*/
{clrscr();
int dt,yr,m,b,r;
int c=0; int d=0;
printf("Enter Date,Month,Year");
scanf("%d%d%d",&dt,&m,&yr);
if(m>12)
{printf("WRONG MONTH ENTERED\n");   return 0;
 }
yr=yr-2000;
if(dt<=func(m,yr))
{
for(int i=1;i<m;i++)
{ c=func(i,yr);
d=d+c;
}
dt=dt+d;
b=yr/4;
r=(365*yr+b+dt)%7;
switch(r)
{ case 0: printf("sat"); break;
  case 1: printf("sun"); break;
  case 2: printf("mon"); break;
  case 3: printf("tue"); break;
  case 4: printf("wed"); break;
  case 5: printf("thu"); break;
  case 6: printf("fri"); break;
  }
}
else
{ printf("WRONG DATE ENTERED"); }
  getch(); }
