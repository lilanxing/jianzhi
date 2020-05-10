#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;

    ListNode(int _val) : val(_val), next(nullptr) {}
};

int GetListLength(ListNode* head) {
    int len = 0;
    ListNode* p = head;
    while (p != nullptr) {
        ++len;
        p = p->next;
    }
    return len;
}

ListNode* CommonNode(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr || l2 == nullptr) return nullptr;

    int len1 = GetListLength(l1);
    int len2 = GetListLength(l2);
    int len_diff = len1 - len2;

    ListNode* p_long = l1;
    ListNode* p_short = l2;
    if (len_diff < 0) {
        len_diff = -len_diff;
        p_long = l2;
        p_short = l1;
    }

    for (int i = 0; i < len_diff; ++i) p_long = p_long->next;

    while (p_long != nullptr && p_short!= nullptr && p_long != p_short) {
        p_long = p_long->next;
        p_short = p_short->next;
    }
    return p_long;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;
    ListNode* node3 = new ListNode(3);
    node2->next = node3;
    ListNode* node6 = new ListNode(6);
    node3->next = node6;
    ListNode* node7 = new ListNode(7);
    node6->next = node7;

    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node4->next = node5;
    node5->next = node6;

    ListNode* common = CommonNode(node1, node4);
    if (common != nullptr) std::cout << common->val << std::endl;
}
