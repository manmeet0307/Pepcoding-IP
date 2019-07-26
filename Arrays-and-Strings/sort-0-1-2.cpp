
#include<bits/stdc++.h>
using namespace std;
void sort012(int arr[], int n)  {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing output is handled automatically.
     */
    int low= 0 , mid , high =n-1;
    for(; low < n ; low++)
    {
        if(arr[low] !=0)
        {
            break;
        }
    }
    mid = low ;
    for(; mid < n ; mid++)
    {
        if(arr[mid] != 1 )
        {
            break;
        }
    }
    while( high >=0)
    {
        if(arr[high] != 2)
        {
            break;
        }
        high--;
    }
    while(mid <= high )
    {
        if(arr[mid] == 2)
        {
            swap(arr[mid],arr[high]);
            high--;
        }
        else if(arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }
        else
        {
            mid++;
        }
    }

}

int main() {
	//code
	int t;
	cin>> t;
	while(t--)
	{
	    int n;
	    cin>>n;

	int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort012(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
	}
	return 0;
}
