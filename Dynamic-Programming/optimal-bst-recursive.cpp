// A naive recursive implementation of
// optimal binary search tree problem
#include <bits/stdc++.h>
using namespace std;

// A utility function to get sum of
// array elements freq[i] to freq[j]
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
    s += freq[k];
    return s;
}
int optimalSearchTree(int keys[], int freq[],int n ,  int i , int j)
{
    if(i>j)
        return 0;
    if(i==j)
        return freq[i];
	//base case
	int omin = INT_MAX;
	 for(int r = i ; r<=j ; r++)
     {
         int leftcost = optimalSearchTree(keys , freq, r , 0 , r-1 );
         int rightcost = optimalSearchTree(keys,freq ,n-1-r, r+1 , j);
         omin = min(leftcost + rightcost , omin);
     }
     return omin + sum(freq,i,j);
}

// A utility function to get sum of
// array elements freq[i] to freq[j]


// Driver Code
int main()
{
	int keys[] = {10, 12, 20};
	int freq[] = {34, 8, 50};
	int n = sizeof(keys) / sizeof(keys[0]);
	cout << "Cost of Optimal BST is "
		<< optimalSearchTree(keys, freq, n , 0, n-1);
	return 0;
}

// This is code is contributed
// by rathbhupendra
