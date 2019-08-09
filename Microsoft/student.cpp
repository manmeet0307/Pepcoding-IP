#include<bits/stdc++.h>
using namespace std;
class mycomp{
public:
    bool operator()(const pair<int , int> a , const pair<int,int> b)
    {
        return a.second > b.second;
    }
};
int fun(int mat[][4] , int m , int n ,int * b)
{
    vector<int> v;
    for(int i = 0; i < m ; i++)
    {
        int c = 0;
        for(int j = 0; j<n;j++)
        {
            if(mat[i][j])
            {
                c++;
            }
        }
        v.push_back(c);
    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , mycomp> pq;
    for(int i =0 ; i < n ; i++)
    {
        pq.push(make_pair(i , v[i]));
    }
    int counter = 0;
    while(!pq.empty())
    {
        pair<int,int> c = pq.top();
        pq.pop();
        //cout<<c.second<<endl;
         for(int j= 0;j<m;j++)
         {
             if(mat[c.first][j] && b[j])
             {
                 counter++;
                 b[j]--;
                 break;
             }
         }
    }
    return counter;
}
int main()
{
    int mat[][4] = {{0,0,1,0} , {1,1,1,1} , {0 , 1, 1,1} , {0,1,0,1} , {1,0,1,0}};
    int b[] = {5,4,3,2,1};
    cout<<fun(mat , 5,4,b)<<endl;
}
