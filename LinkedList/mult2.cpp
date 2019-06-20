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
long mult(Node * h1 , Node * h2)
{
    long a = 0;
     long mod = 1000000007;
    while(h1!=NULL)
    {
        a = ((a*10) + h1->data)%mod;
        h1 = h1->next;
    }
    long b = 0;
    while(h2!=NULL)
    {
        b = ((b*10) + h2->data)%mod;
        h2 = h2->next;
    }

   return (a*b) %mod;
}
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
        cout<<mult(head1,head2);
    }
