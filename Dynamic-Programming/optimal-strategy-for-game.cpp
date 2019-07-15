#include <bits/stdc++.h>
using namespace std;
int optimalStrategyOfGame(int* arr, int i,int j)
{
  if(i>j)
  {
      return 0;
  }
  if(i==j)
  {
      return arr[i];
  }
  if(arr[i] > arr[j])
  {
      return arr[i] + min(optimalStrategyOfGame(arr , i+2,j-1 ) , optimalStrategyOfGame(arr,i+1,j-2));
  }
  else
  {
      return arr[j] + min(optimalStrategyOfGame(arr , i+2,j-1 ) , optimalStrategyOfGame(arr,i+1,j-2));
  }
}
int main()
{
    int arr1[] = { 8, 15, 3, 7 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", optimalStrategyOfGame(arr1,0, n-1));

    int arr2[] = { 2, 2, 2, 2 };
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n", optimalStrategyOfGame(arr2,0, n-1));

    int arr3[] = { 20, 30, 2, 2, 2, 10 };
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n", optimalStrategyOfGame(arr3,0, n-1));

    return 0;
}
