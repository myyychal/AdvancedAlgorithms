#include <iostream>
#include <cstdio>
#include "TreeNode.h"

TreeNode::TreeNode(char c, int i) {
    this->symbol = c;
    this->count = i;
    parent = NULL;
    left = NULL;
    right = NULL;
}

TreeNode::TreeNode() {
    this->symbol = (char) NULL;
    this->count = 0;
    parent = NULL;
    left = NULL;
    right = NULL;
}

TreeNode *TreeNode::getParent() const {
    return parent;
}

void TreeNode::setParent(TreeNode *parent) {
    this->parent = parent;
}

TreeNode *TreeNode::getLeft() const {
    return left;
}

void TreeNode::setLeft(TreeNode *left) {
    this->left = left;
    left->parent = this;
}

TreeNode *TreeNode::getRight() const {
    return right;
}

void TreeNode::setRight(TreeNode *right) {
    this->right = right;
    right->parent = this;
}

std::string TreeNode::toString() {
    if (this != NULL){
        std::string symbolString = std::string(1,this->getSymbol());
        std::string tmp;
        std::sprintf((char*)tmp.c_str(), "%d", this->getCount());
        std::string str = tmp.c_str();
        return "[" + symbolString + ":" + str + "]";
    } else {
        return "";
    }

}