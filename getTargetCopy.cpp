/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int findValue(TreeNode* original, TreeNode* target){
        
        if (original == nullptr) {
        return -1;
        }

        if (original == target) {
            return original->val;
        }

        // Traverse the left subtree
        int leftResult = findValue(original->left, target);
        if (leftResult != -1) {
            return leftResult;
        }

        // Traverse the right subtree
        int rightResult = findValue(original->right, target);
        return rightResult;
    }

    TreeNode* getClonedRef(TreeNode* cloned, int targetVal){
        if (cloned == nullptr) return nullptr;

        if (cloned->val == targetVal) {
            cout << "CValue: " << cloned->val << endl;
            return cloned;
        }

        // Search in the left subtree
        TreeNode* leftResult = getClonedRef(cloned->left, targetVal);
        if (leftResult != nullptr) {
            return leftResult;
        }

        // Search in the right subtree
        TreeNode* rightResult = getClonedRef(cloned->right, targetVal);
        return rightResult;
    }

    TreeNode* getTargetCopyHelper(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int value = findValue(original, target);
        cout << "Value: " << value << endl;
        return getClonedRef(cloned, value);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return getTargetCopyHelper(original, cloned, target);
    }
};