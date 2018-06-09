/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 
void find(TreeNode* root, int sum, vector<int>& curr_stack, vector<vector<int> >& ans){
    if(sum == 0 && root->left == NULL && root->right == NULL){
        ans.push_back(curr_stack);
    }
    
    if(root->left != NULL){
        curr_stack.push_back((root->left)->val);
        find(root->left, sum - (root->left)->val, curr_stack,ans);
        curr_stack.pop_back();
    }
    
    if(root->right != NULL){
        curr_stack.push_back((root->right)->val);
        find(root->right, sum - (root->right)->val, curr_stack,ans);
        curr_stack.pop_back();
    }
}
 
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > ans;
    vector<int> v;
    if(NULL == A)
        return ans;
    v.push_back(A->val);
    find(A,B- A->val,v,ans);
    return ans;
}