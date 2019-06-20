#include<bits/stdc++.h>
using namespace std;
class helper {
public:
    int x,y,level;
    helper(int a, int b, int c)
    {
        x = a;
        y = b;
        level = c;
    }
};
bool isvalid(int c[][100],int x,int y,int n)
{
    if(x<0 || y<0 || x>=n || y>= n)
    {
        return false;
    }
    if(c[x][y]==1)
    {
        return false;
    }
    return true;
}
int knightpos(int sx,int sy,int dx,int dy,int n)
{
    int chessboard[100][100];
    memset(chessboard, 0 ,sizeof(chessboard));
    chessboard[sx][sy] = 1;
    //chessboard[dx][dy] = 1;
    queue<helper> q;
    q.push(helper(sx,sy,0));
    while(!q.empty())
    {
        //cout<<"here";
        helper t = q.front();
       /* if(chessboard[t.x][t.y]==1)
        {
            continue;
        }*/
        q.pop();
        chessboard[t.x][t.y] = 1;
        if(t.x == dx && t.y == dy)
        {
            return t.level;
        }
        if(isvalid(chessboard,t.x + 2,t.y + 1,n))
        {
            q.push(helper(t.x+2,t.y+1,t.level+1));
            chessboard[t.x+2][t.y+1] = 1;
        }
        if(isvalid(chessboard,t.x + 2,t.y - 1,n))
        {
            q.push(helper(t.x+2, t.y-1 ,t.level+1));
             chessboard[t.x+2][t.y-1] = 1;
        }
        if(isvalid(chessboard,t.x - 2,t.y + 1,n))
        {
            q.push(helper(t.x-2,t.y+1,t.level+1));
             chessboard[t.x-2][t.y+1] = 1;
        }
        if(isvalid(chessboard,t.x - 2,t.y - 1,n))
        {
            q.push(helper(t.x-2,t.y-1,t.level+1));
             chessboard[t.x-2][t.y-1] = 1;
        }
        if(isvalid(chessboard,t.x + 1,t.y + 2,n))
        {
            q.push(helper(t.x+1,t.y+2,t.level+1));
             chessboard[t.x+1][t.y+2] = 1;
        }
        if(isvalid(chessboard,t.x + 1,t.y - 2,n))
        {
            q.push(helper(t.x + 1 ,t.y - 2, t.level + 1));
             chessboard[t.x+1][t.y-2] = 1;
        }
        if(isvalid(chessboard,t.x - 1,t.y + 2,n))
        {
            q.push(helper(t.x - 1,t.y + 2,t.level+1));
             chessboard[t.x - 1][t.y + 2] = 1;
        }

        if(isvalid(chessboard,t.x - 1,t.y - 2,n))
        {
            q.push(helper(t.x-1,t.y-2,t.level+1));
             chessboard[t.x - 1][t.y - 2] = 1;
        }

    }
    return -1;
}
int main()
{
    int sx, sy, dx, dy,n;
    cin>>n>>sx>>sy>>dx>>dy;
    cout<<knightpos(sx-1,sy-1,dx-1,dy-1,n);
}
