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

bitset<10000010>bs ;
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

vi primeFactors(int N)
{
	vi Factors ;
	long PF_idx = 0 ;
    long PF = primes[PF_idx] ;
    while(N!=1&&(PF*PF<=N))
    {
    	while(N%PF==0)
		{
			N/=PF ;
		     Factors.push_back(PF) ;
		}
		PF = primes[++PF_idx] ;
    }
    if(N!=1)  Factors.push_back(N) ;
    return Factors ;
}

int main()
{
	long long N ;
	sieve(10000000) ;
	while(1)
	{
		vi factors ;
		scanf("%lld",&N);
		
		if(N==0)  break ;
		printf("%lld = ",N) ;
		if(N==2147483647||N==-2147483647)
		{
			if(N<0)    printf("2147483647 = -1 x 2147483647\n") ;
	    	else       printf("2147483647 = 2147483647\n") ;
		}
		else
		{
			if(N<0)  
			{
		  		printf("-1 x ") ;
	      		factors = primeFactors(-1*N) ;
	      
	      		for(int i=0;i<factors.size() ; i++ )
	      		{
	      			printf("%d",factors[i]) ;
	      			if(i!=factors.size()-1) printf(" x ") ;
	      		}
	    	}
	    	else
	    	{
	    		factors = primeFactors(N) ;
	      
	     	 	for(int i=0;i<factors.size() ; i++ )
	      		{
	      			printf("%d",factors[i]) ;
	      			if(i!=factors.size()-1) printf(" x ") ;
	      		}
	    	}
	    }
	    printf("\n") ;
	    factors.clear() ; 
	}
	return 0 ;
}
