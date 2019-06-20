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

 void display()
 {
     for (Node *node = head; node != NULL; node = node->next)
     {
         cout << node->data << " ";
     }
 }

  // ---------------------------------------------------------------
      // This is a functional problem. Only this function has to be written.

 void fashion(Node* head)
 {
     // write your code here
     if(head==NULL || head->next==NULL)
     {
         return ;
     }
    bool isincr = 1;
    Node * t =head;
    if(head->next->next ==NULL)
    {
        if(head->data > head->next->data)
            swap(head->data, head->next->data);
        return ;
    }
    while(t->next!=NULL)
    {
        Node * x= t , *y = t->next;
        if(isincr==1 && x->data  > y->data)
        {
            swap(x->data , y->data);
        }
        else if( isincr == 0 && x->data < y->data)
        {
            swap(x->data , y->data);
        }
        t = t->next;
        isincr = (isincr==1)? 0 : 1;
    }

     return ;
 }

 int main()
 {
     //input handled
     int n = 0;
     cin >> n;
     for (int i = 0; i < n; i++)
     {
         int a = 0;
         cin >> a;
         insert(a);
     }

     // call to the function
     fashion(head);

     //output
     display();
     return 0;
 }
