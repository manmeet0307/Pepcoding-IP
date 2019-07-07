#include<bits/stdc++.h>
using namespace std;
void lbs(int * arr, int n)
{
    vector<vector<int>> lis(n) , lds(n);
    lis[0].push_back(arr[0]);
    for(int i = 1 ; i< n;i++)
    {
        for(int j = 0;j < i ;j++)
        {
            if(arr[j] < arr[i] && lis[j].size() > lis[i].size())
            {
                lis[i] = lis[j];
            }
        }
        lis[i].push_back(arr[i]);
    }
    cout<<"lis"<<endl;
    for(int i=0;i<lis.size();i++)
    {
        for(int j=0;j<lis[i].size() ;j++)
        {
            cout<<lis[i][j]<<" ";
        }
        cout<<endl;
    }
    lds[n-1].push_back(arr[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        for(int j = i+1;j<n;j++)
        {
            if(arr[j] < arr[i] && lds[j].size() > lds[i].size() )
            {
                lds[i] = lds[j];
            }
        }
        lds[i].push_back(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        reverse(lds[i].begin() ,lds[i].end());
    }

    cout<<"lds"<<endl;
    for(int i=0;i<lds.size();i++)
    {
        for(int j=0;j<lds[i].size() ;j++)
        {
            cout<<lds[i][j]<<" ";
        }
        cout<<endl;
    }
    int mval = 0;
    vector<int> ind;
    for(int i =0;i<n;i++)
    {
        if((lis[i].size() + lds[i].size()) >= mval)
        {
            mval = lis[i].size() + lds[i].size();
            ind.push_back(i);
            cout<<"push " <<i<<endl;
        }
    }
    for(int i=0;i<ind.size() ;i++)
    {
        int index = ind[i];
        cout<<"index"<<index<<endl;
        for(int x = 0;x <lis[index].size() ;x++)
        {
            cout<<lis[index][x]<<" ";
        }
        for(int x = 1;x <lds[index].size() ;x++)
        {
            cout<<lds[index][x]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
int arr[] =  { 1, 11, 2, 10, 4, 5, 2, 1 };
int n = sizeof(arr)/sizeof(arr[0]);
lbs(arr,n);
return 0;
}
