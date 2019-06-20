#include <iostream>
 #include <vector>
 using namespace std;

 int mustangTour(vector<int> &petrol, vector<int> &dist)
 {
 	 // Write your code here
    int n = petrol.size();
    int i = 0,j = 0, spare = 0;
    while(1)
    {
        if(spare < 0)
        {
            if(j<=i)
                break;
            i = j;
            spare = 0;
        }
        else
        {
            spare = spare + petrol[j] - dist[j] ;
             j = (j+1)%n;
            if(spare>=0 && i==j)
                return i;

        }
        cout<<i<<" "<<j<<" "<<spare<<endl;

    }
    return -1;
 }

 // Dont make changes here
 int main()
 {

 	 int n;
 	 cin >> n;
 	 vector<int> petrol(n, 0), dist(n, 0);
 	 for (int i = 0; i < n; i++)
 	 	 cin >> petrol[i];
 	 for (int i = 0; i < n; i++)
 	 	 cin >> dist[i];
 	 cout << mustangTour(petrol, dist) << endl;
 	 return 0;
 }
