#include <iostream>

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};

ListNode* KthToTail(ListNode* head, int k) {
    if (head == nullptr || k <= 0) return nullptr;

    ListNode* front = head;
    ListNode* back = nullptr;

    for (int i = 0; i < k - 1; ++i) {
        if (front->next == nullptr) return nullptr;
        front = front->next;
    }

    back = head;
    while (front->next != nullptr) {
        front = front->next;
        back = back->next;
    }

    return back;
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
    ListNode* node7 = new ListNode(7);
    node6->next = node7;

    std::cout << KthToTail(node1, 3)->val << std::endl;
}
