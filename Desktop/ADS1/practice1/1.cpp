#include <iostream>
#include <string>

using namespace std;

int a[100];
int sz = 0;
int head = 1;
int tail = 0;


void push(int x){
	sz++;
	tail++;
	a[tail] = x;
}

int pop(){
    int data = a[head];
    sz--;
    head++;
    return data;
    }

int front(){
	return a[head];
}

int size(){
	return sz;
}

void clear(){
	sz = 0;
	head = 1;
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
            if (size()>=1) {
                cout << pop() << endl;
            }    
		}else if(command == "front"){
            if (size()>=1) {
                cout << front() << endl;
            }    
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
