#include<bits/stdc++.h>
using namespace std;
int fleet(pair<int,int> *cars ,int n , int t)
{
    int mf = 0;
    int time = 0;
    int i;
    int m = -1;
    for(int i = 0;i<n;i++)
    {
        if(cars[i].second > t)
        {
            m=i-1;
            break;
        }
    }

    for(i = m; i>=0;i--)
    {
         int ctime = (t - cars[i].second)/cars[i].first;

         if(ctime >= time)
         {
             mf++;
             time = ctime;
         }

    }
    time = 0;
    for(int i = m+1;i<n;i++)
    {
        int ctime = ( cars[i].second - t)/cars[i].first;
        if(ctime >= time)
        {
            mf++;
            time = ctime;
        }
    }


    return mf;
}
bool comparator(pair<int,int> p1 , pair<int ,int> p2)
{
    return p1.second <=p2.second;
}
int main()
{
    int speed[1000],pos[1000];
    int t;
    cin>>t;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>pos[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>speed[i];
    }
    pair<int,int> cars[10000];
    for(int i = 0;i<n;i++)
    {
        cars[i].second = pos[i];
        cars[i].first = speed[i];
    }
    sort(cars,cars + n, comparator);
    for(int i = 0;i<n;i++)
    {
        cout<<cars[i].first <<" "<<cars[i].second<<endl;
    }
    cout<< fleet(cars,n ,t);
}
