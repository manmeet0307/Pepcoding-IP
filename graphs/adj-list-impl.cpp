#include<bits/stdc++.h>
using namespace std;
class edge{
public:
    int nbr;
    int wt;
};
vector<vector<edge>> graph;
void addedge(int s, int d , int wt)
{
    edge e;
    e.nbr = d;
    e.wt = wt;
    graph[s].push_back(e);;
    edge e2;
    e2.nbr = s;
    e2.wt = wt;
    graph[d].push_back(e2);
}

void display()
{
    for(int i = 0 ; i  < graph.size() ; i++)
    {
        cout<<i<<" -> ";
        for(int j = 0 ; j < graph[i].size() ; j++)
        {
            cout<<"[ " <<graph[i][j].nbr<<" " <<graph[i][j].wt<< " ] ";
        }
        cout<<endl;
    }
}
void printallpaths(int s , int d , string psf , int dsf, vector<bool> & visited)
{
    if(s == d)
    {
        cout<<psf<<d<<" @ "<<dsf<<endl;
        return ;
    }
    visited[s] = true;
    for(int i = 0 ; i < graph[s].size() ; i++)
    {
        if(!visited[graph[s][i].nbr])
        printallpaths(graph[s][i].nbr , d, psf + to_string(s),dsf + graph[s][i].wt , visited);
    }
    visited[s] = false;
}
bool haspath(int s, int d , vector<bool> &visited)
{
    if(s == d)
    {
        return true;
    }
    visited[s] = true;
    for(int i = 0; i < graph[s].size() ; i++)
    {
        if(!visited[graph[s][i].nbr])
        {
            bool pfromnbr = haspath(graph[s][i].nbr , d , visited);
            if(pfromnbr)
                return true;
        }
    }
    return false;
}
int main()
{
    graph.push_back(vector<edge>());
    graph.push_back(vector<edge>());
    graph.push_back(vector<edge>());
    graph.push_back(vector<edge>());
    graph.push_back(vector<edge>());
    graph.push_back(vector<edge>());
    graph.push_back(vector<edge>());

    addedge(0,1,10);
    addedge(1,2,10);
    addedge(2,3,10);
    addedge(3,0,40);
    addedge(3,4,2);
    addedge(4,5,3);
    addedge(5,6,3);
    addedge(6,4,8);

    display();
    vector<bool> visited(7,0);
    printallpaths(0 , 6 , "" , 0 , visited);

}
