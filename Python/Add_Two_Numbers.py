'''
    This script takes in 2 linked list and adds them up
    in reverse order in a new linked list:
    Example:
        l1 = 2 -> 4 -> 3
        l2 = 5 -> 6 -> 4
        result = 7 -> 0 -> 8
'''
class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def add_two_numbers(l1, l2):
    resultPreHead = ListNode()
    resultTail = resultPreHead
    carry = 0

    while l1 is not None or l2 is not None:
        sum = carry

        if l1 is not None:
            sum += l1.val
            l1 = l1.next
        if l2 is not None:
            sum += l2.val
            l2 = l2.next

        carry = sum // 10
        sum %= 10

        resultTail.next = ListNode(sum)
        resultTail = resultTail.next

    if carry > 0:
        resultTail.next - ListNode(carry)

    return resultPreHead.next   # next = head of list

def populate_list(size):
    if size == 0:
        return None
    
    value = int(input("Enter List Values: "))
    head = ListNode(value)
    tail = head

    for _ in range(size-1):
        value = int(input())
        tail.next = ListNode(value)
        tail = tail.next

    return head

def print_list(head):
    if head is None:
        print("Empty!")
        return
    
    while head.next is not None:
        print(f"{head.val} -> ", end = "")
        head = head.next
    print(f"{head.val}")

def main():
    size = int(input("Enter #Nodes for List 1: "))
    l1 = populate_list(size)

    size = int(input("Enter #Nodes for List 1: "))
    l2 = populate_list(size)

    result = add_two_numbers(l1, l2)
    print_list(result)

if __name__ == "__main__":
    main()