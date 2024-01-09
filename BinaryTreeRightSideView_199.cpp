class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> result;
        if (!root)
            return result;
        
        queue<TreeNode*> qu;
        qu.push(root);
        qu.push(nullptr);
        while(!qu.empty()) {

            TreeNode * node = qu.front();
            if (node == nullptr){
                qu.pop();
                if (!qu.empty())
                    qu.push(nullptr);
            }
            else {
                if (node->left)
                    qu.push(node->left);
                if (node->right)
                    qu.push(node->right);

                qu.pop();
                if (qu.front() == nullptr)
                    result.push_back(node->val);                

            }
        }
        return result;
    }
};
