#include<iostream>
 #include<vector>
 #include<string>
 using namespace std;
 // This is a functional problem. You have to complete this function.
 // It takes as input a length and a 2D array of update operations.
 // It should return the modified array.
 vector<int> getModifiedArray(int length, vector<vector<int> >& updates) {
    vector<int> v(length,0);
    for(int i = 0 ; i< updates.size() ; i++)
    {
        vector<int> a = updates[i];
        v[a[0]] += a[2];
        if(a[1] + 1  < length)
        {
            v[a[1] + 1] -= a[2];
        }
    }
    for(int i = 1 ; i < length ;i++)
    {
        v[i] = v[i] + v[i-1];
    }
    return v;
 }
 void display(vector<int> & arr) {

     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }

 int main(int argc,char** argv){

     int length ;
     cin>>length;

     int K;
     cin>>K;

     vector<vector<int> > updates(K,vector<int>(3));

     for (int i = 0; i < updates.size(); i++) {
         for (int j = 0; j < updates[i].size(); j++) {
             cin>>updates[i][j];
         }
     }

     vector<int> res= getModifiedArray(length, updates);
     display(res);
 }
