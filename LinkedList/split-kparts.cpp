#include <iostream>
#include <vector>
#include<unordered_set>
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
  int len(Node * h)
  {
      if(h == NULL)
      {
          return 0;
      }
      return 1 + len(h->next);
  }

  //----------------------------------------------------
       //This is a functional problem. Only this function has to be written.
       //You should return the head of node after sorting.
  vector<Node*> removedupl(Node* head , int k)
  {
      if(head == NULL )
      {
          return vector<Node*>{NULL};
      }
      int l = len(head);
      int partlen = l/ k;
      int extra = l % k;
      vector<Node*> v;
      Node * t = head;
      while(t!=NULL)
      {
          Node * x = t;
          int explen  = (extra>0)? partlen + 1 : partlen;
          for(int i=0 ; i < explen -1; i++)
          {
              t = t->next;
          }
          Node * y = t;
          t = t->next;
          y->next =NULL;
          v.push_back(x);
          extra--;
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
          insert(a);
      }
      // cal to the function
      int k;
      cin>>k;
      vector<Node* > v = removedupl(head,k);

      //output handled
      for(int i=0;i<v.size();i++)
      {
            display(v[i]);
            cout<<endl;
      }

      return 0;
  }
