/* Linked List
https://www.hackerrank.com/challenges/30-linked-list/problem
*/

#include <iostream>
#include <cstddef>
using namespace std;	

class Node
{
    public:
        int data;
        Node *next;
        Node(int d)
        {
            data = d;
            next = NULL;
        }
};


class Solution{
    public:
        Node* insert(Node *head,int data)
        {
            Node *start = head;
            // the keyword 'new' does not declare variables. It allocates memory.
            Node *newNode = new Node(data);
            
            // Special case for empty list
            if (start == NULL)
            {
                head = newNode;
                return head;
            }                
            
            // Traverse the list through the last VALID node
            while(start->next)
            {
                start = start->next;
            }            
            start->next = newNode;

            return head;
        }

        // bellow is the suplied code
        void display (Node *head)
        {
            Node *start = head;
            while(start)
            {
                cout << start->data << " ";
                start = start->next;
            }
        }
};

int main()
{
	Node* head=NULL;
  	Solution mylist;
    int T, data;
    cin >> T;
    while (T-->0)
    {
        cin >> data;
        head = mylist.insert(head,data);
    }	
	mylist.display(head);
		
}
