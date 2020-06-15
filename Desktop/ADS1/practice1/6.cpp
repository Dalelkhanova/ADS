#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct List{
    ListNode * head;
    ListNode * tail;
    List(){
        head = NULL;
        tail = NULL;
    }
    void push(int x) {
        ListNode *nn = new ListNode(x);
        if (head == NULL) {
            head = nn;
            tail = nn;
        } else {
            head->next = nn;
            head = nn;
        }
    }
    
};

void print(ListNode * nn){
        while(nn != NULL){
            cout << nn->val;
            nn = nn->next;
            if(nn != NULL){
                cout << "->";
            }
        }
}

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            return swap(NULL, head);
        }
        
        ListNode* swap(ListNode * n1, ListNode * n2){
            if(n1 == NULL && n2 == NULL) return NULL;
            ListNode * n3 = n2->next;
            n2->next = n1;
            if(n3 == NULL) return n2;
            return swap(n2, n3);
        }
};


int main(){

    int test1[] = {};
    int len = sizeof(test1) / sizeof(int);

    List l;
    for(int i = 0; i < len; ++i){
        l.push(test1[i]);
    }

    cout << "input: ";
    print(l.head);
    cout << endl;

    Solution s;
    ListNode *head2 = s.reverseList(l.head);

    cout << "output: ";
    print(head2);
    cout << endl;

    return 0;
}