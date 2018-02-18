/*
RookieRank4
#3 Height and Total Height of a BST
https://www.hackerrank.com/contests/rookierank-4/challenges/height-and-total-height-of-a-bst
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define max(a,b) a=(a>b?a:b)

class node
{
    public:
        int data;
        node* left;
        node* right;
        node()
        {
            //data = null;
            left = nullptr;
            right = nullptr;
        }
        node(int val) 
        {            
            data = val;
            left = nullptr;
            right = nullptr;
        }
        node(int val, node* l, node* r)
        {
            data = val;
            left = l;
            right = r;
        }
};

class bst
{    
    public:
        node root;
        bst(){}
        // bst(node n)
        // {
        //     this->root = n;
        // }
        // bst(int val)
        // {            
        //     root.data = new node(val);
        // }

    // bool search(int key, node* root)
    // {
    //     if (root == NULL)
    //     {            
    //         return false;
    //     }

    //     if (root.data == key)
    //     {            
    //         return true;
    //     }

    //     if (key < node.data)
    //     {
    //         return search(key, node.left);
    //     }
    //     else
    //     {
    //         return search(key, node.right);
    //     }

    // }

    node* insert(int key, node* root)
    {
        if (!root)
        {
            root = new node(key, nullptr, nullptr);
            cout << "inserting: " << root->data << endl;                        
            return root;
        }
        else if (key < root->data)
        {
            cout << "<- left " << key << " current Data: " << root->data << endl;
            root->left = insert(key, root->left);
        }
        else 
        {
            cout << "-> right" << key << " current Data: " << root->data << endl;
            root->right = insert(key, root->right);            
        }
        return root;
    }

};

// Traversing in PostOrder
int getWeights(node* root, int *pTotalHeight)
{
    int leftW = -1, rightW = -1;
    
    if (root->left != nullptr)
    {
        cout << "<- left " << root->data << endl;
        leftW = getWeights(root->left, pTotalHeight);
    }

    if (root->right != nullptr)
    {   cout << "-> right " << root->data << endl;
        rightW = getWeights(root->right, pTotalHeight);
        
        // int nodeW = max(leftW, rightW)+1;
        // cout << "weight: " << nodeW << " data: " << root->data << endl;
        
        // *pTotalHeight = *pTotalHeight + nodeW;
        // return nodeW;
    }
    //else
    {
       // leaf node
        int nodeW = max(leftW, rightW)+1;
        cout << "@weight: " << nodeW << " data: " << root->data << endl;
        
        *pTotalHeight = *pTotalHeight + nodeW;
        return nodeW;
    }
    
}

int main()
{
    int n; cin >> n;
    vector<int> v;
    
    // reading input values
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
        //cout << v[i] << " ";
    }
    
    node rootNode(v[0]);    
    //cout << endl <<"root Node: " << rootNode.data <<endl;

    bst tree;
    tree.root = rootNode;
    bst* ptrTree = &tree;    
    node* rt = &tree.root;

    for (int i = 1; i < n; i++)
    {        
        rt = tree.insert(v[i], rt);
    }
    
    int total_height = 0;
        
    // cout << "w-root: " << tree.root.data << endl;
    // cout << "rootLeft: " << &tree.root.left << " rootRight: " << &tree.root.right << endl;
    // cout << "rootLeftData: " << tree.root.left->data << " rootRightData: " << tree.root.right->data << endl;
    int tree_height = getWeights(&tree.root, &total_height);
    
    cout << tree_height << endl;
    cout << total_height << endl;
        
    return 0;
}
