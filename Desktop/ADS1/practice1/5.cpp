#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
    }
};

class Stack {
    public:
    Node *top;
    int sz;

    Stack() {
        top= NULL;
        sz = 0;
    }

    void push(int data) {
        Node *newN = new Node(data);
        newN->next = top;
        top = newN;
        sz++;
    }

    void pop() {
        if (top != NULL) {
            top = top->next;
            sz--;
        }
    }  

    int size() {
        return sz;
    }  

    bool empty() {
        if (sz == 0)
            return true;
        return false;    
    }

    Node *topElement() {
        return top;
    }
};

int main(){
    Stack *st = new Stack();
    string command;
	while(cin >> command){
		if(command == "push"){
			int x;
			cin >> x;
			st->push(x);
			cout << "ok" << endl;
		}else if(command == "pop"){
			if (st->size()>=1) {
                cout <<st->topElement()->data <<endl;
                st->pop();
            } else {
                cout << "error" << endl;
            }
		}else if(command == "back"){
			if (st->size()>=1) {
                cout << st->topElement()->data << endl;
            } else { 
                cout << "error" << endl;
            }
		}else if(command == "size"){
			cout << st->size() << endl;
		}else if(command == "clear"){
			if (!st->empty()) {
                st->pop();
            } cout << "ok" << endl;
		}else if(command == "exit"){
			cout << "buy" << endl;
		    break;
	    }
    }
	return 0;
}