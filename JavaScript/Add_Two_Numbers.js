/*
    This script takes in 2 linked list and adds them up
    in reverse order in a new linked list:
    Example:
        l1 = 2 -> 4 -> 3
        l2 = 5 -> 6 -> 4
        result = 7 -> 0 -> 8
*/
const prompt = require('prompt-sync')({sigint: true});

class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

function addTwoNumbers(l1, l2) {
    let resultPreHead = new ListNode();
    let resultTail = resultPreHead;
    let carry = 0;

    while (l1 !== null || l2 !== null) {
        let sum = carry;

        if (l1 !== null) {
            sum += l1.val;
            l1 = l1.next;
        }
        if (l2 !== null) {
            sum += l2.val;
            l2 = l2.next;
        }

        carry = Math.floor(sum / 10);
        sum %= 10;

        resultTail.next = new ListNode(sum);
        resultTail = resultTail.next;
    }

    if (carry > 0) {
        resultTail.next = new ListNode(carry);
    }

    return resultPreHead.next   // next = head of list
}

function populateList(size) {
    if(size === 0) return null;

    console.log("Enter List Values: ");
    let value = parseInt(prompt(), 10);
    let head = new ListNode(value);
    let tail = head

    for (let i = 1; i < size; i++) {
        value = parseInt(prompt(), 10);
        tail.next = new ListNode(value);
        tail = tail.next;
    }

    return head;
}

function printList(head) {
    // list is empty
    if (head === null) {
        console.log("Empty!");
        return;
    }
    // iterates through list 
    let current = head;
    let result = '';
    while(current.next !== null) {
        result += current.val + ' -> ';
        current = current.next;
    }
    result += current.val;
    console.log(result);
}

function main() {
    let size = parseInt(prompt("Enter #Nodes for List 1: "), 10);
    let l1 = populateList(size);

    size = parseInt(prompt("Enter #Nodes for List 1: "), 10);
    let l2 = populateList(size);

    let result = addTwoNumbers(l1, l2);
    printList(result);
}

main()