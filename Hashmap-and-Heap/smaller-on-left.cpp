#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
void leftsmall(int * arr , int n)
{
    ordered_set o;
    int ans[n];
    for(int i =0; i<n;i++)
    {
        o.insert(arr[i]);
        int * pt = o.find_by_order(arr[i]);
        if(pt == NULL)
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = *pt;
        }
    }
    for(int i =0 ;i<n;i++)
    {
        cout<<ans[i]<< " ";
    }
}
int main()
{
    int arr[] = {4,2,5,6};
    leftsmall(arr,4);
}
