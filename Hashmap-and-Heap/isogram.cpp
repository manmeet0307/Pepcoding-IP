#include <iostream>
 #include <vector>
 #include <string>
 #include <unordered_map>
 #include <unordered_set>

 using namespace std;

 // --------------------------------------
 bool isIsogram(string &data)
 {
     unordered_set<char> s;
     for(int i =0 ; i<data.size() ;i++)
     {
         if(s.count(data[i]))
            return false;
         s.insert(data[i]);
     }
     return true;
 }
 int main()
 {
     string s;
     cin >> s;

     if (isIsogram(s))
     {
         cout << "true" << endl;
     }
     else
     {
         cout << "false" << endl;
     }
     return 0;
 }
