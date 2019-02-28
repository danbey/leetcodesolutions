/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {


			if (!l1 || !l2)
				return NULL;

			bool is_first = true;

			ListNode *head;
			ListNode *prev;

			int curr_sum = 0;

			while (l1 || l2) {


				if (l1 && l1->val) curr_sum += l1->val;
				if (l2 && l2->val) curr_sum += l2->val;

				ListNode * nd = new ListNode(curr_sum % 10);

				if (is_first) {    
					prev = head = nd;
					is_first = false;
				} else {
					prev->next = nd;
					prev = nd;
				}


				if (curr_sum >= 10 )
					curr_sum = 1;
				else
					curr_sum = 0;

				if (l1) l1 = l1->next;
				if (l2) l2 = l2->next;

			}

			if (curr_sum) {
				prev->next = new ListNode(curr_sum);

			}

			return head;
		}
};
