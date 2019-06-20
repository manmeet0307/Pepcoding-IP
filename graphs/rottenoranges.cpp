#include<bits/stdc++.h>
using namespace std;
class helper {
public:
    int x,y,time;
    helper(int a, int b, int c)
    {
        x = a;
        y = b;
        time = c;
    }
};
bool isvalid(int c[][100],int x,int y,int n,int m)
{
    if(x<0 || y<0 || x>=n || y>= m)
    {
        return false;
    }
    if(c[x][y]==0 || c[x][y]==2)
    {
        return false;
    }
    return true;
}
// n rows m col
int oranges(int chessboard[][100],int n,int m)
{

    queue<helper> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(chessboard[i][j]==2)
            {
                q.push(helper(i,j,0));
            }
        }
    }
    int time = 0;
    while(!q.empty())
    {
        helper t = q.front();

        q.pop();
        chessboard[t.x][t.y] = 2;
        //work
        time = t.time;

        if(isvalid(chessboard,t.x+1,t.y ,n,m))
        {
            q.push(helper(t.x + 1,t.y ,t.time + 1));
            chessboard[t.x + 1][t.y] = 2;
        }
        if(isvalid(chessboard,t.x -1, t.y ,n,m))
        {
            q.push(helper(t.x - 1, t.y ,t.time+1));
             chessboard[t.x - 1][t.y] = 2;
        }
        if(isvalid(chessboard,t.x ,t.y + 1,n,m))
        {
            q.push(helper(t.x,t.y+1,t.time+1));
             chessboard[t.x][t.y+1] = 2;
        }
        if(isvalid(chessboard,t.x ,t.y - 1,n,m))
        {
            q.push(helper(t.x,t.y - 1,t.time+1));
             chessboard[t.x][t.y - 1] = 2;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m ;j++)
        {
            if(chessboard[i][j]==1)
            {
                time = -1;
            }
        }
    }
    return time;
}
void input(int n,int m)
{
    int chessboard[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>chessboard[i][j];
        }
    }

    cout<<oranges(chessboard,n,m);
}

int main()
{
    int n,m;
    cin>>n>>m;
    input(n,m);
}
