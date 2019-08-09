#include<bits/stdc++.h>
using namespace std;
int root(int i)
{
    return round(sqrt(i));
}
int f(int k)
{
    int counter = 0;
    for(int i = 0; i<= k ; i++)
    {

        for(int j = 0; j <= k ; j++)
        {
            if((root(i) + 5) == (root(j) + 5))
            {
                counter++;
            }
        }
    }
    return counter;
}
int main()
{
    cout<<f(2);
}
