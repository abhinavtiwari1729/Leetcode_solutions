class Solution {
public:
    int maxLevelSum(TreeNode* root) {
    
        int max_sum = INT_MIN;
        int max_level = 0;
        int curr_level = 0;

        queue<TreeNode *> qu;
        qu.push(root);

        while(!qu.empty()) {
            
            curr_level++;
            int curr_sum = 0 ;
            int size = qu.size();

            for (int i = 0 ; i < size ; i++) {

                TreeNode *node = qu.front();
                qu.pop();

                curr_sum += node->val;
                if(node->left)
                    qu.push(node->left);
                if(node->right)
                    qu.push(node->right);


            }

            if (curr_sum > max_sum) {
                max_sum = curr_sum ;
                max_level = curr_level;
            }


        }

        return max_level;
    }
};
