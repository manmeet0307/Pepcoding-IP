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

 //-----------------------------------------------------
      //This is a functional problem. Only this function has to be written.
      //You should return an integer denoting decimal equivalent of binary linked list.

 int getnum(Node* head)
 {
     Node * t = head->next;
     int dec=head->data;
     while(t!=NULL)
     {   if(t->data==1)
            {

                dec= (2*dec + 1);
            }
            else{
                dec= (2*dec);
            }

         t = t->next;
     }
     return dec;
 }
 //---------------------------------------------------

 int main()
 {
     // Input Handled
     int n=0;
     cin >> n;

     for(int i=0; i<n; i++)
     {
         int a = 0;
         cin >> a;
         insert(a);
     }

     // Call and Output
     cout << getnum(head);

     return 0;
 }
