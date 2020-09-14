/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur = head;
	    ListNode* res = new ListNode(0);		// 新开辟的链表指针
	    ListNode* pre = res;				// 用于找到插入位置

	    while (cur)
	    {
		    pre = res;
		    while (pre->next != nullptr && pre->next->val < cur->val)	// 寻找插入位置
			    pre = pre->next;

		    ListNode* tmp = cur->next;		// 先将cur后面的指针保存，否则插入后，将失去后面未插入的节点
		    cur->next = pre->next;			// 执行插入操作，先更新其指向后的指针
		    pre->next = cur;				// 更新其前一个指针的指向，完成插入操作
		    cur = tmp;						// cur更新为未插入的节点
	    }
	return res->next;
    }
};
