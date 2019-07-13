#include<bits/stdc++.h>                                                                                                                                                                                                                   #include<bits/stdc++.h>
using namespace std;
int minimumSquare(int h, int w , int **dp)
{
	if(h==0 || w==0 )
        return 0;


    if(dp[h][w] != -1)
    {
        return dp[h][w];
    }
    int omin = INT_MAX;
    for(int x = 1;  x <= min(h,w) ; x++)
    {
        int r1hh = x;
        int r1hw = w-x;
        int r2hh = h-x;
        int r2hw = w;

        int r1vh = h-x;
        int r1vw = x;
        int r2vh = h;
        int r2vw = w-x;

        int f1 = minimumSquare(r1hh , r1hw , dp);
        int f2 = minimumSquare(r2hh , r2hw , dp);
        int f3 = minimumSquare(r1vh , r1vw , dp);
        int f4 = minimumSquare(r2vh , r2vw , dp);
        //cout<<x<<" f1 = " <<f1 << " f2 = "<<f2<< " f3= "<<f3<< " f4 = "<<f4<<endl;
        omin = min(omin , min(f1+f2 , f3+f4));
    }

    dp[h][w] = omin +1;
    return omin+1;
}
int main()
{
	int m = 30, n = 35;
	int ** dp = new int * [m+1];
	for(int i = 0; i < m+1; i++)
    {
        dp[i] = new int[n+1];
        for(int j=0;j<n+1;j++)
        {
            dp[i][j] = -1;
        }
    }
	cout << minimumSquare(m, n, dp);
	return 0;
}
