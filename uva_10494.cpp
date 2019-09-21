#include<bits/stdc++.h>
#include<string>

using namespace std ;


int main()
{
	// #ifndef ONLINE_JUDGE
 //  freopen("input.txt","r",stdin);
 //  freopen("output.txt","w",stdout) ;
	// #endif  

	int ans,x1,x2,y1,y2;

  	while(1)
  	{
        cin>>x1>>y1>>x2>>y2;

        if( x1==0 and x2==0 and y1==0 and y2==0 ) break;

        if(x1==x2 and y1==y2) cout<<"0"<<endl;
        else if((abs(x1-x2)==abs(y1-y2)) or (x1==x2||y1==y2) ) cout<<"1"<<endl;
        else          cout<<"2"<<endl;

  		
  	
  	}

	return 0 ;
}