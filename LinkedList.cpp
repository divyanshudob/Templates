#include<bits/stdc++.h>
using namespace std;
class Node
{
  public:
  int data;
  Node *next;
  
  Node(int d)
  {
      data = d;
      next = NULL;
  }
};

// Insertion At head
void insertAtHead(Node*& head, int data)
{
    if(head == NULL)
    {
        head = new Node(data);
        return;
    }
    
    Node * n = new Node(data);
    n->next = head;
    head = n;
}

//Printing the Linked List
void print(Node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<".";
    cout<<endl;
    return;
}
//length of the linked list
int lengthOfTheLinkedList(Node* head)
{
    int cnt = 0;
    while(head)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}
//Insert At insertAtTail
void insertAtTail(Node *& head, int data)
{
     Node *temp = head;
     while(temp->next != NULL)
     {
         temp=temp->next;
     }
     Node * n = new Node(data);
     temp->next = n;
}
//Insertion In Middle
void insertInMiddle(Node *&head, int pos, int data)
{
    int size = lengthOfTheLinkedList(head);
    if(size == 1)
    {
        Node* n = new Node(data);
        head->next = n;
    }
    else
    if(pos >= size)
    {
        insertAtTail(head, data);
    }
    else
    {
        int jump = 0;
        Node * temp = head;
        while(jump <= pos-1)
        {
            temp = temp->next;
            jump++;
        }
        
        Node*n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }
}
//Delete at Head
void deleteAtHead(Node *& head)
{
    head = head->next;
}
//searching
bool search(Node *head, int data)
{
    while(head != NULL)
    {
        if(head->data == data)
          return true;
        head = head->next;
    }
    return false;
}
//Recursive search
bool recursiveSearch(Node *head, int data)
{
    if(head == NULL)
       return false;
    if(head -> data == data)
       return true;
    
    return(head->next, data);
}
//Reverse a linked list
void reverse(Node *& head)
{
    Node*p,*q,*r;
    p = q = NULL;
    r = head;
    
    while(r != NULL)
    {
        q = r -> next;
        r-> next = p;
        p = r;
        r = q;
    }
    
    head = p;
}
//Delete at head
void deleteAtHead(Node *& head)
{
    if(head == NULL or head->next == NULL)
       return;
    
    head = head->next;
}
//Mid point of a linked list
int midPoint(Node * head)
{
    if(head== NULL or head->next== NULL)
      return head;
    
    node * slow = head;
    node * fast = head->next;
    
    while(fast != NULL)
    {
       fast = fast->next->next;
       slow = slow->next;
    }
    return slow->data;
}
//kth node from the end
int kthNode(node*head, int pos)
{
    int length = lengthOfTheLinkedList(head);
    int jump = 0;
    while(jump <= length - pos)
    {
        jump++;
        head = head->next;
    }
    
    return head->data;
}
int main()
{
    Node *head = NULL;
    while(1)
    {
        
        int choice, data, pos;
        bool ans;
        cout<<"**********Main Menu********"<<endl;
        cout<<"1. Insertion at head"<<endl;
        cout<<"2. Print the linked list"<<endl;
        cout<<"3. length Of The Linked List"<<endl;
        cout<<"4. Insert At Tail"<<endl;
        cout<<"5. Insert In Middle"<<endl;
        cout<<"6. Delete At head"<<endl;
        cout<<"7. Search"<<endl;
        cout<<"8. Recurive Search"<<endl;
        cout<<"9. Reverse a linked list"<<endl;
        cout<<"10. Delete at head"<<endl;
        cout<<"11. Mid point of a Linked List"<<endl;
        cout<<"12. Kth Node from the end"<<endl;
        cout<<". Exit"<<endl;
        cout<<"**************************"<<endl;
        cin>>choice;
        
        switch(choice)
        {
            case 1:cout<<"Enter the element to be inserted\n";
                    cin>>data;
                    insertAtHead(head, data);
                    break;
            case 2: print(head);
                    break;
            case 3: lengthOfTheLinkedList(head);
                    break;
            case 4: cout<<"Enter the element to be inserted\n";
                    cin>>data;
                    insertAtTail(head, data);
                    break;
            case 5: cout<<"Enter the element to be inserted and the pos\n";
                    cin>>data>>pos;
                    insertInMiddle(head, pos, data);
                    break;
            case 6: deleteAtHead(head);
                    break;
            
            case 7: cout<<"Enter data to be searched"<<endl;
                    cin>>data;
                    ans =  search(head, data);
                    if(ans) cout<<"Element Present"<<endl;
                    else cout<<"Not Present"<<endl;
                    break;
            
            case 8: cout<<"Enter data to be searched recursively"<<endl;
                    cin>>data;
                    ans =  recursiveSearch(head, data);
                    if(ans) cout<<"Element Present"<<endl;
                    else cout<<"Not Present"<<endl;
                    break;
            
            case 9: cout<<"Reverse a Linked List"<<endl;
                    reverse(head);
                    break;
                    
            case 10: deleteAtHead(head);
                     break;
            
            case 11: cout<<midPoint(head);
                     break;
            
            case 12: cout<<"Enter the position"<<endl;
                     cin>>pos;
                     cout<<kthNode(head, pos)<<endl;;
                     break;
        }
        
    }
}