// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std ;
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)

int gcd(int a ,int b) { 	return (b==0?a:gcd(b,a%b)) ; }

int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
int main()
{
	cout<<gcd(315,990);
	return 0 ;
}

