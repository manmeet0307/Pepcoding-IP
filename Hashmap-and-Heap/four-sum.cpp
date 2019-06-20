#include <iostream>
#include <algorithm>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
/*
class helper{
public:
    int x, y, z,w;
    helper(int p , int q,int r ,int s)
    {
        x = p;
        y = q;
        z = r;
        w = s;
    }
    bool operator==(const helper& t) const
    {
        return (this->x == t.x && this->y == t.y && this->z == t.z && this->w == t.w) || (this->x == t.z && this->w == t.y && this->z == t.x && this->w == t.y);
    }

};

class MyHashFunction {
public:
    // id is returned as hash function
    size_t operator()(const helper& t) const
    {
        return t.x;
    }
};*/
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
     unordered_map<int , vector<pair<int,int>>> m;
     for(int i=0;i<nums.size();i++)
     {
         for(int j = i+1; j < nums.size() ;j++)
         {
             m[nums[i]+nums[j]].push_back(make_pair(i,j));
         }
      }

     unordered_map<int , vector<pair<int,int>>> :: iterator it;


     vector<vector<int> > ans;
     int c =0;
     for(int i=0;i<nums.size();i++)
     {
         for(int j = i+1; j < nums.size() ;j++)
         {
             int cds = nums[i] + nums[j];
             if(m.count(target-cds))
             {
                vector<pair<int,int>> tbs = m[target-cds];
                for(int r = 0 ; r < tbs.size() ; r++)
                {
                    vector<int> x ;
                    if(tbs[r].first==i || tbs[r].first==j || tbs[r].second==i || tbs[r].second == j)
                        continue;

                    x.push_back(nums[i]);
                    x.push_back(nums[j]);
                    x.push_back(nums[tbs[r].first]);
                    x.push_back(nums[tbs[r].second]);
                    ans.push_back(x);
                }
             }
         }
     }
/*
     cout<<endl;
     //remove dupllicacy from vector

     unordered_set<helper , MyHashFunction> s;
     for(int i =0;i < ans.size();i++)
     {
        vector<int> t = ans[i];
         s.insert(helper(t[0] , t[1] , t[2] ,t[3]));
     }

     for (auto e : s) {
        cout <<"[ "<< e.x << " "<<e.y << " "<<e.z << " "<<e.w << " ]";
    }
  cout<<endl<<endl<<endl;*/
     return ans;
 }

 int main(int args, char **argv)
 {
     int n, target;
     cin >> target >> n;
     vector<int> nums(n, 0);
     for (int i = 0; i < n; i++)
     {
         cin >> nums[i];
     }

     vector<vector<int>> list = fourSum(nums, target);
     cout << "[";
     for (int i = 0; i < list.size(); i++)
     {
         cout << "[";
         for (int j = 0; j < list[i].size(); j++)
         {
             if (j == list[i].size() - 1)
                 cout << list[i][j];
             else
                 cout << list[i][j] << ",";
         }
         if (i == list.size() - 1)
             cout << "]";
         else
             cout << "],";
     }
     cout << "]";
 }
