/*
Day 23 - BST Level Order Traversal
https://www.hackerrank.com/challenges/30-binary-trees/problem
*/

#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }
// this code above is supplied
	void levelOrder(Node * root)
    {
        //Write your code here
        std::queue<Node*> myQueue;
        Node* current = root;

        while (current != NULL)
        {
            cout << current->data << " ";
            if (current->left != NULL) myQueue.push(current->left);
            if (current->right != NULL) myQueue.push(current->right);

            if (!myQueue.empty())
            {
                current = myQueue.front();
                myQueue.pop();
            }
            else
            {
                current = NULL;
            }
        }
	}

// this code bellow is supplied
        };//End of Solution
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}