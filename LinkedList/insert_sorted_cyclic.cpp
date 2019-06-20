#include <iostream>
#include <vector>
using namespace std;

  class Node
  {
  public:
      int data;
      Node *next;

      Node(int data, Node *next)
      {
          this->data = data;
          this->next = next;
      }
  };

  Node *head = NULL;
  Node *tail = NULL;
  int size = 0;

  void insert(int data)
  {

      Node *nn = new Node(data, NULL);
      if (head == NULL)
      {
          head = nn;
          tail = nn;
          tail->next = head;
      }
      else
      {
          tail->next = nn;
          tail = nn;
          tail->next = head;
      }
      size++;
  }

    bool checkCyclic(Node * head) {
         if (head == NULL) {
             return true;
         }

         Node * curr = head;

         bool result = false;
         while (curr->next != NULL && curr->next != head) {
             curr = curr->next;
         }
         if (curr->next == head) {
             result = true;
         }

         return result;
     }

     bool checkSorted(Node* head) {
         if (head == NULL) {
             return true;
         }

         Node * curr = head;

         bool result = true;
         while (curr->next != NULL && curr->next != head) {
             if(curr->data > curr->next->data){
                 return false;
             }
             curr = curr->next;
         }

         return result;
     }

  void display(Node* head)
  {
        Node * node;
      for ( node = head; node->next != head; node = node->next)
      {
          cout << node->data << " ";
      }
      cout<< node->data;
  }

  //----------------------------------------------------
       //This is a functional problem. Only this function has to be written.
       //You should return the head of node after sorting.
  Node* sort(Node* head , int num)
  {
     Node * nn = new Node(num,NULL);
     Node * prev = head , *curr = head->next;
     if(prev->data > nn->data)
     {
         while(curr->next!=head)
            curr = curr->next;
         curr->next = nn;
         nn->next = head;
         return nn;
     }
     while(curr->next != head)
     {
         if(prev->data <= nn->data && curr->data > nn->data)
         {
             prev->next = nn;
             nn->next = curr;
         }
         prev = curr;
         curr = curr->next;
     }
     if(curr->data < nn->data)
     {
         curr->next = nn;
         nn->next = head;
     }
     return head;
  }
  //----------------------------------------------------

  int main()
  {
      //Input managed
      int n=0;
      cin >> n;

      for(int i=0; i<n; i++)
      {
          int a = 0;
          cin >> a;
          insert(a);
      }
     int num;
     cin>>num;
      // cal to the function
     head = sort(head , num);
        if (checkCyclic(head) && checkSorted(head)) {
             cout<<"1";
         } else {
             cout<<"0";
         }
      //output handled
     // display(sortedHead);
     // display(head);
      return 0;
  }
