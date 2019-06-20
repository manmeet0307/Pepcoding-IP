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
      }
      else
      {
          tail->next = nn;
          tail = nn;
      }
      size++;
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
  Node* rearrange(Node* head)
  {
      if(head==NULL || head->next == NULL)
      {
          return head;
      }
      Node * oh = NULL , *ot = NULL  , *eh = NULL , *et = NULL;
      int c = 1;
      Node * t = head;
      while(t!=NULL)
      {
          Node * curr = t;
          t = t->next;
          curr->next = NULL;

          if(c%2!=0)
          {
              if(oh == NULL)
              {
                  oh = curr , ot = curr;
              }
              else
              {
                    ot->next = curr;
                    ot = ot->next;
              }
          }
          else
          {
             if(eh == NULL)
              {
                  eh = curr , et = curr;
              }
              else
              {
                    et->next = curr;
                    et = et->next;
              }
          }
          c++;
      }
    ot->next = eh;
    return oh;
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
      // cal to the function
      Node* sortedHead = rearrange(head);

      //output handled
      display(sortedHead);
      return 0;
  }
