#include<bits/stdc++.h>
using namespace std;

int fun(int l , int m)
{
    int v = 2;
    int sum = 1;
    for(int i = 1 ; i< l ; i++)
    {
        v = (v*v + 1)%m;
        sum += v;
    }
    return sum %m;
}
int main()
{

    cout<<fun(1,2);
}
