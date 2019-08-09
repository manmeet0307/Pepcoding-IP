#include<bits/stdc++.h>
using namespace std;
double dist(int input[][2] , int i , int j)
{
    double d1 = sqrt(pow(input[i][0] - input[j][0] , 2 )  + (pow(input[i][1]-input[j][1],2)));

    return d1;
}
double fun(int input[][2] , int sp , int x)
{
    double maxdist = 0;
    for(int i = 0; i < x;i++)
    {
        for(int j = i+1 ; j < x ; j++)
        {
           cout<<maxdist<<endl;
           maxdist = max(dist(input , i , j) , maxdist);
        }
    }
    cout<<fixed<<setprecision(6);
    double ans =  1.0*maxdist/sp;
    return ans;
}
int main()
{
    int input[][2] = {{0,0} , {-2,2} , {2,2}, {1,0}};
    cout<<fun(input , 4 , 4);
}
