#include<bits/stdc++.h>
using namespace std;
class FreqStack{

public:
    int mf;
    unordered_map<int,int> m1;
    unordered_map<int,stack<int>>m2;
    FreqStack()
    {
        mf = 0;
    }
    void push(int x)
    {
        m1[x]++;
        m2[m1[x]].push(x);
        if(m1[x] > mf)
        {
            mf = m1[x];
        }
    }
    int pop()
    {
        int x = m2[mf].top();
        m2[mf].pop();
        if(m2[mf].empty())
        {
            mf--;
        }
        m1[x]--;
        return x;
    }
};
int main()
{
    FreqStack fq;
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
      	  	   i++;
      	   }
      	   //cout<<fq.mf<<endl;
}
