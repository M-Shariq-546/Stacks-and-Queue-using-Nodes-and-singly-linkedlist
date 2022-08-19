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
class Queue{
    private:
        Linkedlist l;
        int size;
    public:
        void setSize(int size)
        {
            this->size = size;
        }
        int getSize()
        {
            return size;
        }
        Queue(int size = 10)
        {
            setSize(size);
        }
        bool isEmpty()
        {
            return (l.isEmpty())?true:false;
        }
        bool isFull()
        {
            int count = l.getLenght();
            return (count == size) ? true:false;
        }
        bool enqueue(int val)
        {
            if(!(isFull()))
            {
                l.insertAtBegin(val);
                return true;
            }
            else{
                cout<<"The Queue is Full.";
                return NULL;
            }
        }
        int dequeue()
        {
            if(!(isEmpty()))
            {
                int n = l.getLastElement();
                l.removeFromLast();
                return n;  
            }
            else{
                cout<<"The Queue is Empty .";
                int n = 0;
                return n;
            }
        }
        int peek(){
                if(!(isEmpty()))
                {
                   return l.getLastElement();
                }
                else{
                    cout<<"The Queue is Empty.";
                    int n = 0;
                    return n;
                }
        }
        void printQueue()
        {
            cout<<"The All Elements of the Queue are : ";
            l.printAll();
        }
};

int main()
{  
    Queue q;
    for(int i=0 ; i< 10 ; i++)
    {
        q.enqueue(i + 2);
    }
    cout<<"The size of queue is : "<<q.getSize();
    if(q.isFull())
    {
        cout<<"The Queue is Completely Filled .";
    }
    else{
        cout<<"The Queue is Not Filled .";
    }
    q.printQueue();
    cout<<"The Peek value is : "<<q.peek();
    return 0;
}