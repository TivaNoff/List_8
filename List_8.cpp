#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        int length = 0;

        while (head) {
            length++;
            head = head->next;
        }

        head = dummy->next;

        for (int i = 0; i < length / k; ++i) {
            ListNode* next_group_start = curr->next;
            for (int j = 1; j < k; ++j) {
                curr->next = next_group_start->next;
                next_group_start->next = prev->next;
                prev->next = next_group_start;
                next_group_start = curr->next;
            }
            prev = curr;
            curr = next_group_start;
        }

        return dummy->next;
    }
};

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    Solution solution1;
    ListNode* result1 = solution1.reverseKGroup(head1, 2);
    std::cout << "Example 1 Output: ";
    printList(result1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    Solution solution2;
    ListNode* result2 = solution2.reverseKGroup(head2, 3);
    std::cout << "Example 2 Output: ";
    printList(result2);

    return 0;
}
