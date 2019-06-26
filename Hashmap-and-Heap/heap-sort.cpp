#include<iostream>
 #include<vector>
 using namespace std;

 void printArray(vector<int> &arr) {
     int n = arr.size();
     for (int i = 0; i < n; ++i)
         cout<<arr[i]<<" ";
     cout<<endl;
 }

 void heapify(vector<int> &arr, int n) {
    int hs = n;
    while(hs > 0)
    {
        int pi = 0;
        swap(arr[pi] , arr[hs-1]);
        hs--;
        while(true)
        {
            int lci = 2*pi + 1;
            int rci = 2*pi+2;
            int mi = pi;
            if(lci< hs && arr[lci] > arr[mi])
            {
                mi = lci;
            }
            if(rci < hs && arr[rci] > arr[mi])
            {
                mi = rci;
            }
            if(mi==pi) break;
            swap(arr[mi] , arr[pi]);
            pi = mi;
        }
    }
 }
 void sort(vector<int> &arr) {
     int hs = 1;
     for(int i = 1;i < arr.size();i++)
     {
         hs++;
         int ci = hs-1;
   //      heapify(arr,hs,ci);
         while(ci!=0)
         {
           int pi = (ci - 1)/2;
           if(arr[pi] > arr[ci])
           {
               break;
           }
            swap(arr[pi],arr[ci]);
            ci = pi;
          }
     }

     heapify(arr,arr.size() );
 }


 int main(int argc, char** argv){
     int n;
     cin>>n;
     vector<int> arr;
     for(int i=0;i<n;i++){
         int val; cin>>val;
         arr.push_back(val);
     }
     sort(arr);
     printArray(arr);
 }
