#include<iostream>
 #include<vector>
 using namespace std;

 // function to display an array.
 void display(vector<int> &arr) {
     for (int i = 0; i < arr.size(); i++) {
         cout<<arr[i]<<" ";
     }
     cout<<endl;
 }

 // This is a functional problem. You have to complete this function.
 // It takes as input an integer array. It should return true if the number
 // of global inversions are equal to the number of local inversions, else
 // should return false.
 bool isIdealPermutation(vector<int> &A) {
   int msfi = 0 , msf = A[0];
   for(int i = 1 ; i < A.size() ;i++)
   {
       if(A[i] < msf)
       {
           msfi = i , msf = A[i];
       }
       if((i - msfi)>1)
       {
           return false;
       }
   }
   int minsfi = A.size() -1 ,minsofar =  A[A.size() -1] ;
   for(int i = A.size() - 2 ; i>=0 ; i--)
   {
       if(A[i] > minsofar)
       {
           minsofar = A[i];
           minsfi = i;
       }
       if(abs(i - minsfi ) > 1)
        return false;
   }
   return true;
 }
bool perm2(const vector<int> & A)
{
   //int minsfi = A.size() -1 ;
   vector<int> minsofar(A.size());
   minsofar[A.size()-1] =  A[A.size() -1] ;
   for(int i = A.size() - 2 ; i>=0 ; i--)
   {
       if(A[i] < minsofar[i+1])
       {
           minsofar[i] = A[i];
       }
       else{
        minsofar[i] = minsofar[i+1];
       }
   }
   int maxsofar = A[0];
   for(int i = 1; i < A.size() ; i++)
   {
       if(i+1 < A.size() && maxsofar > minsofar[i+1]) //global inv thet is not local inv
       {
         //  cout<<A[i];
           return false;
       }
       maxsofar = max(maxsofar , A[i]);
   }
   return true;
}
 int main(int argc, char** argv){
     int N;
     cin>>N;
     vector<int> arr(N);

     for (int i = 0; i < arr.size(); i++) {
         cin>>arr[i];
     }

     if (perm2(arr)) {
         cout<<"Yes"<<endl;
     } else {
         cout<<"No"<<endl;
     }

 }
