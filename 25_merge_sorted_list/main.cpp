#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;

    ListNode(int _val) : val(_val), next(nullptr) {}
};

ListNode* Merge(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNode* head = nullptr;
    if (l1->val < l2->val) {
        head = l1;
        head->next = Merge(l1->next, l2);
    } else {
        head = l2;
        head->next = Merge(l1, l2->next);
    }
    return head;
}

void OutputList(ListNode* l) {
    for (ListNode* p = l; p != nullptr; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << std::endl;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;

    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    node3->next = node4;

    OutputList(Merge(node1, node3));
}
