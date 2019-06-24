#include<bits/stdc++.h>
#include<iostream>
  #include<vector>
  using namespace std;

  // Function to display an array.
  void display(vector<int> &arr) {
      for (int i = 0; i < arr.size(); i++) {
          cout<<arr[i]<<" ";
      }
      cout<<endl;
  }

  // This is a functional problem. You have to complete this function.
  // It takes as input a 2D array
  // It should return the min number of meeting rooms required.
  int minMeetingRooms(vector<vector<int> > &intervals) {
      vector<int> s , e;
      for(int i = 0 ; i < intervals.size();i++)
      {
          s.push_back(intervals[i][0]);
          e.push_back(intervals[i][1]);
      }
      sort(s.begin() , s.end());
      sort(e.begin() , e.end());
int rooms = 1;
      int sptr = 1 , eptr = 0,mr=-1;
      while(eptr < e.size() && sptr< s.size())
      {
          if(s[sptr]<e[eptr])
          {
              rooms++;
              sptr++;
          }
          else{
            rooms--;
            eptr++;
          }
          mr = max(mr , rooms);
      }
      return mr;
  }

  int main(int argc, char** argv){
      int n;
      cin>>n;
      vector<vector<int> > intervals(n, vector<int> (2));
      // Input for intervals.
      for (int i = 0; i < n; i++) {
          cin>>intervals[i][0];
          cin>>intervals[i][1];
      }
      int r = minMeetingRooms(intervals);
      cout<<r;
  }
