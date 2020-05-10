#include <iostream>
#include <vector>
#include <stack>

bool IsPopOrder(const std::vector<int>& push_order, const std::vector<int>& pop_order) {
    bool possible = false;

    if (push_order.size() > 0 && pop_order.size() > 0 && push_order.size() == pop_order.size()) {
        int push_idx = 0;
        int pop_idx = 0;
        std::stack<int> s;

        while (pop_idx < pop_order.size()) {
            while (s.empty() || s.top() != pop_order[pop_idx]) {
                if (push_idx == push_order.size()) break;
                s.push(push_order[push_idx]);
                ++push_idx;
            }
            if (s.top() != pop_order[pop_idx]) break;
            s.pop();
            ++pop_idx;
        }

        if (s.empty() && pop_idx == pop_order.size()) possible = true;
    }
    
    return possible;
}

int main() {
    std::vector<int> push = {1, 2, 3, 4, 5};
    std::vector<int> pop1 = {4, 5, 3, 2, 1};
    std::vector<int> pop2 = {4, 3, 5, 1, 2};
    std::cout << IsPopOrder(push, pop1) << std::endl;
    std::cout << IsPopOrder(push, pop2) << std::endl;
}
