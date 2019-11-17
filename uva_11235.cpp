//some test cases failing
#include<bits/stdc++.h>

using namespace std ;

void build( vector<int>& tree, vector<int>& a, int L, int R, int p )
{
  if(L==R)
  {
     tree[p] = a[L] ;
  }
  else
  {

    int mid = (L+R)/2;

    build(tree, a, L, mid, 2*p) ;
    build(tree, a, mid+1, R, 2*p+1) ;

    tree[p] = max( tree[2*p], tree[2*p+1]) ;      
  }
}


int rmq( vector<int>& tree, vector<int>& a, int L, int R, int i, int j, int p )
{
  if(i>R||j<L)   return INT_MIN;
  if(i<=L && j>=R)  return tree[p] ;

  int mid = (L+R)/2 ;

  return max(rmq(tree,a,L,mid,i,j,2*p), rmq(tree,a,mid+1,R,i,j,2*p+1)) ; 
}

int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout) ;
#endif

    map<int,int> m ;
    vector<int> d ;
    vector<int> a ;
    

    int n,q,tmp ;

    cin>>n>>q ;

    vector<int> boundary(n) ;

    for(int i=0;i<n;i++)
    {
        cin>>tmp ;
        d.push_back(tmp) ;
        if(m.find(tmp)!=m.end())
        {
            m[tmp]+=1 ;
        }
        else
        {
            m[tmp] = 1 ;
        }
    }
   // d.clear() ;
    
      for(int i = 0;i<n;i++) a.push_back(m[d[i]]) ;
      
    
      int prev = INT_MIN ;

    for(int i=0;i<n;i++)
    {
        if(a[i]!=prev) 
        {
            boundary[i] = i ;
            prev = a[i] ;
        }
        else
        {
          boundary[i] = boundary[i-1] ;
        }
    }
    
    vector<int> tree(4*n) ;

    build(tree,a,0,n-1,1);

    int i,j ;

   

    for(int k = 0; k<q ; k++ )
    {
      cin>>i>>j ;
      // boundary check
      if(i==j)  
        {
          cout<<1<<endl;
          continue ;
        }



      i = i-1 ; j = j-1 ;
      
      if(i-1>=0&&j-1>=0&&boundary[i]==boundary[j])
      {
        cout<<j-i+1<<endl;
        continue ;
      }

/*  ---------------------  check this section ----------------------------*/
      int b1=0 , b2=0;

      if(i-1>=0&&a[i-1]==a[i])
      {
          b1 = boundary[i]+a[i]-i ;
      }

      if(j+1<n&&a[j+1]==a[j])
      {
          b2 = j-boundary[j]+1 ;
      }

      i = i + b1 ;
      j = j - b2 ;

/*  ---------------------  check this section-end ----------------------------*/

      int res = 0 ;
      if(i<=j)  res = rmq(tree,a,0,n-1,i,j,1) ;

      res = max( res, max(b1,b2) ) ;
      cout<<res<<endl ;
    }

   // cin>>tmp;

  return 0 ;
}