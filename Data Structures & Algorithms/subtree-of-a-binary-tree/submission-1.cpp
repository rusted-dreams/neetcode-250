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
    bool compare(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if((!p && q) || (!q && p)) return false;
        if(p->val != q->val) return false;

        bool left = compare(p->left, q->left);
        bool right = compare(p->right, q->right);

        return left && right;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root && !subRoot) return true;
        if(!root && subRoot) return false;
        if(root->val == subRoot->val) {
            if(compare(root, subRoot)) return true;
        }
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left || right;
    }
};
