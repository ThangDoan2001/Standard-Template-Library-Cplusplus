#include<iostream>
#include<vector>
using namespace std;

//chay tren dev c++ thi duoc :))

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapNodes1(ListNode* head, int k) {
    ListNode* x = head;
    vector<int> arr;
    while (x != NULL) {
        arr.push_back(x->val);
        x = x->next;
    }
    int tmp = arr[k - 1];
    arr[k - 1] = arr[arr.size() - k];
    arr[arr.size() - k] = tmp;
    ListNode* new_head = new ListNode(arr[0]);
    ListNode* cur = new_head;
    for (int i = 1; i <= arr.size() - 1; ++i) {
        ListNode* nextNode = new ListNode(arr[i]);
        cur->next = nextNode;
        cur = nextNode;
    }
    cur->next = NULL;
    return new_head;
}

ListNode* swapNodes2(ListNode* head, int k) {
    int listLength = 0;
    ListNode* frontNode;
    ListNode* endNode;
    ListNode* currentNode = head;
    while (currentNode) {
        listLength++;
        if (listLength == k) {
            frontNode = currentNode;
        }
        currentNode = currentNode->next;
    }
    endNode = head;
    for (int i = 1; i <= listLength - k; i++) {
        if(endNode->next != NULL) 
            endNode = endNode->next;
    }
    // swap front node and end node values
    ListNode* tempNode = frontNode;
    frontNode = endNode;
    endNode = tempNode;
    return head;
}

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = NULL;

    ListNode* first = swapNodes1(a, 2);
    while (first != NULL) {
        cout << first->val;
        first = first->next;
    }

    cout << "\n";
    ListNode* second = swapNodes2(a, 2);
    while (second != NULL) {
        cout << second->val;
        second = second->next;
    }

    return 0;

}