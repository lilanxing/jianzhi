# -*- coding: utf-8 -*-


class ListNode(object):

    def __init__(self, val):
        self.val = val
        self.next = None


def meeting_node(head):
    if head is None:
        return None
    slow = head.next
    if slow is None:
        return None
    fast = slow.next

    while fast is not None and slow is not None:
        if fast == slow:
            return fast
        slow, fast = slow.next, fast.next
        if fast is not None:
            fast = fast.next
    return None


def entry_loop(head):
    _meeting_node = meeting_node(head)
    if _meeting_node is None:
        return None

    loop_inner_count, p = 1, _meeting_node
    while p.next != _meeting_node:
        loop_inner_count += 1
        p = p.next

    p, back = head, head
    for i in range(loop_inner_count):
        p = p.next
    while back != p:
        back, p = back.next, p.next
    return p


if __name__ == '__main__':
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
    node5.next = node3

    entry_node = entry_loop(node1)
    if entry_node is None:
        print('no loop')
    else:
        print('entry if loop: {0}'.format(entry_node.val))
