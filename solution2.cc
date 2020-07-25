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


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        /*
         to remove the n-th element from End in one single pass
         we need to keep track on the recent n elements 
         So, we use a pointer that's alway pointing to (n+1)-th element
         from the end `node2`
        */
        
        ListNode *ptr1 ,*ptr2, *ptr;
        ptr1=  ptr= head;
        
        int i=0; //we are in the first
        while(ptr1!= nullptr){
            
            
            if( i > n)
            {
                ptr=ptr->next;
            }
            
            i++;
            ptr1= ptr1->next;    
        }
        
        ListNode* tmp = ptr->next;
        if( tmp != nullptr)
        {
            ptr->next = tmp->next;
            delete tmp;
        }

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
    int elm= 5;
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