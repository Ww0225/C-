//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct TreeNode {
//    char data;
//    struct TreeNode* left;
//    struct TreeNode* right;
//} TreeNode;
//// 前序遍历
//void preOrderTraversal(TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//    printf("%c ", root->data);
//    preOrderTraversal(root->left);
//    preOrderTraversal(root->right);
//}
//
//// 中序遍历
//void inOrderTraversal(TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//    inOrderTraversal(root->left);
//    printf("%c ", root->data);
//    inOrderTraversal(root->right);
//}
//
//// 后序遍历
//void postOrderTraversal(TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//    postOrderTraversal(root->left);
//    postOrderTraversal(root->right);
//    printf("%c ", root->data);
//}
//
//int countLeafNodes(TreeNode* root) {
//    if (root == NULL) {
//        return 0;
//    }
//    if (root->left == NULL && root->right == NULL) {
//        return 1;
//    }
//    return countLeafNodes(root->left) + countLeafNodes(root->right);
//}
//
//// 创建二叉树
//TreeNode* createTree(char data) {
//    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
//    newNode->data = data;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    return newNode;
//}
//
//// 递归构建二叉树
//void buildTree(TreeNode** root) {
//    char data;
//    scanf_s(" %c", &data); // 输入节点的数据
//
//    if (data == '#') {
//        *root = NULL; // 若输入 '#' 表示空节点
//    }
//    else {
//        *root = createTree(data);
//        buildTree(&((*root)->left)); // 递归构建左子树
//        buildTree(&((*root)->right)); // 递归构建右子树
//    }
//}
//
//int main() {
//    TreeNode* root = NULL;
//    printf("按前序顺序输入节点数据（#表示空节点）：\n");
//    buildTree(&root);
//
//    printf("前序遍历序列：");
//    preOrderTraversal(root);
//    printf("\n");
//
//    printf("中序遍历序列：");
//    inOrderTraversal(root);
//    printf("\n");
//
//    printf("后序遍历序列：");
//    postOrderTraversal(root);
//    printf("\n");
//
//    int leafCount = countLeafNodes(root);
//    printf("叶子结点个数：%d\n", leafCount);
//
//    return 0;
//}