//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct TreeNode {
//    char data;
//    struct TreeNode* left;
//    struct TreeNode* right;
//} TreeNode;
//// ǰ�����
//void preOrderTraversal(TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//    printf("%c ", root->data);
//    preOrderTraversal(root->left);
//    preOrderTraversal(root->right);
//}
//
//// �������
//void inOrderTraversal(TreeNode* root) {
//    if (root == NULL) {
//        return;
//    }
//    inOrderTraversal(root->left);
//    printf("%c ", root->data);
//    inOrderTraversal(root->right);
//}
//
//// �������
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
//// ����������
//TreeNode* createTree(char data) {
//    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
//    newNode->data = data;
//    newNode->left = NULL;
//    newNode->right = NULL;
//    return newNode;
//}
//
//// �ݹ鹹��������
//void buildTree(TreeNode** root) {
//    char data;
//    scanf_s(" %c", &data); // ����ڵ������
//
//    if (data == '#') {
//        *root = NULL; // ������ '#' ��ʾ�սڵ�
//    }
//    else {
//        *root = createTree(data);
//        buildTree(&((*root)->left)); // �ݹ鹹��������
//        buildTree(&((*root)->right)); // �ݹ鹹��������
//    }
//}
//
//int main() {
//    TreeNode* root = NULL;
//    printf("��ǰ��˳������ڵ����ݣ�#��ʾ�սڵ㣩��\n");
//    buildTree(&root);
//
//    printf("ǰ��������У�");
//    preOrderTraversal(root);
//    printf("\n");
//
//    printf("����������У�");
//    inOrderTraversal(root);
//    printf("\n");
//
//    printf("����������У�");
//    postOrderTraversal(root);
//    printf("\n");
//
//    int leafCount = countLeafNodes(root);
//    printf("Ҷ�ӽ�������%d\n", leafCount);
//
//    return 0;
//}