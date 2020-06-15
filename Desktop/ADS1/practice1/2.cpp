#include <iostream>
#include <string>

using namespace std;

int sz = 0;
int head = 0;
int tail = 0;


void push(int x){
	sz++;
	tail++;
	tail = x;
}

int pop(){
    int data = head;
    sz--;
    head++;
    return data;
    }

int front(){
	return head;
}

int size(){
	return sz;
}

void clear(){
	sz = 0;
	head = 0;
	tail = 0;
}

string exit(){
    return "bye";
}

int main(){

    string command;
	while(cin >> command){
		if(command == "push"){
			int x;
			cin >> x;
			push(x);
			cout << "ok" << endl;
		}else if(command == "pop"){
			cout << pop() << endl;
		}else if(command == "front"){
			cout << front() << endl;
		}else if(command == "size"){
			cout << size() << endl;
		}else if(command == "clear"){
			clear();
			cout << "ok" << endl;
		}else if(command == "exit"){
			cout << exit() << endl;
		    break;
	    }
    }
	return 0;
}
