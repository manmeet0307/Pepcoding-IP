#include<bits/stdc++.h>
using namespace std;
class minStack{

public:

    stack<int> ds;
    stack<int> ms;
    void push(int x)
    {
        ds.push(x);
        if(ms.empty() || ms.top() > x)
        {
            ms.push(x);
        }
    }
    int pop()
    {
        if(ds.empty())return -1;
        int x = ds.top();
        ds.pop();
        if(!ms.empty() && ms.top() == x)
        {
            ms.pop();
        }
        return x;
    }
    int getmin()
    {
        return !ms.empty() ? ms.top() : -1;
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
      	  	   else if(q==2) cout<<fq.pop()<<" ";
      	  	   else if(q==3) cout<<fq.getmin()<<" ";
      	  	   i++;
      	   }
      	   //cout<<fq.mf<<endl;
}
