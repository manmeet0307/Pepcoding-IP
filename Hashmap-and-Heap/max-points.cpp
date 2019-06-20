#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

 ///Dont make changes here
 class Point {
     public:
     int x, y;

     Point(int x, int y) {
         this->x = x;
         this->y = y;
     }
 };

 int maxPoints(vector<Point> points) {

     unordered_map<string , int> m;
     int mk = -1;
     for(int i = 0; i < points.size() ; i++)
     {
            for(int j = i+1; j < points.size() ; j++)
            {
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                int x = __gcd(dy,dx);
                string key = to_string(dy/x) + "-" + to_string(dx/x);
                m[key]++;
                if(m[key] > mk)
                {
                    mk = m[key];
                }
            }
            m.clear();
     }
 return mk + 1;
 }

 int main(int argc, char** argv) {
     int n;
     cin>>n;
     vector<Point> points;
     for (int i = 0; i < n; i++) {
         int x, y;
         cin>>x>>y;
         points.push_back(Point(x, y));
     }
     cout<<maxPoints(points);
 }
