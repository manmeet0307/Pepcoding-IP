#include<iostream>
 #include<vector>
 using namespace std;
 pair<int,int> getminsm(vector<int> v)
 {
     pair<int , int> p;
     int min1=INT_MAX , mini1 , min2=INT_MAX , mini2;
     for(int i=0; i< v.size() ;i++)
     {
         if(v[i] < min1)
         {
             min1 = v[i];
             mini1 = i;
         }

     }
      for(int i=0; i< v.size() ;i++)
     {
          if(v[i] < min2 && i !=mini1)
         {
             min2 = v[i];
             mini2 = i;
         }
     }
     return make_pair(mini1,mini2);
 }
 int minCostII(vector<vector<int>>& costs) {

        int n = costs.size();
        int k = costs[0].size();
        int **dp = new int *[k];
        for(int i=0;i<k;i++)
        {
            dp[i] = new int[n];
        }
    int m, sm;
    vector<int> v(k);
    for(int i=0;i<k;i++)
    {
        v[i] = costs[0][i];
    }
        //costs[0][0] > costs[0][1] ? m = 1 , sm = 0: m = 0 , sm = 1;
        for(int i = 0 ; i < k ;i ++)
        {
            dp[i][0] = costs[0][i];
        }
        pair<int,int> p = getminsm(v);
         m = p.first , sm = p.second;
        for(int j = 1; j < n; j++)
        {
            int c = 0;
            vector<int> t(k);
            for(int x = 0 ; x < k ; x++)
            {
                if(m == x)
                {
                    dp[x][j] = dp[sm][j-1] + costs[j][x];
                }
                else{
                    dp[x][j] = dp[m][j-1] + costs[j][x];
                }
                t[c++] = dp[x][j];
            }
            p = getminsm(t);
         m = p.first , sm = p.second;
      //   cout<<"col "<<j<<" " <<m<<" " <<sm<< " "<<endl;
        }

        int min1 = INT_MAX;
        for(int i = 0; i < k ; i++)
        {
            if(min1 > dp[i][n-1])
            {
                min1 = dp[i][n-1];
            }
        }

        for(int i = 0;i< k;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        return min1;
}

 int main(int argc,char** argv) {
     int n ,k;
     cin>>n>>k;
     vector<vector<int>> costs(n,vector<int>(k));
     for(int i=0;i<n;i++){
         for(int j=0;j<k;j++){
             cin>>costs[i][j];
         }
     }
     cout<<minCostII(costs)<<endl;
 }
