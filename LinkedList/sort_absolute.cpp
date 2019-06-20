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
  Node* sort(Node* head)
  {
      if(head==NULL || head->next==NULL)
      {
          return head;
      }
      Node * xh = NULL, *xt = NULL;
      Node * yh = NULL , *yt = NULL;
      Node * t = head;
      while(t!=NULL)
      {
          if(t->data < 0)
          {
              if(xh == NULL)
              {
                  xh = t;
                  xt = t;
                  t = t->next;
                  xt->next = NULL;
              }
              else
              {
                   Node * temp = t;
                   t=t->next;
                   temp->next = xh;
                   xh = temp;
              }
          }
          else{
            if(yh == NULL)
              {
                  yh = t;
                  yt = t;
                  t = t->next;
                  yt->next = NULL;
              }
              else{
                yt->next = t;
                t = t->next;
                yt = yt->next;
                yt->next = NULL;
              }
          }
      }
      if(xh==NULL)  return yh;
      xt->next = yh;
      return xh;
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
      Node* sortedHead = sort(head);

      //output handled
      display(sortedHead);
      return 0;
  }
