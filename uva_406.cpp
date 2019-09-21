// `roCKy FireBirD

// Sieve of eratosthenes - Complexity O(Nloglog(N))
// Prime Factors

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
#include<bitset>

using namespace std ;
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)
typedef long long ll ;
typedef vector<int> vi ;

bitset<1010>bs ;
vi primes ;
ll sieve_size ;
void sieve(ll upperbound)
{
	sieve_size = upperbound+1 ;
	bs.reset() ;
	bs.flip() ;
	bs.set(0,false) ; // 0 - not prime
	bs.set(1,false) ; // 1 - prime
	
	for(ll i = 2 ; i<=sieve_size ; i++ )
	{
		if(bs.test((size_t)i))
		{
			for(ll j =i*i ; j<=sieve_size ; j+=i)
			{
				bs.set((size_t)j,false) ;
			}
			primes.push_back((int)i) ;   // push back prime numbers
		}
	}
}

bool isPrime(ll N)
{
	if(N<sieve_size)  return bs.test((size_t)N) ;
	FOR(i,0,primes.size()-1)
	if(N%primes[i]==0)   return false ;
	return true ;
}

int main()
{
	sieve(1000) ;
	int n,d,C ,mid;
	while(scanf("%d %d",&n,&d)!=EOF)
	{
		int count = 0 ;
		for(int i=0;primes[i]<n ; i++ )   count++ ;
		
		if(count%2!=0)
		{
			mid = (int)(count/2)+1 ;
			printf("%d %d:",n,d) ;
			for(int i=mid-d+1;i<=mid ; i++)
			{
				printf("%d ",primes[i]) ;
			}
			for(int i=mid+1 ; i<=mid+d-1 ; i++)
				if(i!=mid+d-1) printf("%d ",primes[i]) ;
				else printf("%d\n",primes[i]) ;
		}
		else
		{
			mid = (int)(count/2)+1 ;
			printf("%d %d:",n,d) ;
			for(int i=mid-d+1 ; i<=mid ; i++)
			{
				printf("%d ",primes[i]) ;
			}
			for(int i=mid+1 ; i<=mid+d-1 ; i++)
				if(i!=mid+d-1) printf("%d ",primes[i]) ;
				else printf("%d\n",primes[i]) ;
		}
		
	}
	return 0 ;
}
