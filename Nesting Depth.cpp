
#include <bits/stdc++.h>

using namespace std;

void recur(int times,int st,int en,vector<char> v[])
{
  
 // cout << "depth = "<<times<<" "<<st<<' '<<en<<'\n'; 
  if(st > en)
    return;
  
  if(st==en)
  {
    int bari = v[st].front()-'0'-times;
   
   for(int i=1;i<=bari;++i)
    {
      v[st-1].push_back('(');
      v[en+1].push_back(')');
    }
    return;
  }

  int en1=en;
  int st1=st;

  try{
  while( st1<=en and v[st1].front()-times =='0' )
    st1=st1+2;
 }
 catch (char *excp) { 
    cout << "Caught 1" << excp; 
  }


try{
  while( st<=en1 and v[en1].front()-times =='0' )
    en1=en1-2;
 }
 catch (char *excp) { 
    cout << "Caught 2" << excp; 
  }


  if(st1>en1)
    return;
  

 //  cout << "depth2 = "<<times<<" "<<st1<<' '<<en1<<'\n'; 
  
  int fr=st1;
  for(int i=st1;i<=en1;i=i+2)
  {  try{
     if(v[i].front()-times =='0')
     {    
          v[fr-1].push_back('(');
          v[i-1].push_back(')');
          recur(times+1,fr,i-2,v);

          while(i<=en1 && v[i].front()-times =='0')
          {
            i=i+2;
            fr=i;  
          }
          
          i=i-2;
         // cout<<i<<"\n";
     } }
 catch (char *excp) { 
    cout << "Caught 3" << excp; 
  }
  }

  try{
   v[fr-1].push_back('(');
          v[en1+1].push_back(')');
           
recur(times+1,fr,en1,v);
 }
 catch (char *excp) { 
    cout << "Caught 3" << excp; 
  }
    

}
int main()
{
    int T;
    cin>>T;
   
            
    for(int t=1;t<=T;++t)
    {
        string s;
        cin>>s;
        int len = s.length();
        len--;


     
     vector <char> v[2*len + 5];

     for(int i=0;i<=len;++i)
      {
        v[2*i + 1].push_back(s[i]);
      }



        // for(int i=0;i<2*len+5;++i)
        // {
        //   for(auto it=v[i].begin();it!=v[i].end();it++)
        //   {
        //     cout<<*it;
        //   }
        // }
        // cout<<"\n"; 
   
   try{
    recur(0,1,2*len+1,v);
 }
 catch (char *excp) { 
    cout << "Caught " << excp; 
  }

    


        cout <<"Case #"<<t<<": ";

        for(int i=0;i<2*len+5;++i)
        {
          for(auto it=v[i].begin();it!=v[i].end();it++)
          {
            cout<<*it;
          }
        }
        cout<<"\n"; 
    }

    return 0;
}
