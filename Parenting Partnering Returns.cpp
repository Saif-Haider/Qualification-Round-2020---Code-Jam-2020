
#include <bits/stdc++.h>

using namespace std;

struct triplet
{
  pair <int,int > X;
  int i;
};

struct person
{
  char name;
  bool busy;
  int endtime;
};

bool cmp(triplet A,triplet B)
{
    if ( (A.X.second < B.X.second) || (A.X.second == B.X.second && A.X.first < B.X.first))
      return true;
    return false;
}
int main()
{
    int T;
    cin>>T;
   
            
    for(int t=1;t<=T;++t)
    {
      int n;
      cin>>n;
    int arr[24*60 + 5] ={0};
    fill(arr,arr + 24*60 + 5 ,0);

      //vector <pair<int,int>> p;
      vector <triplet> trip;
      triplet tmp;
      int x,y; 
      
      for(int i=0;i<n;++i)
       { cin>>x>>y;
         //v.push_back({x,y});
         tmp.X = {y,x};
         tmp.i = i;

         trip.push_back(tmp);
         arr[x]++;
         arr[y]--;
       }


       int presum=0;
      
      bool possible= true;
       for(int i=0;i<24*60+5;++i)
       {
        presum = presum + arr[i];
        if(presum>2)
          possible = false;

       }

       sort(trip.begin(),trip.end(),cmp);
     
     person a ,b;
     a.name = 'C';
     a.busy = false;
     b.name = 'J';
     b.busy = false;

 // for(int i=0;i<trip.size();++i)
 //        {
 //          cout <<trip[i].X.second<<" "<<trip[i].X.first<<" "<<trip[i].i<<"\n";
 //        }
 //        cout<<"\n\n\n\n\n\n";

     string ans(n,' ');
     if(possible )
     {
        for(int i=0;i<trip.size();++i)
        { 


           if(a.busy ==false || a.endtime <= trip[i].X.second)
           {

        //    cout << a.endtime <<"  "<< trip[i].X.second<<"\n";
              ans[trip[i].i] = a.name;
              a.busy = true;
              a.endtime = trip[i].X.first;
           }
           else
           {
              ans[trip[i].i] = b.name;
              // b.busy = true;
              // b.endtime = trip[i].X.first;
           }
        }

     }


    if(possible)
       cout <<"Case #"<<t<<": "<<ans<<"\n";
     else
       cout <<"Case #"<<t<<": "<<"IMPOSSIBLE"<<"\n";

    }
    

    return 0;
}

