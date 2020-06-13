#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int data) {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class LinkedList {
    public:
    Node *front;
    Node *tail;
    int sz;

    LinkedList() {
        front = NULL;
        tail = NULL;
        sz = 0;
    }

    void pushFront(int data) {
        Node *nn = new Node(data);
        if (front == NULL) {
            front = nn;
            tail = nn;
        } else {
            front->next = nn;
            nn->prev = front;
            front = nn;
        }
    }

    void popFront() {
        if (front != NULL) {
            front = front->prev;
            if (front == NULL)
                tail = NULL;
            else 
                front->next = NULL;
        }
    }

    void pushBack(int data) {
        Node *nn = new Node(data);
        if (tail == NULL) {
            front = nn;
            tail = nn;
        } else {
            nn->next = tail;
            tail->prev = nn;
            tail = nn;
        }
    }

    void popBack() {
        if (tail != NULL) {
            tail = tail->next;
            if (tail == NULL)
                front = NULL;
            else 
                tail->prev = NULL;
        }
    }

    void push(Node *a, Node *c) {
        Node *b = a->next;
        if (b == NULL) {
            pushFront(c->data);
        } else {
            a->next = c;
            c->prev = a;
            c->next = b;
            b->prev = c;
        }
    }

    void pop(Node *a) {
        if (a->next == NULL)
            popFront();
        else if (a->prev == NULL)
            popBack();
        else {
            Node *c = a->prev;
            Node *b = a->next;
            c->next = b;
            b->prev = c;
        }
    }

    Node *find(int data) {
        Node *node = front;
        /*while (node != NULL) {
            if (node->data == data) {
                node = front;
                break;
            }
            node = node->next;
        }
        return NULL;*/
        while (node != NULL && node->data != data)
            node = node->next;
        return node;
    }
};

int main() {
    LinkedList *ll = new LinkedList();
    ll->pushFront(5);
    ll->pushFront(10);
    ll->pushBack(15);
    ll->pushBack(20);
    ll->pushBack(25); //10 5 15 20 25
    //ll->popBack();
    //ll->popFront();
    Node *node = ll->find(5);
    ll->pop(node);
    cout << ll->tail->data << endl; 
    return 0;
}