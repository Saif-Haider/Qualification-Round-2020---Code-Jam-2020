
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    unordered_set <int> s;
            
    for(int t=1;t<=T;++t)
    {
        int n;
        cin>>n;
        
        int arr[n][n];
        int sum =0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                cin >> arr[i][j];
                
                if(i==j)
                sum = sum + arr[i][j];
            }
        }
        
        
        int r=0,c=0;
        
        for(int i=0;i<n;++i)
        {
            s.clear();
            for(int j=0;j<n;++j)
            {
               s.insert(arr[i][j]);
         
            }
            
            if(s.size() < n)
              r++;
        }
        
        
        for(int i=0;i<n;++i)
        {
            s.clear();
            for(int j=0;j<n;++j)
            {
               s.insert(arr[j][i]);
         
            }
            
            if(s.size() < n)
              c++;
        }
        
        
        cout <<"Case #"<<t<<": "<<sum<<" "<<r<<" "<<c<<"\n"; 
    }

    return 0;
}
