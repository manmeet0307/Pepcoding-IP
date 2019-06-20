#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
class Project{
public:
    int pno , prft , cap ;
    Project(int x , int y , int z)
    {
        pno = x;
        prft = y;
        cap = z;
    }
};

class projcomp{
public:
    bool operator()(Project one , Project two){
        return one.prft < two.prft ;
    }
};

bool capcomp(Project one, Project two)
{
    return one.cap < two.cap;
}
int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {

     priority_queue<Project , vector<Project> , projcomp> projpq;

  vector<Project> arr;
  for(int i =0 ;i < Profits.size() ;i++)
  {
      arr.push_back(Project(i,Profits[i], Capital[i]));
  }
  sort(arr.begin() , arr.end() , capcomp);
  /*
  for(int i = 0 ; i < n ; i++)
  {
      if(arr[i].cap<= W)
      {
          cappq.push(arr[i]);
      }
  }*/
  int c = 0;
   while( c<arr.size() && arr[c].cap<=W)
   {
            projpq.push(arr[c]);
            c++;
   }
  int counter = 0;
  while(!projpq.empty() )
  {
     Project temp = projpq.top();
     projpq.pop();
     //p += temp.prft;
     W = W + temp.prft;
      counter++;
      if(counter == k)
      {
          break;
      }
      while( c<arr.size() && arr[c].cap<=W)
      {
            projpq.push(arr[c]);
            c++;
      }
  }
  return W;
}

 int main(int argc, char** argv){
     int k, w;
     cin>>k>>w;

     int n;
     cin>>n;
     vector<int> profits;
     vector<int> capital;

     for (int i = 0; i < n; i++) {
         int a;
         cin>>a;
         profits.push_back(a);
     }

     for (int i = 0; i < n; i++) {
         int a;
         cin>>a;
         capital.push_back(a);
     }

     cout<<findMaximizedCapital(k, w, profits, capital);
 }
