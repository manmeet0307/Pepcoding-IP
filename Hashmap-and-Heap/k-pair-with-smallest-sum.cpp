#include<iostream>
 #include<vector>
 #include<string>
 #include<bits/stdc++.h>
 using namespace std;
  class helper{
  public:
      int sum;
      int i,j;
      helper(int x , int y , int z)
      {
          sum = x;
          i = y;
          j = z;
      }
      helper(){
      }
  };

  class mycomp{
  public:
      bool operator()(helper o,helper t)
      {
          return o.sum > t.sum;
      }
  };
vector<vector<int> > kSmallestPairs(vector<int>& num1,vector<int> &num2 ,int k){
   priority_queue<helper,vector<helper>, mycomp> pq;
   set<pair<int,int>> s;
   sort(num1.begin() , num1.end());
   sort(num2.begin() , num2.end());
    pq.push(helper(num1[0] + num2[0] , 0 , 0));
    s.insert(make_pair(0,0));;
    vector<vector<int>> ans;
    for(int x = 0 ; x < k ; x++)
    {
        helper temp = pq.top();
        pq.pop();
        vector<int> v{num1[temp.i] , num2[temp.j]};
        ans.push_back(v);
        int i = temp.i , j = temp.j;
        if(s.find(make_pair(i+1,j)) == s.end() )
        {
            pq.push(helper(num1[i+1] + num2[j] , i+1 , j));
        }
        if(s.find(make_pair(i,j+1)) == s.end() )
        {
            pq.push(helper(num1[i] + num2[j+1] , i , j+1));
        }
    }
    return ans;
}

 void display(vector<vector<int> > &v){
     for(int i=0;i<v.size();i++){
         for(int j=0;j<v[i].size();j++){
             cout<<v[i][j]<<" ";
         }
         cout<<endl;
     }
 }
 bool sortcol( const vector<int>& l1,
                const vector<int>& l2 ) {
     int sum1 = l1[0] + l1[1];
     int sum2 = l2[0] + l2[1];

     if (sum1 != sum2) {
         return sum1 <sum2;
     } else {
         return l1[0]< l2[0];
     }

 }
 int main(int argc,char ** argv){

     int n;
     cin>>n;
     vector<int> num1;
     vector<int> num2;
     for(int i=0;i<n;i++){
         int a;
         cin>>a;
         num1.push_back(a);
     }

     int m;
     cin>>m;
     for(int i=0;i<m;i++){
         int a;
         cin>>a;
         num2.push_back(a);
     }

     int k;
     cin>>k;
     vector<vector<int> > res;
     res=kSmallestPairs(num1, num2, k);
     sort(res.begin(),res.end(),sortcol);
     display(res);
 }
