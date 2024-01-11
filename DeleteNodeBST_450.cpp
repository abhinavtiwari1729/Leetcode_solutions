class Solution {

    TreeNode * FindMin(TreeNode * root) {
        while(root->left)
            root = root->left;

        return root;
    }


public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (!root)
            return root;
        
        if (key < root->val)
           root->left = deleteNode(root->left , key);
        else if (key > root->val)
            root->right = deleteNode(root->right , key);
        else {

            if (root->left == NULL && root->right == NULL){
                    delete root;
                    root = NULL;
            }

            else if (root->left == NULL) {
                TreeNode * temp = root;
                root = root->right;
                delete temp;
            }          

            else if (root->right == NULL) {
                TreeNode * temp = root;
                root = root->left;
                delete temp;
            }

            else {
                
                TreeNode * min = FindMin(root->right);
                root->val = min->val;
                root->right = deleteNode(root->right , root->val);
            
            }

        } 

        return root;
    }      
};
