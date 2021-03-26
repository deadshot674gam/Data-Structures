#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
typedef struct Node Node;



Node* reverse(Node *prev, Node *curr)
{
    if (curr == NULL)
    {
        return prev;
    }
    Node *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;

    return reverse(prev, curr);
}


class LinkedList
{
public:
    Node *head;

    LinkedList(){};
    LinkedList(Node*  h){
        head= h;
    }
    ~LinkedList(){
        Node* ptr =head;
        while(ptr!=NULL){
            Node* temp = ptr->next;
            free(ptr);
            ptr = temp;
        }
    }

    int length(){
        Node* ptr = head;
        int len = 0;
        while(ptr!=NULL){
            len++;
            ptr=ptr->next;
        }

        return len;
    }

    void append(int data)
    {
        if (this->head == NULL)
        {
            this->head = new Node(data);
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new Node(data);
        }
    }

    Node* reverseList()
    {
        Node *curr = this->head;
        Node *prev = NULL;

        while (curr != NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }



    void display(){
        Node* ptr = head;
        while(ptr!=NULL){
            cout<<ptr->data<<" -> ";
            ptr = ptr->next;
        }
        cout<<"NULL"<<endl;
    }

    friend ostream &operator<<(ostream &os, LinkedList* l)
    {

        Node *ptr = (*l).head;
        while (ptr != NULL){
            os<<(ptr->data)<<" -> ";
            ptr = ptr->next;
        }
        os<<"NULL"<<endl;
        return os;
    }

    void folding(){
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;


        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* firstNode = head;
        LinkedList* first = new LinkedList(firstNode);
        LinkedList* second = new LinkedList(slow);
        (*second).head = (*second).reverseList();
        firstNode = first->head;
        Node* secondNode = second->head;

        while (secondNode->next!=NULL){
            Node* temp = firstNode->next;
            firstNode->next = secondNode;
            firstNode = temp;
            temp = secondNode->next;
            secondNode->next = firstNode;
            secondNode =temp;
        }
    }

    void rearrange(int x){
        

        LinkedList* l = new LinkedList();

        Node* ptr = head;
        while(ptr!=NULL){
            if(ptr->data<x)
            (*l).append(ptr->data);
            ptr = ptr->next;
        }

        ptr = head;
        while(ptr!=NULL){
            if(ptr->data>=x)
            (*l).append(ptr->data);
            ptr = ptr->next;
        }
        this->head = (*l).head;

        
    }
};



int main()
{
    LinkedList* n = new LinkedList();
    (*n).append(9);
    (*n).append(2);
    (*n).append(1);
    (*n).append(3);
    (*n).append(2);
    (*n).append(4);
    (*n).append(10);
    (*n).append(8);
    (*n).append(7);
    // (*n).display();
    // (*n).head = (*n).reverseList();
    

    // (*n).head = reverse(NULL, (*n).head);
    // (*n).display();

    (*n).rearrange(5);


    cout<<n;
    delete n;
    return 0;
}