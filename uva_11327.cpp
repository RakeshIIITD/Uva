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
ll h[200001] ;
bitset<10000010>bs ;
vi primes ;
ll sieve_size ;
int gcd(int a,int b){ return b==0?a:gcd(b,a%b) ; }
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
	int PF_idx = 0 ;
    int PF = primes[PF_idx] ;
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

long EulerPhi(int N)
{
	vi factors = primeFactors(N) ;
	vi::iterator new_end = unique(factors.begin() , factors.end()) ;
	long result = N ;
	for (vi::iterator i = factors.begin() ; i!= new_end; i++)
	result = result - (result/(*i));
	return result;
} 
int main()
{
	sieve(200010) ;
	h[1] = 2 ;
	for(int i=2;i<=200000 ; i++ )
	{
		h[i] = EulerPhi(i) ;
		h[i]+= h[i-1] ;
	}
	ll n ;
	while(scanf("%lld",&n)&&n)
	{
		// error from here
		int index = upper_bound(h+1,h+200000,n)-(h+1) ;
		
		int count=0,in;
		cout<<index<<endl ;
		for(int i=1;i<index;i++)
		{
			int g = gcd(i,index) ;
			if(g==1)
			{
				count++ ;
			}
			if(count==(n-h[index-1]))
			{
				in = i ;
				break;
			}
		}
		printf("%d/%d\n",in,index) ; 
	}
	return 0 ;
}
