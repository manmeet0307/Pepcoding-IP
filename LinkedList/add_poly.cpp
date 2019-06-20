#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

  class Node
  {
  public:
      int coeff;
      int power;
      Node *next;

      Node(int data,int p, Node *next)
      {
          this->coeff = data;
          power = p;
          this->next = next;
      }
  };

  Node *head1 = NULL;
  Node *tail1 = NULL;

  Node *head2 = NULL;
  Node *tail2 = NULL;
  int size = 0;

  void insert(Node * &head , Node * &tail,int data ,int p)
  {

      Node *nn = new Node(data,p, NULL);
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
  Node * addpoly(Node * h1 , Node * h2)
  {
      Node * t3;
      if(h1->power > h2->power)
      {
          Node * x = new Node(h1->coeff,h1->power , NULL);
          t3 = x;
          h1 = h1->next;

      }
      else if(h1->power < h2->power)
      {
          Node * x = new Node(h2->coeff,h2->power , NULL);
          t3 = x;
          h2 = h2->next;
      }
      else{
          Node * x = new Node(h1->coeff + h2->coeff,h1->power , NULL);
          t3 = x;
          h1 = h1->next;
          h2 = h2->next;
      }
      Node * h3 = t3;
      while(h1!=NULL && h2 != NULL)
      {
        if(h1->power > h2->power)
        {
          Node * x = new Node(h1->coeff,h1->power , NULL);
          t3->next = x;
          h1 = h1->next;
        }
        else if(h1->power < h2->power)
        {
          Node * x = new Node(h2->coeff,h2->power , NULL);
          t3->next = x;
          h2 = h2->next;
        }
        else{
          Node * x = new Node(h1->coeff + h2->coeff,h1->power , NULL);
          t3->next = x;
          h1 = h1->next;h2 = h2->next;
        }
        t3 = t3->next;
      }
      while(h1!=NULL)
      {
          Node * x = new Node(h1->coeff,h1->power , NULL);
          t3->next = x;
          h1 = h1->next;
          t3 = t3->next;
      }
      while(h2!=NULL)
      {
          Node * x = new Node(h2->coeff,h2->power , NULL);
          t3->next = x;
          h2 = h2->next;
          t3 = t3->next;
      }

      return h3;
  }
  void display(Node* head)
  {
      Node * node;
      for ( node = head; node->next != NULL; node = node->next)
      {
          cout << node->coeff<< "x^" << node->power<< " + ";
      }
      cout << node->coeff<< "x^" << node->power;
  }

  int main()
  {
      //Input managed
      int n=0;
      cin >> n;

      for(int i=0; i<n; i++)
      {
          int a1 = 0 , a2 = 0;
          cin >> a1 >> a2;
          insert(head1,tail1,a1,a2);
      }
      cin >> n;

      for(int i=0; i<n; i++)
      {
          int a1 = 0 , a2 = 0;
          cin >> a1 >> a2;
          insert(head2,tail2,a1,a2);
      }


      //output handled
    display(addpoly(head1,head2));
      return 0;
  }
