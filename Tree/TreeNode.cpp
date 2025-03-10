#ifndef TreeNode_cpp
#define TreeNode_cpp
#include <iostream>
#include <vector>
using namespace std;

template <class Object>
class TreeNode
{
private:
    Object elem;
    TreeNode *parent;
    vector<TreeNode*> Child;

public:
    TreeNode(Object o = Object(), TreeNode *father = NULL) : elem(o), parent(father) {}
    TreeNode *&getParent() { return parent; }
    void setParent(TreeNode *father) { parent = father; }
    void insertChild(TreeNode *child) { Child.push_back(child); }
    vector<TreeNode *> &getChild() { return Child; }
    void setElem(Object o) { elem = o; }
    Object &getElem() { return elem; }
    bool hasChild() { return Child.size() > 0; }
};

void preOrder(TreeNode<int> *root, string p = "\n")
{
    if (root == 0)
        return;
    cout << p << root->getElem();
    // co the dung vong lap for de duyet con nhung phai khoi tao chi so i
    for (auto z : root->getChild())
        preOrder(z, p + "\t");
}

void inOrder(TreeNode<int> *root, string p = "\n")
{
    if (root == 0)
        return;
    if (root->hasChild())
        inOrder(root->getChild()[0], p + "\t");
    cout << p << root->getElem();

    for (int i = 1; i < root->getChild().size(); ++i)
        inOrder(root->getChild()[i], p + "\t");
}

void postOrder(TreeNode<int> *root, string p = "\n")
{
    if (root == 0)
        return;
    for (auto z : root->getChild())
        postOrder(z, p + "\t");
    cout << p << root->getElem();
}
#endif

/* int main()
{
    TreeNode<int> *p = new TreeNode<int>(3);
    TreeNode<int> *A = new TreeNode<int>(4);
    TreeNode<int> *B = new TreeNode<int>(5);
    p->getChild().push_back(A);
    p->getChild().push_back(B);
    TreeNode<int> *T = new TreeNode<int> (7, A);
    TreeNode<int> *T1 = new TreeNode<int> (6, B);
    TreeNode<int> *T2 = new TreeNode<int> (9, B);
    A->getChild().push_back(T);
    B->getChild().push_back(T1);
    B->getChild().push_back(T2);
    preOrder(p);
    cout << "\n";
    inOrder(p);
    cout << "\n";
    postOrder(p);
    return 0;
} */