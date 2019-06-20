#include <iostream>
   #include <vector>
   #include <string>
   #include <unordered_map>

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

   /*
       * Input Parameters: tail: tail of the linked list in which a new node is to
       * be inserted. data: the data value of the node which is to be inserted.
       *
       * Return Value: tail of the linked list in which the node is inserted
   */
   Node *insert(Node *tail, int data)
   {
       if (tail == NULL)
       {
           return new Node(data, NULL);
       }
       else
       {
           tail->next = new Node(data, NULL);
           return tail->next;
       }
   }

   /*
       * Input Parameters: head: head of the linked list in which is to be
       * displayed.
       *
       * Return Value: null
   */
   void display(Node *head)
   {
       for (Node *node = head; node != NULL; node = node->next)
       {
           cout << node->data << " ";
       }
       cout << endl;
   }

   // -----------------------------------------------------
   // This is a functional problem. Only this function has to be written.
   // It takes as input the head of the linked list. It should return the
   // head of the modifiec list.
    void rpi(Node * &head)
    {
        Node * prev=NULL, * curr =head;
        while(curr!=NULL)
        {

            Node * nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        head = prev;
    }
   Node *plusOne(Node *n)
   {
       // write your code here
       Node * t = n;
       rpi(t);
       Node * m = t;
       int c = 0;
       if(t!=NULL)
       {
           int x = t->data;
           t->data = (t->data +1)%10;
           c = (x + 1)/10;
           t = t->next;
       }
       while(t!=NULL)
       {
           int x =t->data;
           t->data = (x  + c)%10;
           c = (x +c)/10;
        if(t->next !=NULL)
           t = t->next;
        else
            break;
       }
       if(c==1)
       {
           t->next = new Node(1,NULL);
           t = t->next;
       }
       rpi(m);
    return m;
   }

   // -----------------------------------------------------

   int main()
   {
       int s;
       cin >> s;
       int a;
       cin >> a;
       head = insert(NULL, a);
       Node *cur = head;
       for (int i = 1; i < s; i++)
       {
           int temp;
           cin >> temp;
           cur = insert(cur, temp);
       }

       Node *added = plusOne(head);
       display(added);
   }
