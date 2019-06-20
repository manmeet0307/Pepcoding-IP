#include<iostream>
    using namespace std;

    // Class declaration for a Node of the Linked List
    class Node {
        public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
    };

    Node* head1;

    /*
    * Input Parameters: head: head of the linked list in which a new node is to
    * be inserted. data: the data value of the node which is to be inserted.
    *
    * Return Value: head of the linked list in which the node is inserted
    */
    Node* insert(Node* head, int data) {

        if (head == NULL) {
            Node* nn = new Node(data);
            return nn;
        }

        head->next = insert(head->next, data);
        return head;
    }

    void display(Node* head) {
        for (Node* node = head; node != NULL; node = node->next) {
            cout<<node->data<<" ";
        }
    }
    // -----------------------------------------------------
    // This is a functional problem. Only this function has to be written.
    // This takes as input the head of the linked list and x.
    // It should return the head of the modified list.
      void addLast(Node * &h,Node * &t, Node *nn)
    {
        if(h==NULL)
        {
            h = nn,t = nn;
        }
        else{
        t->next = nn;
        t = nn;
        }
    }
    Node* partition(Node* n, int m) {
    // write your code here
     Node *oh =NULL ,*ot =NULL,*eh =NULL,*et = NULL , *h = n;
    while(h!=NULL)
    {
        Node * x=h;
        h = h->next;
        x->next=NULL;
        if(x->data<m)
        {
            addLast(oh,ot,x);

        }
        else{
           addLast(eh,et,x);
        }

    }
        if(oh==NULL)
            return eh;
        ot->next = eh;
        return oh;


    }// -----------------------------------------------------

    int main(int argc, char** argv) {
        int n1;
        cin>>n1;

        for (int i = 0; i < n1; i++) {
            int a;
            cin>>a;
            head1 = insert(head1, a);
        }

        int x;
        cin>>x;

        head1 = partition(head1, x);
        display(head1);

    }
