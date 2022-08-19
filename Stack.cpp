#include<iostream>
using namespace std;
class Node
{
    private:
        int data;
        Node * next;
    public:
        Node(){}
        Node(int data , Node * next = NULL)
        {
            setData(data);
            setNext(next);
        }
        void setData(int data)
        {
            this->data = data;
        }
        void setNext(Node * next)
        {
            this->next=next;
        }
        int getData()
        {
            return data;
        }
        Node* getNext()
        {
            return next;
        }
};
class Linkedlist
{
    private:
        Node * head;
    public:
        bool isEmpty()
        {
            if(head->getNext() == NULL)
            {
                return true;
            }
            return false;

        }
        int insertAtBegin(int val)
        {
            if(isEmpty())
            {
                head = new Node(val);
            }
            Node * t = new Node(val);
            t->setNext(head);
            head = t ;
            return head->getData();
        }
        int getLenght()
        {
          if(!isEmpty())
          {
            int count =0;
            Node* t = head;
            while(t != NULL)
            {
                t = t->getNext();
                count++;
            }
            return count;
          }   
        }
        void insertAtLast(int val)
        {
            Node * t = new Node(val);
            if(isEmpty())
            {
                head = t;
            }
            else{
            Node * t1 = head;
            while(t1->getNext() != NULL)
            {
                t1 = t1->getNext();
            }
           t1->setData(val);
            cout<<t1->getData();
        }
        }
        bool removeFromBegin()
        {
            if(head->getNext() != NULL)
            {
                delete head ;
                head->setNext(NULL);
                return true;
            }
            return false;
        }
        void removeFromLast()
        {
            Node * t = head;
            Node * t1 = t->getNext();
            while(t1->getNext() != NULL)
            {
                t = t->getNext();
                t1 = t1->getNext();
            }
            delete t1;
            t->setNext(NULL);
        }
        int getFirstElement()
        {
                return (head->getData());   
        }
        int getLastElement()
        {
            if(!isEmpty())
            {
                while(head->getNext() !=NULL)
                {
                    head = head->getNext();
                }
                return head->getData();
            }
        }
        void printAll()
        {
            if(!isEmpty())
            {
                Node* temp=head;
                while (temp != NULL)
                {
                    cout << temp->getData() <<"  ";
                    temp = temp->getNext();
                }
            }
        }
};
class stack{
    private:
        Linkedlist l;
        int size;
    public:
        stack(){}
        void setSize(int size)
        {
            size = this->size;
        }
        int getSize()
        {
            return size;
        }
        stack(int size = 10){
            setSize(size);
        }
        bool push(int val)
        {
            if(!(isFull()))
            {
                l.insertAtBegin(val);
                return true;
            }
            else{
                cout<<"The Stack is completely filled";
                return false;
            }
        }       
        int pop()
        {
            if(!(isEmpty()))
            {
                int value = l.getFirstElement();
                l.removeFromBegin();
                return value;
            }
            else{
                cout<<"The Stack is Empty and nothing to pop out.";
                return 1;
            }
        }
        bool isEmpty()
        {
            return l.isEmpty();
        }
        bool isFull()
        {
            int count = l.getLenght();
            if(count == size)
            {
                return true;
            }
            else{
                return false;
            }
        }
        int top()
        {
            if(!(isEmpty()))
            {
                return l.getFirstElement();
            }
            else{ 
                cout<<"The stack is Empty and nothing to be topped out.";
                return 1;
            }
        }
        int printAll()
        {
            l.printAll();
        }
};
int main()
{
    stack s(55);
    for(int i=0 ; i<10 ; i++)
    s.push(5);

    cout<<"The Size of the stack at this time is : ";
    cout<<s.getSize();
    cout<<endl;
        if(s.isFull())
    {
        cout<<"The Stack is Not Full. ";
        cout<<endl;
    }   
    else{
        cout<<"The Stack is completely Full.";
        cout<<endl;
    }
    cout<<"The top most value of the stack is : ";
    cout<<s.top();
    cout<<endl;
    cout<<"The List of All the members of the stack is : ";
    s.printAll();
    return 0;
}