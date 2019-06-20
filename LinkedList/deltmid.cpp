#include <iostream>
#include <vector>
#include<unordered_map>
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
      }
      else
      {
          tail->next = nn;
          tail = nn;
      }
      size++;
  }
 Node * mid(Node * head,int x)
   {
      Node * slow = head, *fast = head->next;


    //   cout<<x;
       if(x%2==0)
       {
           while(fast->next != NULL)
           {
               slow = slow->next;
               fast = fast->next->next;
           }
       }
       else{
           while(fast->next->next != NULL)
           {
               slow = slow->next;
               fast = fast->next->next;
           }
       }
       return slow;
   }
   Node * dltmid(Node* h,int n)
   {
       if(h==NULL || h->next==NULL)
        return NULL;
        Node* m = mid(h,n);
        m->next = m->next->next;
        return h;
   }
  void display(Node* head)
  {
      for (Node *node = head; node != NULL; node = node->next)
      {
          cout << node->data << " ";
      }
  }

  //----------------------------------------------------
       //This is a functional problem. Only this function has to be written.
       //You should return the head of node after sorting.
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
      //output handled
      display(dltmid(head,n));
      return 0;
  }
