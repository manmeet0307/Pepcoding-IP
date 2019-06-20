#include<bits/stdc++.h>
using namespace std;
vector<int> printnegative(vector<int> &nums, int n ,int k)
{
        vector<int> v;
        vector<int > nge(nums.size());
        stack<int> st;
        st.push(nums.size()-1);
        nge[nums.size()-1] = -1;
        for(int i=nums.size()-2 ; i>=0 ; i--)
        {
            while(!st.empty() && nums[st.top()] <nums[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                nge[i] = -1;
            }
            else
            {
                nge[i] = st.top();
            }
            st.push(i);
        }
    // int n = nums.size();
//     for(int i=0;i<n;i++)
//         cout<<nge[i];

    for(int i=0;i<=n-k;i++)
    {
        if(nge[i] >= i+k)
        {
            v.push_back(nums[i]);
        }
        else
        {
            int x = nge[i],ans;
            while(x<i+k)
            {
                ans = x;
                if(nge[x]==-1)
                {
                    ans = x;
                    break;
                }
                x = nge[x];
            }
            v.push_back(nums[ans]);
        }
    }
    return v;

}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        v.push_back(num);
    }
    int k;
    cin>>k;
    vector<int> m = printnegative(v,n,k);
    for(int i=0;i<m.size();i++)
    {
        cout<<m[i]<<" ";
    }
}
