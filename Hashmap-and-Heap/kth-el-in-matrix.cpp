#include<iostream>
 #include<vector>
 #include<queue>
 #include<string>
 using namespace std;

 // Function to display a matrix.
 void display(vector<vector<int> >&mat) {

     for (int i = 0; i < mat.size(); i++) {
         for (int j = 0; j < mat[0].size(); j++) {
             cout<<mat[i][j]<<" ";
         }
         cout<<endl;
     }
 }

 // This is a functional problem. You have to complete this function.
 // It takes as input a matrix and K.
 int findKthSmallest(vector<vector<int> >& nums, int k) {
     // write your code here.

     int m = nums.size() , n = nums[0].size();
     priority_queue<int> pq;
     int i , j ,c=0;
     /*for( i = 0 ; i < m ;i ++)
     {
         for(int j = 0 ; j  < n ; j ++)
         {
             if(c++<k)
             {
                 pq.push(nums[i][j]);
             }
             else{
                break;
             }
         }
     }*/
       for( i = 0 ; i < m ;i ++)
     {
         for(j = 0 ; j  < n ; j ++)
         {
             if(c++<k)
             {
                 pq.push(nums[i][j]);
             }
            else if(nums[i][j] < pq.top())
            {

                pq.pop();
                pq.push(nums[i][j]);
            }
         }
    }
    return pq.top();
 }

 int main(int argc,char** argv){


         int N;
         cin>>N;

         vector<vector<int> > mat(N,vector<int>(N) );

           for (int i = 0; i < mat.size(); i++) {
             for (int j = 0; j < mat[0].size(); j++) {
                 cin>>mat[i][j];
             }
         }

         int K;
         cin>>K;
         int result = findKthSmallest(mat, K);

         cout<<result<<endl;
 }
