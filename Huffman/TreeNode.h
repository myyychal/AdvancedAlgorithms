#include "Node.h"

class TreeNode : public Node{
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;

public:

    TreeNode *getParent() const;

    void setParent(TreeNode *parent);

    TreeNode *getLeft() const;

    void setLeft(TreeNode *left);

    TreeNode *getRight() const;

    void setRight(TreeNode *right);

    std::string toString();

    TreeNode(char c, int i);

    TreeNode();
};