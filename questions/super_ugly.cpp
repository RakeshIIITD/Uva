class Solution {
public:
    int min_element(vector<int>& N)
    {
        int m = INT_MAX ;
        
        for(int i=0;i<N.size();i++) if(m>N[i]) m = N[i] ;
        
        return m ;
        
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        vector<int> a ;
        
        a.push_back(1) ;
        
        vector<int> N(primes) ;
        vector<int> index(primes.size(),0) ;
        int res ;
        for(int i=0;i<n;i++)
        {
            res = min_element(N);
            a.push_back(res) ;
            
            for(int k=0;k<primes.size();k++)
            {
                if(res==N[k])
                {
                    index[k]++ ;
                    
                    N[k] = primes[k]*a[index[k]] ;
                }
            }
        }
        
        return a[n-1] ;
    }
};
