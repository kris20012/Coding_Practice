#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int preOrderTraversal(TreeNode *root, int maxVal, int & count){
    if(root != nullptr){
        cout << "Value: " << root->val << endl;
        if(root->val >= maxVal){
            cout << "Good Node: " << root->val << endl;
            maxVal = root->val;
            count++;
        }
        preOrderTraversal(root->left, maxVal, count);
        preOrderTraversal(root->right, maxVal, count);
    }
    return count;
}

int goodNodes(TreeNode* root) {
    int rootVal = root->val;
    int count = 0;
    preOrderTraversal(root, rootVal, count);
    return count;
}
