#include<bits/stdc++.h>

using namespace std;

int A,B,N;

void C(int Ca,int Cb)
{


	if(Ca==N||Cb==N)   return ;
 	if(Ca!=A) C(A,Cb) ;   // fill A
	if(Cb!=B) C(Ca,B) ;  // fill B
	if(Ca<A)  C((Ca+Cb)%A , Ca+Cb>A?Cb-(A-Ca):0 );   // fill B->A
	if(Cb<B)  C(Ca+Cb>B?Ca-(B-Cb):0 , (Ca+Cb)%B );   // fill A->B
	if(Ca!=0) C(0,Cb);   // empty A
	if(Cb!=0) C(Ca,0);   // empty B
}

int main()
{

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout) ;
    #endif

    

    while(scanf("%d",&A)>0)
    {
    	scanf("%d%d",&B,&N) ;

    	C(0,0);

    }
	return 0;
}