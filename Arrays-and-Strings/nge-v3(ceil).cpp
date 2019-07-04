#include<iostream>
#include<algorithm>
 using namespace std;

 int nextGreaterElement(int n) {
 	 vector<int> num;
 	 while(n>0)
 	 {
 	     num.push_back(n%10);
 	     n/=10;
 	 }
 	 reverse(num.begin() , num.end());
 	 bool val = next_permutation(num.begin() , num.end());
 	 if(val == false)
        return -1;
        int ans = 0;
     for(int i = 0 ; i < num.size();i++)
     {
        cout<<num[i]<<endl;
         ans += ans *10 + num[i];
     }
     return ans;
  }

 int main(int argc, char** argv){
     int n; cin>>n;
     cout<<nextGreaterElement(n);
 }
