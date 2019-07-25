#include<bits/stdc++.h>
using namespace std;
class Treenode{
public :
    int data ;
    Treenode * left , *right;
    Treenode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Treenode * deserialize(int * arr , int n)
{
    Treenode * r = NULL;
    Treenode* nodes[n];
    nodes[0] = NULL;
    for(int i = 1; i<n;i++)
    {
        nodes[i] =  new Treenode(0);
    }

    for(int i = 1 ; i< n ; i++)
    {
        if(arr[i] == 0)
        {
            r = nodes[i];
            continue;
        }
        int pari = arr[i];
        Treenode * p = nodes[pari];
        p->data = pari;
        Treenode * c = nodes[i];
        c ->data = i;
        if(p->left == NULL)
        {
            p->left = c;
        }
        else
        {
            p->right = c;
        }
    }
    return r;
}

 void levelorder(Treenode* root) {
    if(root == NULL)
    {
        return ;
    }
    queue<Treenode*> q;
    q.push(root);
    while(!q.empty())
    {
        int c = q.size();
        while(c--)
        {
            Treenode * curr = q.front();
            cout<<curr->data<<" ";
            q.pop();

            if(curr->left !=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right !=NULL)
            {
                q.push(curr->right);
            }
        }
        cout<<endl;
    }
 }

int main()
{
    int arr[] = {-1 , 0 , 1 , 1 , 2 , 2,3 ,5 , 5 ,6 , 6 , 3} ;
    Treenode * r = deserialize(arr , 12);
    levelorder(r);
}
