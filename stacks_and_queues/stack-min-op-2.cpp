#include<bits/stdc++.h>
using namespace std;
class minStack{

public:

    stack<int> ds;
    int minel;
    minStack()
    {
        minel = INT_MAX;
    }
    void push(int x)
    {
        if(ds.empty())
        {
            minel = x;
            ds.push(minel);
        }
        else if(minel<x)
        {
            ds.push(x);
        }
        else{
            ds.push(x + x - minel);
            minel = x;

        }
    }
    int pop()
    {
        if(ds.empty())
            return -1;
        int x = ds.top();
        ds.pop();
        if(x < minel)
        {
            minel =  2*minel -x;
            return (x + minel)/2;
        }
        return x;
    }
    int getmin()
    {
        return !ds.empty() ? minel : -1;
    }
};
int main()
{
    minStack fq;
    int n;
    cin>>n;
    int i=0;
      	   while(i!=n){
      	  	   int q;
      	  	   cin>>q;
      	  	   if(q==1){
                    i++;
                    int num;
                    cin>>num;
      	  	  	   fq.push(num);
      	  	   }
      	  	   else if(q==2) cout<<fq.pop()<<endl;
      	  	   else if(q==3) cout<<fq.getmin()<<endl;
      	  	   i++;
      	   }
      	   //cout<<fq.mf<<endl;
}
