#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#include <set>
#include <iomanip>
#include "TreeNode.h"

using namespace std;

vector<TreeNode> getCountOfLetters(string text);

bool compareTreeNodeCounts(const TreeNode &first, const TreeNode &second);

list<TreeNode *> createPointersList(vector<TreeNode> v);

void getCodesForLetters(TreeNode *p, map<char, string> &codesMap, string code);

string codeTextUsingMapWithCodes(string text, map<char, string> codes);

string decodeTextUsingMapWithCodes(TreeNode *root, string text);

void printTreeNodesVector(vector<TreeNode> v);

void printTreeNodesList(list<TreeNode *> l);

int main(int argc, char *argv[]) {

    string text = "To jest jakis przykladowy tekst, ktory bedzie szyfrowany, a nastepnie rozszyfrowywany.";

    vector<TreeNode> noOfLetters = getCountOfLetters(text);

    sort(noOfLetters.begin(), noOfLetters.end(), compareTreeNodeCounts);

    list<TreeNode *> noOfLettersList = createPointersList(noOfLetters);

    while (noOfLettersList.size() > 1) {
        TreeNode *first = noOfLettersList.front();
        noOfLettersList.pop_front();
        TreeNode *second = noOfLettersList.front();
        noOfLettersList.pop_front();

        TreeNode *newTreeNode = new TreeNode();
        newTreeNode->setCount(first->getCount() + second->getCount());
        newTreeNode->setLeft(first);
        newTreeNode->setRight(second);

        list<TreeNode *>::iterator iterator = noOfLettersList.begin();
        while ((*iterator)->getCount() < newTreeNode->getCount()) {
            if (iterator == noOfLettersList.end()) {
                break;
            }
            iterator++;
        }
        noOfLettersList.insert(iterator, newTreeNode);
    }

    TreeNode *root = noOfLettersList.front();
    map<char, string> lettersCodesMap;

    getCodesForLetters(root, lettersCodesMap, "");

    string codedText = codeTextUsingMapWithCodes(text, lettersCodesMap);

    cout << codedText << endl;

    cout << decodeTextUsingMapWithCodes(root, codedText) << endl;

    return 0;
}

vector<TreeNode> getCountOfLetters(string text) {
    map<char, int> tempCounts;
    vector<TreeNode> notSortedCounts;
    for (int i = 0; i < text.size(); i++) {
        char currentLetter = text.at(i);
        if (tempCounts[currentLetter] != (int) NULL) {
            int currentCount = tempCounts.at(currentLetter);
            currentCount++;
            tempCounts[currentLetter] = currentCount;
        } else {
            tempCounts[currentLetter] = 1;
        }
    }
    typedef map<char, int>::iterator it_type;
    for (it_type iterator = tempCounts.begin(); iterator != tempCounts.end(); iterator++) {
        TreeNode *newTreeNode = new TreeNode(iterator->first, iterator->second);
        notSortedCounts.push_back(*newTreeNode);
    }
    return notSortedCounts;
}

bool compareTreeNodeCounts(const TreeNode &first, const TreeNode &second) {
    return first.getCount() <= second.getCount();
}

list<TreeNode *> createPointersList(vector<TreeNode> v) {
    list<TreeNode *> pointersList;
    for (int i = 0; i < v.size(); i++) {
        TreeNode *treeNode = new TreeNode(v.at(i).getSymbol(), v.at(i).getCount());
        pointersList.push_back(treeNode);
    }
    return pointersList;
}

void getCodesForLetters(TreeNode *p, map<char, string> &codesMap, string code = "") {
    if (p != NULL) {
        if (p->getSymbol() != (char) NULL) {
            codesMap[p->getSymbol()] = code;
        }
        if (p->getLeft()) {
            string newCode = code + "0";
            getCodesForLetters(p->getLeft(), codesMap, newCode);
        }
        if (p->getRight()) {
            string newCode = code + "1";
            getCodesForLetters(p->getRight(), codesMap, newCode);
        }
    }
}

string codeTextUsingMapWithCodes(string text, map<char, string> codes) {
    string codedText = "";
    for (int i = 0; i < text.size(); i++) {
        codedText += codes[text.at(i)];
    }
    return codedText;
}

string decodeTextUsingMapWithCodes(TreeNode *root, string text) {
    int i = 0;
    string decodedText = "";
    TreeNode *p = root;
    while (i != text.size()) {
        TreeNode *parentP = p;
        if (text.at(i) == '0'){
            p = p->getLeft();
        } else if (text.at(i) == '1'){
            p = p->getRight();
        }
        if (p == NULL){
            decodedText += parentP->getSymbol();
            p = root;
        } else {
            i++;
        }
    }
    return decodedText;
}

void printTreeNodesVector(vector<TreeNode> v) {
    typedef vector<TreeNode>::iterator it_type;
    cout << "Vector: ";
    for (it_type iterator = v.begin(); iterator != v.end(); iterator++) {
        cout << "[" << iterator->getSymbol() << ": " << iterator->getCount() << "], ";
    }
    cout << endl;
}

void printTreeNodesList(list<TreeNode *> l) {
    typedef list<TreeNode *>::iterator it_type;
    cout << "List: ";
    for (it_type iterator = l.begin(); iterator != l.end(); iterator++) {
        cout << "[" << (*iterator)->getSymbol() << ": " << (*iterator)->getCount() << "], ";
    }
    cout << endl;
}