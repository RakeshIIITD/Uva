/*  Disjoint set based problem
*   Link : https://leetcode.com/problems/smallest-string-with-swaps/
*
*/

#include<bits/stdc++.h>
class Solution {
public:
    
    int n ;
    vector<int> pset ;
    vector<int> _size ;
    void init()
    {
        pset.assign(n,0) ;
        _size.assign(n,1) ;
        
        for(int i=0;i<n;i++)  
        {
            pset[i] = i ;
        }
    }
    
    int findSet(int i)
    {
        return  pset[i]==i?i:(pset[i] = findSet(pset[i])) ;
    }
    
    void unionSet(int i,int j)
    { 
        i = findSet(i) ;
        j = findSet(j) ;
        
        if(i!=j)
        {
            if(_size[j]>_size[i])
            {
                pset[i] = j ;
                _size[j]+= _size[i] ;
            }
            else
            {
                pset[j] = i ;
                _size[i]+= _size[j] ;
            }
        }
        
    }
    bool isSameSet(int i,int j) { return findSet(i)==findSet(j) ; }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
    {
        
        n = s.size() ;
      
        init() ;
         for(int i=0;i<pairs.size();i++)
         {
             unionSet(pairs[i][0] , pairs[i][1] ) ;
         }
        
        vector<pair<char,int> > inv ;
        
        for(int i=0; i<n; i++)
        {
            inv.push_back(make_pair(s[i],i)) ;
        }
        
        sort(inv.begin(), inv.end()) ;
        
        vector<pair<int, vector<int> > > adj  ;
        
        for(int i=0; i<n; i++)   adj.push_back(make_pair(0,vector<int>(0))) ;
        
        for(int i=0; i<n; i++)
        {
            pset[i] = findSet(i) ;
            adj[pset[i]].second.push_back(i) ;
        }
        
        /* traverse inv table */
        
        int index; char ch ;
        int rep ; int counter ;
        string out(n,' ');
        
        for(int i=0; i<n ; i++)
        {
            ch = inv[i].first ;
            index = inv[i].second ;

            index = findSet(index) ;
            counter = adj[index].first ;
            
            rep = adj[index].second[counter] ;

            out[rep] = ch ;
            adj[index].first+=1 ;
        }
        
        return out ;
    }
};
