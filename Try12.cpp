/*
 Created by rakesh on 11/5/18.
*/


/*  Uva : Ferry Loading Part-1   */

#include<cstdio>
#include<iostream>
#include<queue>
#define LEFT 0
#define  RIGHT 1
#define TIME first
#define DIR second

using namespace std ;

int main()
{
  int testcase ;
   scanf("%d",&testcase) ;

   int n,m,t ;

   while(testcase--)
   {
        scanf("%d%d%d",&n,&t,&m) ;

        queue<pair<int,int> >q ;

        int a ;
        char b[10] ;

        for(int i=0;i<m;i++)
        {
            scanf("%d %s",&a,&b) ;

            if(b[0]=='l')
            {
                q.push({a,LEFT}) ;
            }
            else
            {
                q.push({a,RIGHT}) ;
            }

        }


        int ferry_d = LEFT ,total = 0;


        while(q.size()>0)
        {
            int limit = n , first =0;

            if(q.front().DIR==ferry_d)
            {
                if(total<=q.front().TIME)
                {
                    first = q.front().TIME ;

                    q.pop() ;
                    limit-- ;
                }

                cout<<"Size"<<q.size()<<endl;

                while(limit!=0 && q.front().DIR==ferry_d && total>=q.front().TIME)
                {
                    q.pop() ;
                    limit-- ;
                }

                total = total + first ;
                total = total + t;
                ferry_d = !ferry_d ;

                /* print the time taken */

                for(int i=0;i<(n-limit);i++)
                {
                    printf("%d\n",total);
                }
            }
            else
            {
                total = total+t ;
                ferry_d = !ferry_d ;
            }
        }

        printf("\n");
   }



    return 0 ;
}

