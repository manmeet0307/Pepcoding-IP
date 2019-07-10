#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countWays(int N)
{
    vector<int> b(N,0),s(N,0);
    b[0] = 1, s[0] = 1;
    for(int i=1 ; i<N ; i++)
    {
        b[i] = s[i-1];
        s[i] = b[i-1] + s[i-1];
    }
    int ans = b[N-1] + s[N-1];
    return ans * ans;
}

int main()
{
	int N = 4;
	cout << "Count of ways for " << N << " sections is " << countWays(N);
	return 0;
}
