/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split into two lists
        prev->next = NULL;

        // Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge
        return merge(left, right);
    }

    ListNode* merge(ListNode* a, ListNode* b) {

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while (a != NULL && b != NULL) {

            if (a->val < b->val) {
                temp->next = a;
                a = a->next;
            }
            else {
                temp->next = b;
                b = b->next;
            }

            temp = temp->next;
        }

        if (a != NULL)
            temp->next = a;
        else
            temp->next = b;

        return dummy.next;
    }
};