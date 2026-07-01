#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Function to add two numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {

        int x = 0, y = 0;

        if (l1 != NULL) {
            x = l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            y = l2->val;
            l2 = l2->next;
        }

        int sum = x + y + carry;

        carry = sum / 10;

        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
}

// Function to print linked list
void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    // First Number : 342
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Second Number : 465
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* ans = addTwoNumbers(l1, l2);

    cout << "Result Linked List: ";
    printList(ans);

    return 0;
}