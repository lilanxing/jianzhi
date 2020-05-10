#include <iostream>
#include <stack>

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};

void PrintListReversingly(ListNode* head) {
    std::stack<ListNode*> nodes;
    ListNode* p = head;
    while (p != nullptr) {
        nodes.push(p);
        p = p->next;
    }
    while (!nodes.empty()) {
        p = nodes.top();
        std::cout << p->val << " ";
        nodes.pop();
    }
    std::cout << std::endl;
}

void PrintListReversinglyRecursively(ListNode* head) {
    if (head != nullptr) {
        if (head->next != nullptr) {
            PrintListReversinglyRecursively(head->next);
        }
        std::cout << head->val << " ";
    }
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    node1->next = node2;
    ListNode* node3 = new ListNode(3);
    node2->next = node3;

    PrintListReversingly(node1);
    PrintListReversinglyRecursively(node1);
    std::cout << std::endl;
}
