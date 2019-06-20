#include <iostream>
#include <vector>
#include<bits/stdc++.h>
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

  Node *head1 = NULL;
  Node *tail1 = NULL;

  Node *head2 = NULL;
  Node *tail2 = NULL;
  Node *head3 = NULL;
  Node *tail3 = NULL;
  int size = 0;

  void insert(int data,Node * &head , Node * &tail)
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
  vector<Node*> alternative_merge(Node* head1 , Node* head2)
  {
      Node *t1 = head1, *t2 = head2;
      if(head1==NULL)
      {
          return vector<Node *>{NULL, head2};
      }
      if(head2==NULL)
      {
          return vector<Node*>{head1,NULL};
      }
      Node * o = t1 , *t = t2 , *on = NULL , *tn = NULL;
      while(o!=NULL && t !=NULL)
      {
          on = o->next;
          tn = t->next;
          o->next = t;
          t->next = on;
          o = on;
          t = tn;
      }
      vector<Node *> v{NULL,NULL};
       v[0] = head1;
       /*if(o->next!=NULL)
       {
           Node * x = o->next;
           v[1] = x;
       }*/
       if(tn !=NULL)
       {

           Node * x = tn;
           //t->next = NULL;
           v[1] = x;
       }
       return v;
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
          insert(a,head1,tail1);
         // cout<<head1->data<< " "<<tail1->data<<endl;
      }
      int n2;
      cin >> n2;

      for(int i=0; i<n2; i++)
      {
          int a = 0;
          cin >> a;
          insert(a,head2,tail2);
      }

      // cal to the function
      vector<Node *> v = alternative_merge(head1,head2);

      //output handled
      display(v[0]);
      cout<<endl;
      display(v[1]);
      cout<<endl;
     // display(sortedHead);
      return 0;
  }
