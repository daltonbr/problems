/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

#include<bits/stdc++.h>

bool has_cycle(Node* head)
{
    std::unordered_set<Node*> nodesVisited;
    
    while (head != NULL)
    {
        if (nodesVisited.find(head) == nodesVisited.end())
        {
            // not found this node, we add it to the set
            nodesVisited.insert(head);
            head = head->next;
        }
        else
        {
            // the node is already visited - a loop
            return true;
        }
    }
    return false;  
}
