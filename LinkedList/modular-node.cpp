#include<iostream>
#include<unordered_set>
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
    // This function takes as input the head of the linked list.
    // It should return the head of the modified list.

    int deletelast(Node* head,int k) {
       // Node * pocc=NULL, *currocc=NULL,*prev = NULL;
        bool f =0;
        int c=1,ans=-1;
        Node * m = head;
        while(head!=NULL)
        {
            if(c%k==0)
            {

                ans = head->data;
                f=1;
            }
            head = head->next;
            c++;
        }
        if(f==0)
            return -1;

        return ans;

    }

    // -----------------------------------------------------

    int main(int argc, char** argv) {
        int n1;
        cin>>n1;

        for (int i = 0; i < n1; i++) {
            int a;
            cin>>a;
            head1 = insert(head1, a);
        }
        int k;
        cin>>k;

        cout<<deletelast(head1,k);
    }
