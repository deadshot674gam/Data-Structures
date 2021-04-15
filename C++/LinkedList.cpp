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

ostream &operator<<(ostream &os, vector<int> arr){
    for (int i = 0; i < arr.size(); ++i){
        os << arr[i] << " ";
    }

    return os;
}


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

    void insertAtNode(int x){
        Node* temp = new Node(x);
        temp->next = head;
        this->head = temp;
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
        Node*  beforeHead = new Node(1);
        Node*  afterHead = new Node(1);

        Node* before = beforeHead;
        Node* after = afterHead;
        Node* ptr = head;
        while(ptr!=NULL){
            if(ptr->data<x){
                before->next = ptr;
                before = before->next;
            }else{
                after->next = ptr;
                after = after->next;
            }
            ptr = ptr->next;
        }
        after->next = NULL;
        before->next = afterHead->next;
        this->head = beforeHead->next;        
    }

    bool isPallindrome(){
        Node* ptr = head;
        vector<int> vec;

        while(ptr!=NULL){
            vec.push_back(ptr->data);
            ptr = ptr->next;
        }

        int low = 0;
        int high = vec.size()-1;
        cout<<vec;
        while(low<high){
            if(vec[low] != vec[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }

    bool ifPallindrome(){
        if(head==NULL && head->next==NULL){
            return true;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverse(NULL,slow);
        fast = head;
        bool flag = false;
        while(fast!=NULL && slow!=NULL){
            if(fast->data == slow->data){
                fast = fast->next;
                slow = slow->next;
                continue;
            }
            flag = true;
            break;
        }
        return !flag;
    }


    
};

void reverseByKgroups(Node* head,int k){
        if()
}



int main()
{
    LinkedList* n = new LinkedList();
    (*n).append(1);
    (*n).append(2);
    (*n).append(3);
    (*n).append(4);
    (*n).append(5);
    (*n).append(4);
    (*n).append(3);
    (*n).append(2);
    (*n).append(1);
    // (*n).display();
    // (*n).head = (*n).reverseList();
    
    (*n).insertAtNode(1);
    // (*n).head = reverse(NULL, (*n).head);
    // (*n).display();

    // (*n).rearrange(5);
    // cout<<(*n).ifPallindrome()<<endl;

    cout<<n;
    delete n;
    return 0;
}