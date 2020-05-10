#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;

    ListNode(int _val) : val(_val), next(nullptr) {}
};

ListNode* MeetingNode(ListNode* head) {
    if (head == nullptr) return nullptr;

    ListNode* slow = head->next;
    if (slow == nullptr) return nullptr;
    ListNode* fast = slow->next;

    while (fast != nullptr && slow != nullptr) {
        if (fast == slow) return fast;

        slow = slow->next;
        fast = fast->next;
        if (fast != nullptr) fast = fast->next;
    }

    return nullptr;
}

ListNode* EntryOfLoop(ListNode* head) {
    ListNode* meeting_node = MeetingNode(head);
    if (meeting_node == nullptr) return nullptr;

    int loop_inner_count = 1;
    ListNode* p = meeting_node;
    while (p->next != meeting_node) {
        ++loop_inner_count;
        p = p->next;
    }

    p = head;
    for (int i = 0; i < loop_inner_count; ++i) p = p->next;
    ListNode* back = head;
    while (p != back) {
        p = p->next;
        back = back->next;
    }

    return p;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;
    ListNode* node3 = new ListNode(3);
    node2->next = node3;
    ListNode* node4 = new ListNode(4);
    node3->next = node4;
    ListNode* node5 = new ListNode(5);
    node4->next = node5;
    ListNode* node6 = new ListNode(6);
    node5->next = node6;
    node6->next = node3;

    ListNode* entry_node = EntryOfLoop(node1);
    if (entry_node != nullptr) std::cout << "has loop, entry node is " << entry_node->val << std::endl;
    else std::cout << "no loop" << std::endl;
}
