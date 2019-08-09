#include<string.h>
#include<bits/stdc++.h>
using namespace std;
string changestr(string a, int i , int j)
{
    if( j > i)
    {
       char s = a[j];
        for(int x = j ; x > i; x--)
        {
            a[x] = a[x-1];
        }
        a[i] = s;
    }
    else{
          //  cout<<"i= "<<i<<" " <<j<<endl;
        char s = a[j];
        for(int x = j;x<i;x++)
        {
            a[x] = a[x+1];
        }
       a[i] = s;
    }
    return a;
}
int p(string a)
{
    unordered_map<char,int> m;
    for(int i = 0; a[i] ; i++)
    {
        m[a[i]]++;
    }
    unordered_map<char,int> :: iterator it;
    int oc = 0;
    for(it = m.begin() ; it!= m.end() ; it++)
    {
        if(it->second % 2 != 0)
        {
            oc++;
        }
    }
    if(oc > 1)
    {
        return -1;
    }
    int len = a.length();
    int swapc = 0;
    for(int i =0 , j = len-1; i<j;i++ , j-- )
    {
        if(a[i] == a[j])
        {
            continue;
        }
        int f = INT_MAX, b = INT_MIN; // initialse
        for(int k = i+1;k < j; k++)
        {
            if(a[k] == a[j])
            {
                //cout<<"match at "<<k<<endl;
                f = k;
                break;
            }
        }
        for(int k = j-1; k>i; k--)
        {
            if(a[k] == a[i])
            {
                b = k;
                break;
            }
        }
        //cout<<f<<" " <<b<<endl;
        //swapc += min(f-i , j - b);
        if(f-i < j-b)
        {
            swapc += (f-i);
        }
        else
        {
            swapc += (j-b);
        }

        if(f-i < j-b){
           a = changestr(a,i,f);
           //cout<<a<<endl;
        }
        else{
            a = changestr(a,j ,b );
         //   cout<<a<<endl;
        }
    }
    return swapc;
}
int main()
{

    while(1)
    {
        string ip;
        cin>>ip;
        if(ip == "0") break;
        int a = p(ip);
        if(a == -1)
            cout<<"Impossible";
        else
         cout<<a<<endl;
    }

}


