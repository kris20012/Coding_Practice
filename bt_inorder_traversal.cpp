#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
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
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> tmp;
        inorderTraversalHelper(root, tmp);
        return tmp;
    }

    void inorderTraversalHelper(TreeNode* root, vector<int> & output) {
        
        if(root == nullptr){
            cout << "Empty" << endl;
            return;
        } 
        
        inorderTraversalHelper(root -> left, output);

        cout << "Val: " << root->val << endl; 
        output.push_back(root->val);
       
        inorderTraversalHelper(root -> right, output);     
    }


};