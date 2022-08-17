#include <iostream>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

struct treeInfo
{
    int diameter;
    int height;
};
treeInfo getTreeInfo(BinaryTree* tree);

int binaryTreeDiameter(BinaryTree* tree);
int main()
{
    BinaryTree* root = new BinaryTree(1);
    root->left = new BinaryTree(3);
    root->left->left = new BinaryTree(7);
    root->left->left->left = new BinaryTree(8);
    root->left->left->left->left = new BinaryTree(9);
    root->left->right = new BinaryTree(4);
    root->left->right->right = new BinaryTree(5);
    root->left->right->right->right = new BinaryTree(6);
    root->right = new BinaryTree(2);
    int result =  binaryTreeDiameter(root );

    cout << result;
     
    return 0;
}
int binaryTreeDiameter(BinaryTree* tree) {
    // Write your code here.
    return getTreeInfo(tree).diameter;
}

treeInfo getTreeInfo(BinaryTree* tree)
{
    if (tree == nullptr)return treeInfo{ 0,0 };

    treeInfo leftTreeInfo = getTreeInfo(tree->left);
    treeInfo rightTreeInfo = getTreeInfo(tree->right);

    int longestPathThroughRoot = leftTreeInfo.height + rightTreeInfo.height;
    int maxDiameterSofar = max(leftTreeInfo.diameter, rightTreeInfo.diameter);
    int curDiameter = max(longestPathThroughRoot, maxDiameterSofar);
    int curheight = 1 + max(leftTreeInfo.height, rightTreeInfo.height);

    return treeInfo{ curDiameter, curheight };

}