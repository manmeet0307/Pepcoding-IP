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
int countocc(Node * headn , int k)
{
    unordered_map<int , int> m;
    while(head!=NULL)
    {
        if(m.count(head->data)==0)
        {
            m[head->data] = 1;
        }
        else{
            m[head->data]++;
        }
        head = head->next;
    }
    if(m.count(k)==0)
    {
        return 0;
    }
    return m[k];
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
      int k;
      cin>>k;

      //output handled
      cout<<countocc(head,k);
      return 0;
  }
