class Solution {
  public:
    bool helper(Node* left, Node* right) {
        if (!left || !right) return left==right;
        if (left->data!=right->data) return false;
        return (helper(left->left, right->right) && helper(left->right, right->left));
    }
    bool isSymmetric(Node* root) {
        // Code here
        return helper(root->left, root->right);
    }
};
