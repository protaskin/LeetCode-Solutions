class Solution {
public:
    ListNode* getIntersectionNode(const ListNode* const headA, const ListNode* const headB) {
        auto nodeA = headA;
        auto nodeB = headB;

        while (nodeA != nodeB) {
            nodeA = nodeA->next;
            nodeB = nodeB->next;

            if (nodeA == nullptr) {
                if (nodeB != nullptr) {
                    nodeA = headB;
                }
            } else if (nodeB == nullptr) {
                nodeB = headA;
            }
        }

        return const_cast<ListNode*>(nodeA);
    }
};
