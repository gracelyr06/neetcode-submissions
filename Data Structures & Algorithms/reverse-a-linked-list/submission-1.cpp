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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr){
            return nullptr;
        } else if (head->next == nullptr) {
            return head;
        }
        ListNode* currNode = head;
        ListNode* nextNode = currNode->next;
        currNode->next = nullptr;
        ListNode* nextNextNode = nextNode->next;
        while (nextNode != nullptr) {
            // A<-B->C
            // temp = B
            // B->next = A
            // cur A temp B 
            nextNode->next = currNode; // B->next = A
            currNode = nextNode; // currNode = B
            nextNode = nextNextNode;
            if (nextNode != nullptr) {
                nextNextNode = nextNode->next;
            }  else {
                return currNode;
            }
        }
        return currNode;
    }
};
