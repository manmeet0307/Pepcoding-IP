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

  void display(Node* head)
  {
      for (Node *node = head; node != NULL; node = node->next)
      {
          cout << node->data << " ";
      }
  }

  //----------------------------------------------------
int connectedcomp(Node * head,const unordered_map<int,bool> &m)
{
    bool f = false;
    int c=0;
    Node * t = head;
    while(t!=NULL)
    {
        if(f==false && m.count(t->data))
        {
            f = true;
            c++;
        }
        if(f==true && m.count(t->data)==0)
        {
            f = false;
        }
        t = t->next;
    }
    return c;
}
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
      int n2;
      cin>>n2;
      unordered_map<int,bool> m;
      for(int i=0;i<n2;i++)
      {
          int num;
          cin>>num;
          m[num] = true;
      }
      cout<<connectedcomp(head,m);
      return 0;
  }
