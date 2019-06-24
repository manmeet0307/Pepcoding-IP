#include <iostream>
 #include <vector>
 #include <string>
 #include <unordered_map>
 #include <unordered_set>

 using namespace std;

 // --------------------------------------------------------
 bool isTwoArrayEqual(vector<long> &num1, vector<long> &num2)
 {
    unordered_map<long , int> m;
    for(int i = 0 ; i < num1.size();i++)
    {
        m[num1[i]] = m[num1[i]] + 1;
    }
    unordered_map<long,int> :: iterator it;
//    for(it = m.begin();it!=m.end();it++)
//    {
//        cout<<it->first<<it->second<<endl;
//    }
    for(int i = 0 ; i < num2.size();i++)
    {
        //cout<<num2[i] << "is here"<<endl;
        if(m.find(num2[i]) == m.end())
        {
           // cout<<num2[i]<<endl;
            return false;
        }
        m[num2[i]]--;
        //cout<<num2[i]<<" yo "<<m[num2[i]]<<endl;
        if(m[num2[i]] == 0)
        {
            m.erase(num2[i]);
        }
    }
//    cout<<m.size()<<endl;
//
//    for(it = m.begin();it!=m.end();it++)
//    {
//        cout<<it->first<<it->second<<endl;
//    }
    return m.size()==0 ;

 }
 // --------------------------------------------------------

 int main()
 {
     int n = 0;
     cin >> n;
     vector<long> num(n, 0);
     for (int i = 0; i < n; i++)
     {
         cin >> num[i];
     }

     int m = n;
    // cin >> m;
     vector<long> arr(m, 0);
     for (int i = 0; i < m; i++)
     {
         cin >> arr[i];
     }

     if (isTwoArrayEqual(num, arr))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }
     return 0;
 }
