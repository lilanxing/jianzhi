#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;

    ListNode(int _val) : val(_val), next(nullptr) {}
};

ListNode* ReverseList(ListNode* head) {
    ListNode* reversed_head = nullptr;
    ListNode* prev_node = nullptr;
    ListNode* p = head;

    while (p != nullptr) {
        ListNode* p_next = p->next;
        if (p_next == nullptr) reversed_head = p;

        p->next = prev_node;
        prev_node = p;
        p = p_next;
    }

    return reversed_head;
}

void OutputList(ListNode* head) {
    ListNode* p = head;
    while (p != nullptr) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;
    ListNode* node3 = new ListNode(3);
    node2->next = node3;
    ListNode* node4 = new ListNode(4);
    node3->next = node4;

    OutputList(node1);
    OutputList(ReverseList(node1));
    OutputList(node1);
}
