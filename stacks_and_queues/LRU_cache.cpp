#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node * prev , *next;

    Node(int n)
    {
        data = n;
        prev = NULL;
        next = NULL;
    }
};

void display(Node * h)
{
    for(Node * t= h;t !=NULL;t=t->next)
    {
        cout<<t->data<<" ";
    }
}
class LruCache{
    int cap;
    Node * h;
    Node * t;
    int size ;
    unordered_map<int,Node *> m;
public:
    LruCache(int n)
    {
        cap = n;
        h = NULL;
        t = NULL;
        size = 0;
    }
    void set(int key,int val)
    {
        if(m.count(key)==0)
        {
           if(size == cap && cap != 1)
           {
              // Node * x =t->next;
              t->prev->next = NULL;
               unordered_map<int,Node*> :: iterator it;
               for(it = m.begin();it!=m.end();it++)
               {
                   if(it->second == t)
                   {
                       m.erase(it->first);
                       break;
                   }
               }
               t = t->prev;
               size--;

           }
           else if(size==cap && cap ==1)
           {
               h = t = NULL;
               m.clear();
               size--;
           }
            Node * n = new Node(val);
             m[key] = n;
             size++;
             if(h==NULL)
             {
                 h = n, t =n;
             }
             else
             {
                 h->prev = n;
                 n ->next = h;
                 h = n;
             }

        }
        else{
            Node * n = m[key];
            n->data = val;
            Node * x = n;
            if(x==h)
            {

                return ;
            }
            else if(x==t)
            {
                t = t->prev;
                t->next = NULL;
                h->prev = x;
                x->next = h;
                x->prev = NULL;
                h = x;
                return ;
            }
            Node * temp = h;
            while(temp->next != x)
            {
                temp = temp->next;
            }
            temp->next = x->next;
            x->next->prev = temp;

            n->next = h;
            h->prev = n;
            h = n;
        }
    }
    int get(int y)
    {
        if(m.count(y) == 1)
        {

            Node * n = m[y];
           Node * x = n;
            if(x==h)
            {
                return n->data;
            }
            else if(x==t)
            {

                t = t->prev;
                t->next = NULL;
                h->prev = x;
                x->next = h;
                x->prev = NULL;
                h = x;
                return h->data;
            }
            Node * temp = h;
            while(temp->next != x)
            {
                temp = temp->next;
            }
            temp->next = x->next;
            x->next->prev = temp;

            n->next = h;
            h->prev = n;
            h = n;
            return n->data;
        }
        else
        {
            return -1;
        }

    }

};
int main()
{
    int cap;
    cin>>cap;
    LruCache lc(cap);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
     	 	 string op;
     	 	 cin>>op;
     	 	 if(op=="SET"){
     	 	 	 int x;
     	 	 	 int y;
     	 	 	 cin>>x>>y;
     	 	 	 lc.set(x, y);
     	 	 }
     	 	 else if(op == "GET"){
     	 	 	 int x;
     	 	 	 cin>>x;
     	 	 	 cout<<lc.get(x)<<endl;
     	 	 }
     	 }
}
