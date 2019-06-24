#include<iostream>
 #include<string>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
 class mycomp
 {
 public:
    bool operator()(pair<int,int> one , pair<int,int> two)
    {
        return (pow(one.first,2) + pow(one.second,2))>(pow(two.first,2) + pow(two.second,2));
    }
 };
 vector<vector<int> > kClosest(vector<vector<int> >& points, int k) {
    vector<pair<int , int> > pts;
    for(int i = 0 ; i < points.size() ; i++)
    {
        pts.push_back(make_pair(points[i][0], points[i][1]));
    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , mycomp> pq;
    for(int i = 0 ; i < pts.size() ; i++)
    {
        pq.push(pts[i]);
    }

    vector<vector<int>> v;
    for(int i = 0 ; i < k ; i++ )
    {
        vector<int> temp(2);
        temp[0] = (pq.top()).first;
        temp[1] = (pq.top()).second;

        v.push_back(temp);
        pq.pop();
    }
    return v;
 }
 int main(int argc,char** argv){
     int row;
     cin>>row;
     vector<vector<int> > points(row,vector<int> (2));
     for(int i=0;i<row;i++){
         for(int j=0;j<2;j++){
             cin>>points[i][j];
         }
     }
     int k;
     cin>>k;
     vector<vector<int> > res=kClosest(points,k);
     for(int i=0;i<res.size();i++){
         for(int j=0;j<2;j++)
             cout<<res[i][j]<<" ";
         cout<<endl;
     }
 }
