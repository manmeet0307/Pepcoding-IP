#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
            unordered_map<int , vector<int>> m;
            int n = pid.size();
            for(int i =0;i<n ;i++)
            {
                int c = pid[i];
                int p = ppid[i];
                m[p].push_back(pid[i]);
            }
            queue<int> q;
            vector<int> ans;
            q.push(kill);
            while(!q.empty())
            {
                int num = q.front();
                q.pop();
                ans.push_back(num);
                vector<int> temp = m[num];
                for(int i =0;i < temp.size() ; i++)
                {
                    q.push(temp[i]);
                }
            }
            return ans;
}

int main(int args,char** argv) {
          int n,k;
          cin>>n>>k;
          vector<int> pid(n,0);
          vector<int> ppid(n,0);
          for (int i = 0; i < n; i++) {
              cin>>pid[i];
          }
          for (int i = 0; i < n; i++) {
              cin>>ppid[i];
          }
          vector<int> ans=killProcess(pid, ppid, k);
          sort(ans.begin(),ans.end());
          cout<<"[";
          for(int i=0;i<ans.size();i++){
          if(i!=ans.size()-1)
          cout<<ans[i]<<", ";
          else cout<<ans[i];
          }
          cout<<"]";
      }
