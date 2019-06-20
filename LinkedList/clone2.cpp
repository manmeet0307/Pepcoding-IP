#include<iostream>
#include<bits/stdc++.h>
    using namespace std;
    class Node {
        public:
        int data;
        Node* next;
        Node* arb;
        Node(int d) {
            data = d;
            next = arb = NULL;
        }
     };

    Node* head;
    Node* addLast(Node * h, Node *nn)
    {
        if(h==NULL)
        {
            return nn;
        }
        h->next = addLast(h->next,nn);
        return h;
    }
  void display(Node* head) {
        for (Node* node = head; node != NULL; node = node->next) {
            cout<<node->data<<" ";
        }
    }
Node * oddevensplit(Node * h)
{
    Node *o =NULL,*e =NULL;
    int c=0;
    while(h!=NULL)
    {
        Node * x=h;
        h = h->next;
        x->next=NULL;
        if(c%2==0)
        {
           o = addLast(o,x);
         //  display(o);
           cout<<endl;
        }
        else{
           e = addLast(e,x);
           //display(e);
           cout<<endl;
        }
        c++;
    }
    display(o);
    cout<<"/n";
    display(e);
    return e;

}
     /*This is a function problem.You only need to complete the function given below*/
     // function to copy linked list
     class Clone {
         public:
         Node* copyList(Node* n) {
             // your code here
             Node * curr=n->next , *p=n,*m=NULL;

             while(curr!=NULL)
             {
                 Node * x= new Node(p->data);
                 p->next = NULL;
                 m = addLast(m,p);
                 m = addLast(m,x);
                // m=addLast(curr);
                 p = curr;
                 curr = curr->next;
             }
             Node * x= new Node(p->data);
//p->next = NULL;
                 m = addLast(m,p);
                 m=addLast(m,x);
             display(m);
            Node *o =m , *t = m->next;
            while(t->next!=NULL)
            {
                t->arb = o->arb->next;
                if(o->next==NULL || t->next==NULL)
                    break;
                o = o->next->next;
                t = t->next->next;
                cout<<o->data<<" ";
                cout<<t->data<<" ";
                if(t->next==NULL)
                {
                    break;
                }
            }
           o->arb!=NULL ? t->arb = o->arb->next;
            return oddevensplit(m);
           // return m;
         }
     };

    void addToTheLast(Node* node) {
        if (head == NULL) {
            head = node;
        } else {
            Node* temp = head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = node;
        }
    }


    bool validation(Node* head, Node* res, Node* cloned_add,
                            Node* generated_add) {
        if (generated_add == cloned_add) return false;
        Node* temp1 = head;
        Node* temp2 = res;
        int len1 = 0, len2 = 0;
        while (temp1 != NULL) {
            len1++;
            temp1 = temp1->next;
        }
        while (temp2 != NULL) {
            len2++;
            temp2 = temp2->next;
        }
        /*if lengths not equal */
        if (len1 != len2) return false;
        temp1 = head;
        temp2 = res;
        while (temp1 != NULL) {
            if (temp1->data != temp2->data) return false;
            if (temp1->arb != NULL && temp2->arb != NULL) {
                if (temp1->arb->data != temp2->arb->data) return false;
            } else if (temp1->arb != NULL && temp2->arb == NULL)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }

    int main(int argc, char** argv) {
            Node* generated_add = NULL;
            int n, q, a1;
            cin>>n>>q>>a1;
            Node* head = new Node(a1);
            addToTheLast(head);
            for (int i = 1; i < n; i++) {
                int a;
                cin>>a;
                addToTheLast(new Node(a));
            }
            for (int i = 0; i < q; i++) {
                int a, b;
                cin>>a>>b;
                Node* tempA = head;
                int count = -1;
                while (tempA != NULL) {
                    count++;
                    if (count == a - 1) break;
                    tempA = tempA->next;
                }
                Node* tempB = head;
                count = -1;
                while (tempB != NULL) {
                    count++;
                    if (count == b - 1) break;
                    tempB = tempB->next;
                }
                // when both a is greater than N
                if (a <= n) tempA->arb = tempB;
            }
            generated_add = head;
            Clone* g = new Clone();
            Node* res = g->copyList(head);
            Node* cloned_add = res;
            display(res);
            // if (validation(head, res, cloned_add, generated_add) == true)
            //     cout<<"1";
            // else
            //     cout<<"false";

    }
