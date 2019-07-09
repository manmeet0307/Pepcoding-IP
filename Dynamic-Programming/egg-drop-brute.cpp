#include<bits/stdc++.h>
using namespace std;

// A utility function to get maximum of two integers
int max(int a, int b) { return (a > b)? a: b; }

/* Function to get minimum number of trials needed in worst
case with n eggs and k floors */
int eggDrop(int n, int k)
{
    if(n==1)
        return k;
    if(k==1 || k==0)
        return k;
    int mans = INT_MAX;
    for(int floor = 1;floor<=k;floor++)
    {
        int ans = max(eggDrop(n-1 ,floor-1 ) ,eggDrop(n , k-floor) );
        mans = min(mans , ans);
    }
    return mans+1;
}

int main()
{
	int n = 2, k = 10;
	cout << "Minimum number of trials in worst case with "
		<< n << " eggs and " << k << " floors is "
		<< eggDrop(n, k) << endl;
	return 0;
}
