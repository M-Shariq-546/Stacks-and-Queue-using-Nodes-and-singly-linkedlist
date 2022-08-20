#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *next;

public:
    Node() {}
    Node(int data, Node *next = NULL)
    {
        setData(data);
        setNext(next);
    }
    void setData(int data)
    {
        this->data = data;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
    int getData()
    {
        return data;
    }
    Node *getNext()
    {
        return next;
    }
};
class Linkedlist
{
private:
    Node *head;

public:
    bool isEmpty()
    {
        while (head->getNext() == NULL)
        {
            return true;
        }
        return false;
    }
    int insertAtBegin(int val)
    {
        if (isEmpty())
        {
            head = new Node(val);
        }
        Node *t = new Node(val);
        t->setNext(head);
        head = t;
        return head->getData();
    }
    void count()
    {
        int count = 0;
        while (head->getNext() != NULL)
        {
            head = head->getNext();
            count++;
        }
        cout << count;
    }
    void insertAtLast(int val)
    {
        Node *t = new Node(val);
        if (isEmpty())
        {
            head = t;
        }
        else
        {
            Node *t1 = head;
            while (t1->getNext() != NULL)
            {
                t1 = t1->getNext();
            }
            t1->setData(val);
            cout << t1->getData();
        }
    }
    void getFirstElement()
    {
        cout<< head->getData();
    }
    int getLastElement()
    {
        if(!isEmpty())
        {
            Node * temp = head;
            Node * t = head->getNext();
            while(t != NULL){
                temp = temp->getNext();
                t = t->getNext();
            }
           return temp->getData();
        }
    }
    void printAll()
    {
        if(!isEmpty())
        {
            Node * t = head;
            while (t != NULL)
            {
                cout<<t->getData()<<" ";
                t = t->getNext();
            }
        }
    }
    bool removeFromLast()
    {
        if(!isEmpty())
        {
            Node * t = head;
            Node * t1 = t->getNext();
            while (t1 != NULL)
            {
                t = t->getNext();
                t1 = t1->getNext();
            }
            delete t1;
            t->setNext(NULL);
            return false;
        }
        return true;
    }
};
int main()
{
    Linkedlist l;
    cout << l.isEmpty() << endl;
    for (int i = 0; i < 5; i++)
        cout << l.insertAtBegin(100 + i) << endl;

    l.insertAtLast(700);
    cout<<endl;
    cout << l.isEmpty() << endl;
    l.count();
    cout<<endl;
    if(l.removeFromLast() == true)
    cout<<"1";
    else    
    cout<<"0";
    l.getFirstElement();
    cout<<endl;
    l.printAll();
    cout<<l.getLastElement();
    
    return 0;
}