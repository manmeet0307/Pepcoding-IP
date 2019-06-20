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
bool isvowel(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
    {
        return true;
    }
    return false;
}
Node * vowelbefore(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node * vh = NULL, *vt = NULL , *ch = NULL,*ct=NULL;
    if(isvowel(head->data))
    {
        vh = head,vt = head;
    }
    else{
        ch = head,ct = head;
    }
    Node * temp = head->next;
    while(temp!=NULL)
    {

        if(isvowel(temp->data))
        {
            if(vt!=NULL)
            {
                vt->next = temp;
                vt = temp;
            }
            else{
                vh = temp,vt = temp;
            }
        }
        else{
             if(ct!=NULL)
            {
                ct->next = temp;
                ct = temp;
            }
            else{
                ch = temp,ct = temp;
            }

        }
        temp = temp->next;
    }
    if(vt==NULL)
    {
        return ch;
    }
    vt->next = ch;
    if(ct!=NULL)
        ct->next = NULL;
return vh;
}
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
int main()
{
    Node* head = NULL,*tail=NULL;
    int n;
    char val;
    cin >> n;
     pair<Node*,Node*> p(NULL,NULL);
    for(int i=0;i<n;i++)
    {
        cin>>val;
        Node * nn = new Node(val);
       p = insertnode(p.first,p.second,nn);
    }
    head = p.first;
    tail = p.second;
    printll(vowelbefore(p.first));
}
