#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void completeTask(int n, int m, vector<int> &comp)
{
    unordered_set<int> s;
    for(int i =0 ;i <n ;i++)
    {
        s.insert(i+1);
    }
    for(int i =0 ;i < comp.size() ; i++)
    {
        s.erase(comp[i]);
    }
    vector<int> tanya, manya;
    bool f =1;
    for(int i =0 ;i <n ;i++)
    {
        if(s.find(i+1) == s.end())
        {
            continue;
        }
        else
        {
            if(f==1)
            {
                tanya.push_back(i+1);
            }
            else
            {
                manya.push_back(i+1);
            }
            f==1 ? f = 0 : f = 1;
        }
    }
    for(int i =0;i<tanya.size() ;i++)
    {
        cout<<tanya[i]<<" ";
    }
    cout<<endl;
    for(int i =0;i<manya.size() ;i++)
    {
        cout<<manya[i]<<" ";
    }

}
 int main(int argc, char *argv[])
 {
     int n = 0, m = 0;
     cin >> n >> m;
     vector<int> num(m);
     for (int i = 0; i < m; i++)
     {
         cin >> num[i];
     }
     completeTask(n, m, num);
     return 0;
 }
