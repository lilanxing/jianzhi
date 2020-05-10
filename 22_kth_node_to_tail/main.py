# -*- coding: utf-8 -*-


class ListNode(object):

    def __init__(self, val):
        self.val = val
        self.next = None


def kth_to_tail(head, k):
    if head is None or k <= 0:
        return None
    
    front, back = head, None
    for i in range(k - 1):
        if front.next is None:
            return None
        front = front.next

    back = head
    while front.next is not None:
        front = front.next
        back = back.next
    return back


if __name__  == '__main__':
    node1 = ListNode(1)
    node2 = ListNode(2)
    node1.next = node2
    node3 = ListNode(3)
    node2.next = node3
    node4 = ListNode(4)
    node3.next = node4
    node5 = ListNode(5)
    node4.next = node5
    node6 = ListNode(6)
    node5.next = node6
    node7 = ListNode(7)
    node6.next = node7

    print(kth_to_tail(node1, 3).val)
