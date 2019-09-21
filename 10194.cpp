//multiple field sorting
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<sstream>

using namespace std ;

struct Team
{
    string country ;
    int points , gms , wins ,ties , losses , goal_diff ,goal_score , goal_agst ;
    Team(string country,int points,int gms,int wins,int ties,int losses,int goal_diff,int goal_score,int goal_agst):country(country),
    points(points),gms(gms),wins(wins),ties(ties),losses(losses),goal_diff(goal_diff),goal_score(goal_score),goal_agst(goal_agst){}
} ;

bool sortByCountry(const Team &lhs , const Team &rhs) { 
string lhstring="";
string rhstring="";

for(int i=0;i<lhs.country.size();i++)
{
    lhstring+=tolower(lhs.country[i]) ;
}
for(int i=0;i<rhs.country.size();i++)
{
    rhstring+=tolower(rhs.country[i]) ;
}
return lhstring<rhstring ; }

bool sortByPoints(const Team &lhs , const Team &rhs) { return lhs.points>rhs.points ; }
bool sortByGame(const Team &lhs , const Team &rhs) { return lhs.gms<rhs.gms ; }
bool sortByWins(const Team &lhs , const Team &rhs) { return lhs.wins>rhs.wins ; }
bool sortByGoal_diff(const Team &lhs , const Team &rhs) { return lhs.goal_diff>rhs.goal_diff ; }
bool sortByGoal_score(const Team &lhs , const Team &rhs){ return lhs.goal_score>rhs.goal_score ; }

int main()
{
    int testcase ;
    scanf("%d",&testcase ) ;
    
    while(testcase--)
    {   
        char tour[100]={'\0'} ; 
        scanf(" %[^\n]s",tour);  
        cout<<tour<<endl ;
        int teams ;
        scanf("%d",&teams) ;
        
        vector<Team> v;
        
        for(int i=0;i<teams;i++)
        {
            char s[40]={'\0'} ;
            scanf(" %[^\n]s",s);
            v.push_back(Team(s,0,0,0,0,0,0,0,0)) ;  
        }
        
        int matches ;
        scanf("%d",&matches ) ;
        getchar();
        while(matches--)
        {
            string s , t1 , t2 ;
            int s1 , s2 ,index1 ,index2 ;
            
            getline(cin,s);
            
            replace(s.begin(),s.end(),' ','*') ;
            replace(s.begin(),s.end(),'#',' ') ;
            replace(s.begin(),s.end(),'@',' ') ;
            
            stringstream ss(s) ;
            ss>>t1 ;
            replace( t1.begin() , t1.end() , '*' , ' ' ) ;
            ss>>s1 ;
            ss>>s2 ;
            ss>>t2 ;
            replace( t2.begin() , t2.end() , '*' , ' ' ) ;
            
            for(int i=0 ; i<v.size() ; i++ )
            {
                if(v[i].country==t1)
                index1 = i ;
                if(v[i].country==t2)
                index2 = i ;
            }
            
            v[index1].gms+= 1 ;
            v[index2].gms+= 1 ;
            v[index1].goal_score+=s1 ;
            v[index2].goal_score+=s2 ;
            v[index1].goal_agst+=s2 ;
            v[index2].goal_agst+=s1 ;
            if(s1>s2)
            {
                v[index1].points+= 3 ;
                v[index1].wins+= 1 ;
                v[index2].losses+=1 ;   
            }
            if(s2>s1)
            {
                v[index1].losses+=1 ;
                v[index2].wins+=1 ;
                v[index2].points+= 3 ;
            }
            if(s1==s2)
            {
                v[index1].points+= 1 ; 
                v[index2].points+= 1 ;
                v[index1].ties+= 1 ;
                v[index2].ties+= 1 ;
            }
        }
        for(int i=0 ; i<v.size() ; i++ )
        {
                v[i].goal_diff = v[i].goal_score - v[i].goal_agst ;
        }
            
        stable_sort( v.begin() , v.end() , sortByCountry ) ;
        stable_sort( v.begin() , v.end() , sortByGame ) ;
        stable_sort( v.begin() , v.end() , sortByGoal_score ) ;
        stable_sort( v.begin() , v.end() , sortByGoal_diff ) ;
        stable_sort( v.begin() , v.end() , sortByWins ) ;
        stable_sort( v.begin() , v.end() , sortByPoints ) ;
            
        for(int i=0 ; i<v.size() ; i++ )
        {
            cout<<i+1<<") "<<v[i].country<<" "<<v[i].points<<"p, "<<v[i].gms<<"g ("<<v[i].wins<<"-"<<v[i].ties;
            cout<<"-"<<v[i].losses<<"), "<<v[i].goal_diff<<"gd ("<<v[i].goal_score<<"-"<<v[i].goal_agst<<")"<<endl ;
        }
        v.clear() ;     
        if(testcase>0) printf("\n");
    }
    return 0;
}
