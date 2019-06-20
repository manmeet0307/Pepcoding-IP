#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    char data;
    Node * next;
    Node(char val)
    {
        data = val;
        next = NULL;
    }
};

void printll(Node * head)
{
    Node * t = head;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t = t->next;
    }
}

pair<Node*,Node*> insertnode(Node * head,Node * tail , Node * nn)
{
    if(head==NULL)
    {
        head=nn;
        tail=nn;
        return make_pair(head,tail);
    }
    tail->next = nn;
    tail = nn;
    return make_pair(head,tail);

}
bool checkcircular(Node * head)
{
    if(head==NULL)
    {
        return head;
    }
    Node * temp = head;
    while(temp!=NULL && temp->next !=head)
    {

        temp = temp->next;
    }
    if(temp==NULL)
    {

        return false;
    }
    else{
        return true;
    }
}
int main()
{
    Node* head = NULL,*tail=NULL;
    int n;
    char val;
    cin >> n;
    int s;
    cin>>s;
     pair<Node*,Node*> p(NULL,NULL);
    for(int i=0;i<n;i++)
    {
        cin>>val;
        Node * nn = new Node(val);
       p = insertnode(p.first,p.second,nn);
    }
    head = p.first;
    tail = p.second;

    if(s==1 && n>0)
    {
        tail->next = head;
    }
    if(checkcircular(head))
    {
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
