#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    return (n==1 || n==0) ? 1 : n * fact(n-1);
}
int comb(int n , int r)
{
    if(r>n)
        return 0;
    return fact(n) / (fact(r) * fact(n-r));
}

int calcsubstr(string s)
{
    int arr[3][s.length()+1];
    memset(arr , 0, sizeof(arr));
    for(int i = 0; i < s.length() ; i++)
    {
        int num = s[i] - 48;
        for(int j = i+1 ; j < s.length() +1 ; j++)
        {
            arr[num][j]++;
        }
    }

//    for(int i =0;i <3;i++)
//    {
//        for(int j =0; j < s.length()+1 ;j++ )
//        {
//            cout<<arr[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    unordered_map<string , int> m;
    for(int j = 0 ; j < s.length() + 1 ; j++)
    {
        int num1 = arr[1][j] - arr[0][j];
        int num2 = arr[2][j] - arr[1][j];
        string newstr = to_string(num1) + "*" + to_string(num2);
        m[newstr]++;
    }

    unordered_map<string , int> :: iterator it;
    int res = 0;
    for( it = m.begin() ; it != m.end() ; it++)
    {
        res += comb(it->second, 2);
    }
    return res;
}
int main()
{
   string s;
   cin>>s;
   cout<< calcsubstr(s);
}
