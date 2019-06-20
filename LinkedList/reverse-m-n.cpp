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
Node* sortll(Node * head, int m, int n)
{
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        int x = m, y = n;
        Node * t = head ;
        Node * prev = NULL , *curr = head;

            while(--x>=1)
            {
                prev = curr;
                curr = curr->next;
            }
            Node * m1 = prev;
            //cout<<m1->data<<endl;
            prev = curr, curr = curr->next;
            Node * nn;
            Node * m2 = prev;
            //cout<<m2->data<<endl;
            int c=0;
            while(c  < y-m)
            {
                nn = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nn;

                c++;
            }
           // cout<<prev->data<<" "<<curr->data<<endl;
            if(m1==NULL)
            {
                m2->next = curr;
                return prev;
            }
            m1->next = prev;

            m2->next = curr;
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
      int m,n1;
      cin>>m>>n1;
      // cal to the function
      Node* sortedHead = sortll(head , m , n1);

      //output handled
      display(sortedHead);
      return 0;
  }
