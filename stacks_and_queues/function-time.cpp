#include<bits/stdc++.h>
using namespace std;
class helper{
    public:
    int pid;
    int stime;//start time
    int nmt; // not my time
    helper(int a , int b , int c)
    {
        pid = a;
        stime = b;
        nmt = c;
    }
};

int getpid(string s)
{
    string a;
    for(int i =0;i< s.length() ;i++)
    {
        if(s[i]==':')
        {
            break;
        }
        a += s[i];
    }
    return stoi(a);
}

int getendtime(string s)
{
    string a;
    for(int i = s.length()-1;i>=0;i--)
    {
        if(s[i]==':')
        {
            break;
        }
        a += s[i];
    }
    reverse(a.begin(),a.end());
    return stoi(a);
}
vector<int> func_calc(vector<string> arr,int n)
{
    vector<int> ans(n);
    stack<helper> st;
    for(int i = 0; i<arr.size() ; i++ )
    {
        string curr = arr[i];
        //cout<< curr<<endl;
        if(curr.find("start") != string :: npos)
        {
            int s = getpid(curr) , e = getendtime(curr);
            st.push(helper( s , e , 0));
          //  cout<<"start"<<endl;
        }
        else
        {
            //cout<<"end"<<endl;
            int endtime = getendtime(curr);
            int starttime = st.top().stime;
            int x = st.top().nmt;
            st.pop();

             int res = (endtime - starttime + 1) - x ;
             ans[getpid(curr)] = res ;
             if(!st.empty() )
              st.top().nmt += (endtime - starttime + 1);
        }
    }
    return ans;
}
int main()
{
    int n , m;
    cin>> n >> m;
    vector<string> arr;
    for(int i =0;i<m;i++)
    {
        string s;
        cin>> s;
        arr.push_back(s);
    }
    vector<int> a = func_calc(arr,n);
    for(int i =0;i<a.size() ;i++)
    {
        cout<<a[i]<<" ";
    }
}
