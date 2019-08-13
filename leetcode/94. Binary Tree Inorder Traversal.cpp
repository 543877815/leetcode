/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode * inOrder(struct TreeNode* root, int* arr, int *size) {
    if(root == NULL) return NULL;
    if(root->left!=NULL) inOrder(root->left, arr, size);
    arr[(*size)++] = root->val;
    if(root->right!=NULL) inOrder(root->right, arr, size);
    return root;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *arr = (int*) malloc (sizeof(int) * 100);
    int size = 0;
    
    inOrder(root, arr, &size);

    * returnSize = size;
    return arr;
}

