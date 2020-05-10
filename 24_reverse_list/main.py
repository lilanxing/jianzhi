# -*- coding: utf-8 -*-


class ListNode(object):

    def __init__(self, val):
        self.val = val
        self.next = None


def reverse_list(head):
    reversed_head, prev_node, p = None, None, head
    while p is not None:
        p_next = p.next
        if p_next is None:
            reversed_head = p

        p.next = prev_node
        prev_node = p
        p = p_next
    return reversed_head


def output_list(head):
    p = head
    while p is not None:
        print(p.val),
        p = p.next
    print('')


if __name__ == '__main__':
    node1 = ListNode(1)
    node2 = ListNode(2)
    node1.next = node2
    node3 = ListNode(3)
    node2.next = node3
    node4 = ListNode(4)
    node3.next = node4

    output_list(node1)
    output_list(reverse_list(node1))
