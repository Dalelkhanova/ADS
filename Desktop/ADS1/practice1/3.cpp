#include <iostream>

using namespace std;

int a[100];
int sz = 0;


void push(int x){
	sz++;
	a[sz] = x;
}

int pop(){
	int data = a[sz];
	sz--;
	return data;   
}

int back(){
	return a[sz];
}

int size(){
	return sz;
}

void clear(){
	sz = 0;
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
		}else if(command == "back"){
			cout << back() << endl;
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