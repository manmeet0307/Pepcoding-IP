#include <iostream>
 #include <vector>
 #include <string>
 #include <unordered_map>
 #include <unordered_set>
 using namespace std;
 bool areKAnagrams(string &str1, string &str2, int k)
 {
     unordered_map<char,int> m;
     for(int i = 0;i<str1.length() ;i++)
     {
         m[str1[i]]++;
     }
     for(int i =0 ;i < str2.length() ; i++)
     {
         m[str2[i]]--;
     }
     int s = 0;
     unordered_map<char , int> :: iterator it;
     for(it = m.begin() ; it!= m.end() ;it++)
     {
         if(it->second > 0 )
         {
             s += it->second;
         }
     }
     if(s<=k)
     {
         return true;
     }
     else{
        return false;
     }
 }
int main()
 {
     string s1, s2;
     cin >> s1 >> s2;
     int k = 0;
     cin >> k;

     if (areKAnagrams(s1, s2, k))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }
     return 0;
 }
