#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<math.h>

using namespace std;

int main()
{
	double p,q,r,s,t,u ;
	
	while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)!=EOF)
	{
		
		double a=0,b=1 ;
		double f1 , f2 ,f3 , x = 1 ;
		double prev_x = 0 ;
		int flag = 0 ;
		f1 = p*exp(-a)+q*sin(a) + r*cos(a) + s*tan(a) + t*a*a + u ;
		f2 = p*exp(-b)+q*sin(b) + r*cos(b) + s*tan(b) + t*b*b + u ;
		
		if(f1*f2>0)   
			{
				flag++ ;
			}
		while(!flag)
		{
			f1 = p*exp(-a)+q*sin(a) + r*cos(a) + s*tan(a) + t*a*a + u ;
			
			x = (a+b)/2.0 ;
			if(fabs(prev_x-x)<1e-6)   break ;
			
			f3 = p*exp(-x)+q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u ;
			
			if(f1*f3<=0)   b=x ;
			else 			a = x ;
			prev_x = x ;
		
	    }
	    if(flag)    printf("No solution\n");
	    else             printf("%.4lf\n",x) ;
	}
	return 0 ;
}
