# -*- coding: utf-8 -*-


class ListNode(object):

    def __init__(self, val):
        self.val = val
        self.next = None


def print_list(head):
    nodes = []
    p = head
    while p is not None:
        nodes.append(p)
        p = p.next
    for p in nodes[::-1]:
        print(p.val),
    print('')


def print_list_recursively(head):
    if head is not None:
        if head.next is not None:
            print_list_recursively(head.next)
        print(head.val),


if __name__ == '__main__':
    node1 = ListNode(1)
    node2 = ListNode(2)
    node1.next = node2
    node3 = ListNode(3)
    node2.next = node3

    print_list(node1)
    print_list_recursively(node1)
