#  Remove Nth Node From End of List
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

# Solution

A basic solution is propused in `solution1.cc` which make a double pass. The first pass using `getListLength` function that calculate the length of the linked list. Then a second pass that find the n-th element from tail and remove it.
