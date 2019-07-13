#include<bits/stdc++.h>
using namespace std;
bool mycomp(pair<int,int> p1 , pair<int ,int> p2 )
{
    return p1.second < p2.second;
}
void printMaxActivities(int s[], int f[], int n)
{
    vector<pair<int,int>> v ;
    for(int i=0;i<n;i++)
    {
        v.push_back(make_pair(s[i] , f[i]));
    }
    sort(v.begin() , v.end() , mycomp);
    int pendtime = 0;
    for(int i=0;i< n;i++)
    {
        if(v[i].first > pendtime)
        {
            cout<< i<<" ";
            pendtime = v[i].second;
        }
    }
}

// driver program to test above function
int main()
{
	int s[] = {1, 3, 0, 5, 8, 5};
	int f[] = {2, 4, 6, 7, 9, 9};
	int n = sizeof(s)/sizeof(s[0]);
	printMaxActivities(s, f, n);
	return 0;
}
