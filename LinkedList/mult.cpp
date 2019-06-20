#include<iostream>
#include<cmath>
using namespace std;

    // Class declaration for a Node of the Linked List
    class Node {
        public:
        int data;
        Node* next;

        Node(int data,Node * next) {
            this->data = data;
            this->next = NULL;
        }
    };

    Node* head1;
    Node *head2;
    Node* tail1;
    Node * tail2;

    /*
    * Input Parameters: head: head of the linked list in which a new node is to
    * be inserted. data: the data value of the node which is to be inserted.
    *
    * Return Value: head of the linked list in which the node is inserted
    */
   void addLast(Node *&head, Node* &tail,int data)
   {
       if(head == NULL)
       {
           head =  new Node(data,NULL);
           tail = head;
       }
       else{
        tail->next  = new Node(data,NULL);
        tail = tail->next;
       }
   }
    void display(Node* head) {
        for (Node* node = head; node != NULL; node = node->next) {
            cout<<node->data;
        }
    }
    void rpi(Node * &head)
    {
        Node * prev=NULL, * curr =head;
        while(curr!=NULL)
        {

            Node * nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        head = prev;
    }
    Node * add(Node * h1, Node * h2)
    {
        /*if(h1==NULL)
        {
            h1 = h2;
        }*/
        Node * ys =NULL, *yt=NULL;
        rpi(h1),rpi(h2);
        Node * t1 = h1, *t2 = h2;
        int c =0;
        while(t1!=NULL && t2 != NULL)
        {
            int d = (t1->data + t2->data +c)%10;
            c = (t1->data + t2->data + c)/10;
            addLast(ys,yt,d);
            t1 = t1->next;
            t2 = t2->next;
        }

       while(t1!=NULL)
       {
            int d = (t1->data +c)%10;
            c = (t1->data + c)/10;
            addLast(ys,yt,d);
            t1 = t1->next;
       }
       while(t2!=NULL)
       {
            int d = (t2->data +c)%10;
            c = (t2->data + c)/10;
            addLast(ys,yt,d);
            t2 = t2->next;
       }

        if(c==1)
        {
            addLast(ys,yt,c);
        }
        rpi(ys);
        return ys;

    }
    Node* mult(Node * head1,Node * head2)
    {
        Node * t1 = head1,*t2 = head2;
        int z = 0;
        rpi(t1), rpi(t2);
       // display(t1);
        //cout<<endl;
        //display(t2);
        //cout<<endl;
        Node *m =NULL,*mt=NULL;
        while(t2!=NULL)
        {
            Node * sm = NULL,*smt = NULL;
            for(int i=0;i<z;i++)
            {
                addLast(sm,smt,0);
            }
            int carry = 0;
            while(t1!=NULL)
            {
                int num = (t1->data * t2->data)+carry;
                int dig = (num)%10;
                 carry = num /10;
                addLast(sm,smt,dig);
                t1 = t1->next;
            }
            if(carry!=0)
            {
                addLast(sm,smt,carry);
            }
            m = add(m,sm);
            // display(m);
            // cout<<endl;
            z++;
            t2 = t2->next;
        }
        rpi(m);
        return m;
    }
long convert(Node * h)
{
    long a = 0;
    while(h!=NULL)
    {

        a = ((a*10)%1000000007 + (h->data + 0l))%1000000007;
       // a = a*10 +h->data;
        h = h->next;
    }
    return a;
}
    // -----------------------------------------------------

    int main(int argc, char** argv) {
        int n1;
        cin>>n1;

        for (int i = 0; i < n1; i++) {
            int a;
            cin>>a;
            addLast(head1,tail1, a);
        }
        int n2;
        cin>>n2;

        for (int i = 0; i < n2; i++) {
            int a;
            cin>>a;
            addLast(head2,tail2, a);
        }
        Node * y = mult(head1,head2);

        display(y);

    }
