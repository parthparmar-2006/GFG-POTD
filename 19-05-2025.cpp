class Solution {
  public:
    Node* rightMost(Node* root) {
        while (root->right) root=root->right;
        return root;
    }
    Node* leftMost(Node* root) {
        while (root->left) root=root->left;
        return root;
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node *pre=nullptr, *succ=nullptr;
        while (root) {
            if (root->data < key) {
                pre = root;
                root = root->right;
            } else if (root->data > key) {
                succ = root;
                root = root->left;
            } else {
                if (root->left) pre = rightMost(root->left);
                if (root->right) succ = leftMost(root->right);
                break;
            }
        } return {pre, succ};
    }
};
