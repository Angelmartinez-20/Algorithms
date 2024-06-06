/*
    This script takes in 2 linked list and adds them up
    in reverse order in a new linked list:
    Example:
        l1 = 2 -> 4 -> 3
        l2 = 5 -> 6 -> 4
        result = 7 -> 0 -> 8
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
ListNode* populateList(int size);
void printList(ListNode* head);

int main() {
    int size;

    cout << "Enter #Nodes for List 1: " << endl;
    cin >> size;
    ListNode* l1 = populateList(size);

    cout << "Enter #Nodes for List 2: " << endl;
    cin >> size;
    ListNode* l2 = populateList(size);

    ListNode* result = addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}

ListNode* populateList(int size) {
    if (size == 0) return nullptr;
    int value;

    /* inits Linked List from 1st input */
    cout << "Enter List Values: ";
    cin >> value;
    ListNode* head = new ListNode(value);
    ListNode* tail = head;

    /* continures Linked List if more values */
    for (int i = 1; i < size; i++) {
        cin >> value;
        tail->next = new ListNode(value);
        tail = tail->next;
    }

    return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* resultPreHead = new ListNode(); 
    ListNode* resultTail = resultPreHead; 
    int carry = 0; 

    /* iterates through both list to add up values */     
    while (l1 != nullptr || l2 != nullptr) {
        int sum = carry;
            
        if (l1 != nullptr) {    
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
            
        carry = sum / 10; 
        sum %= 10; 
            
        resultTail->next = new ListNode(sum); 
        resultTail = resultTail->next; 
    }
        
    if (carry > 0) resultTail->next = new ListNode(carry);
        
    return resultPreHead->next;     // next = head of list
}

void printList(ListNode* head) {
    if (head == nullptr) {
        cout << "Empty!" << endl;
        return;
    }

    while (head->next != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << head->val << endl;
}
