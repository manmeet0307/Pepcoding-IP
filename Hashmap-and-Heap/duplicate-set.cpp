#include<iostream>
 #include<string>
 #include<vector>
 #include<unordered_set>
 using namespace std;

 bool containsDuplicate(vector<int> &nums) {
     unordered_set<int> s;
     for(int i = 0 ; i <nums.size() ; i++)
     {
         if(s.count(nums[i]))
         {
             return true;
         }
         s.insert(nums[i]);
     }
     return false;
 }



 int main(int argc,char** argv){

     int N ;
     cin>>N;

     vector<int> v;

     for (int i = 0; i < N; i++) {
         int a;
         cin>>a;
         v.push_back(a);
     }

     bool res=containsDuplicate(v);
     string ans=res==true?"true":"false";
     cout<<ans<<endl;
 }
