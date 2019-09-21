#include<bits/stdc++.h>
#include<algorithm>
#include<string>

using namespace std ;

int check(int h[])
{
  for(int i=0;i<=128;i++)
    if(h[i]<0)  return 0;
  return 1;
}

int complete(int h[])
{

  for(int i=0;i<=128;i++)
    if(h[i]!=0)  return 0;
  return 1;
}

int equality_check(vector<string> &v1,vector<string> &v2)
{
  unordered_set<string> s1 ;
  for(int i=0;i<v1.size();i++)   s1.insert(v1[i]) ;

   for(int i=0;i<v2.size();i++) if(s1.find(v2[i])!=s1.end())  return 1;

   return 0 ;  

}

void C( 
        int dict[] ,
        vector<string> &dictionary,
        int n,
        vector<vector<string> > &sol,
        vector<string> &ph 
      )
{

if(complete(dict)) 
{

  vector<string> new_ph ;
 // for(int k=0;k<ph.size();k++) new_ph.push_back(ph[k]) ;

  new_ph = ph ;
  sort(new_ph.begin(),new_ph.end()) ;

  sol.push_back(new_ph) ;

  return;
}
if(n<0||!check(dict))
{
  return ;
}

  // include
  string word = dictionary[n] ;
  for(int i=0;i<word.length();i++)
  {
    dict[word[i]]-- ;
  }
  ph.push_back(word);

  C(dict,dictionary,n-1,sol,ph) ;


  // remove

  for(int i=0;i<word.length();i++)
  {
    dict[word[i]]++ ;
  }
  ph.pop_back();

  C(dict,dictionary,n-1,sol,ph) ;
}

int main()
{

  string str,phrase,word ;


 // unordered_set<string> hash ;
  vector<string>  dictionary ;
  int flag = 0 ;

  while(1)
  
  {
    getline(cin,str);


      if(str=="#")
      {
            while(1)
          {
              getline(cin,phrase) ;

              vector<string>  phrase_words ;

            if(phrase=="#")
              {
                flag = 1 ;
                break; 
              }

              istringstream ss(phrase) ;

              while(ss>>word)
              {
                phrase_words.push_back(word) ;
              }

              // POST PROCESSING 

              // we have phrase words and hash of dictionary till now


              int phrase_hash[129] = {0};

                // do phrase hash to reduce search space

                for(int i=0;i<phrase_words.size();i++)
                {
                    for(int j=0;j<phrase_words[i].length();j++)
                    {
                      phrase_hash[phrase_words[i][j]]++;
                    }
                }


                // reduce search space by checking existance in phrase hash

                vector<string> pruned_dict;

                for(int i = 0;i<dictionary.size();i++)
                {

                    int include_flag = 1;

                      for(int k=0;k<dictionary[i].length();k++)
                      {

                        if(!phrase_hash[dictionary[i][k]])
                        {
                          // if doesnt match then ignore this dictionary word
                          include_flag = 0;
                          break;
                        }

                      }

                // include words that has all letters in phrase
                    if(include_flag)   
                    {
                        pruned_dict.push_back(dictionary[i]) ;
                    }
                }


                vector<vector<string> > sol ;
                vector<string> ph ;

                C(phrase_hash,pruned_dict,pruned_dict.size()-1,sol,ph);

                /*print the solution*/

                sort(sol.begin(),sol.end());
                //sort(phrase_words.begin(),phrase_words.end());

                for(int x=0 ; x<sol.size() ; x++)
                {
                  int ph_size = sol[x].size() ;

                  if(!equality_check(phrase_words,sol[x]))
                  {
                      cout<<phrase<<" = ";
                      for(int y=0 ; y<ph_size ; y++)
                      {
                            cout<<sol[x][y];
                            if(y!=ph_size-1)  cout<<" ";
                      }
                      cout<<endl;
                  }
                }

                phrase_words.clear() ;
          }
      }
      else
      {
       //   hash.insert(str) ;
          dictionary.push_back(str);
      }

      if(flag)   break;
  }

  return 0 ;
}