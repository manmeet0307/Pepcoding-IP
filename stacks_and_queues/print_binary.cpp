#include<bits/stdc++.h>
using namespace std;
class Pair{
public:
    int num;
    string s;
    Pair(int num,string s1)
    {
        this->num = num;
        this->s = s1;
    }
};
void printbinary(int n)
{
    queue<Pair> q;
    q.push(Pair(1,"1"));
    while(!q.empty())
    {
        Pair p = q.front();
        q.pop();
        cout<< p.s<<" ";
        if(p.num *2 <=n)
        q.push(Pair(p.num *2 , p.s +"0"));
        if(((p.num * 2) +1) <=n)
        q.push(Pair((p.num *2 )+ 1 , p.s +"1"));
    }
}
int main()
{
    int n;
    cin>>n;
    printbinary(n);
}
