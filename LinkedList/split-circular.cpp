#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
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

   void addLast(Node *&head, Node* &tail,int data)
   {
       if(head == NULL)
       {
           head =  new Node(data,NULL);
           tail = head;
           tail->next = head;
       }
       else{
        tail->next  = new Node(data,NULL);
        tail = tail->next;
        tail->next = head;
       }
   }
   int len(Node * h)
   {
       Node * t=h;
       int c=1;
       while(t->next!=h)
       {
           t= t->next;
           c++;
       }
       return c;
   }
   Node * mid(Node * head)
   {
      Node * slow = head, *fast = head->next;

       int x = len(head);
    //   cout<<x;
       if(x%2==0)
       {
           while(fast->next != head)
           {
               slow = slow->next;
               fast = fast->next->next;
           }
       }
       else{
           while(fast != head)
           {
               slow = slow->next;
               fast = fast->next->next;
           }
       }
       return slow;
   }
   vector<Node*> split(Node * h)
   {
       Node * m = mid(h);
       Node * mn = m->next;
       m->next = h;
       Node * t=mn ;
       while(t->next != h)
        t = t->next;
       t->next=mn;
       return vector<Node*>{h,mn};
   }
    void display(Node* head) {
        Node* node;
        for ( node = head; node->next != head; node = node->next) {
            cout<<node->data<<" ";
        }
        cout<<node->data<<endl;;
    }
    int main(int argc, char** argv) {
        int n1;
        cin>>n1;

        for (int i = 0; i < n1; i++) {
            int a;
            cin>>a;
            addLast(head1,tail1, a);
        }
        if(n1==1){
        cout<<head1->data;
        return 0;
        }
vector<Node*> v = split(head1);
display(v[0]);
display(v[1]);

    }
