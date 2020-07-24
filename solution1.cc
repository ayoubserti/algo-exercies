#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    int getListLength(ListNode* head){
        
        if ( head == nullptr )
            return 0;
        
        int n=1;
        while(head!= nullptr)
        {
            head = head->next;
            if ( head != nullptr )
                n++;
        }
        return n;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len = getListLength(head) - n-1;
        ListNode *node , *ptr;
        node= head;
        while(len>0 ){
            node=node->next;
            len--;
        }
        
        ptr= node->next;
        node->next = ptr->next;
        delete ptr;

        return head;
    }
};

static void printList ( const ListNode* head)
{
    const ListNode* ptr = head;
    while(ptr!= nullptr)
    {
        std::cout << ptr->val;
        if ( ptr->next)
            std::cout << "->";
        ptr= ptr->next;
    }
    std::cout << std::endl;
}

int main(int argv, char** argc)
{
    ListNode* node , *ptr;
    int elm= 10;
    for( int i = elm; i> 0; --i)
    {
        node = new ListNode(i,nullptr);
        if ( i != elm){
            node->next = ptr;
        }
        ptr = node;
    }
    printList(node);

    Solution sol;
    printList(sol.removeNthFromEnd(node,4));

    return 0;
}