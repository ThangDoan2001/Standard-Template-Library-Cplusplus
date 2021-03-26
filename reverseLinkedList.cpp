#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverse1(ListNode* head) {
	ListNode* cur = head;
	ListNode* nextNode = head;
	
	while (cur != NULL && cur->next != NULL) {
		nextNode = cur->next;
		cur->next = nextNode->next;
		nextNode->next = head;
		head = nextNode;
	}
	return head;
}

ListNode* reverse2(ListNode* head) {
	if (head == NULL) {
		return head;
	}
	ListNode* nextNode = head->next;
	if (nextNode == NULL) {
		return head;
	}

	ListNode* newHead = reverse2(nextNode);
	newHead->next = head;
	head->next = NULL;
	return newHead;
}

void printListNode(ListNode* head) {
	ListNode* cur = head;
	while (cur != NULL) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << "\n";
}

int main() {
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	n1->next = n2; n2->next = n3; n3->next = n4, n4->next = n5; n5->next = NULL;
	printListNode(n1);
	ListNode* newHead = reverse1(n1);
	printListNode(newHead);
	newHead = reverse1(n5);
	printListNode(newHead);
	return 0;
}