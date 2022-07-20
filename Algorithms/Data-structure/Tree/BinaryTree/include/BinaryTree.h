#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <iostream>
#include <queue>

template <class Temp>
class bTree {  //二叉树的模板类
   public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual Temp Root(const Temp& flag) const = 0;
    virtual Temp Parent(const Temp& x, const Temp& flag) const = 0;
    virtual Temp lchild(const Temp& x, const Temp& flag) const = 0;
    virtual Temp rchild(const Temp& x, const Temp& flag) const = 0;
    virtual void delLeft(const Temp& x) = 0;
    virtual void delRight(const Temp& x) = 0;
    virtual void preOrder() const = 0;
    virtual void midOrder() const = 0;
    virtual void postOrder() const = 0;
    virtual void levelOrder() const = 0;
    virtual ~bTree(){};
};

template <class Temp>
class binaryTree : public bTree<Temp> {  //二叉链表类
    template <class Type>
    friend void printTree(const binaryTree<Type>& t, const Type& flag);

   private:
    struct node {
        node *left, *right;
        Temp data;

        node() : left(NULL), right(NULL) {}
        node(Temp value, node* L = NULL, node* R = NULL)
            : data(value), left(L), right(R) {}
        ~node() {}
    };

    node* root;  //根节点
    int test = 90;

   public:
    binaryTree() : root(NULL) {}
    binaryTree(const Temp& x) { root = new node(x); }
    ~binaryTree();
    void clear();
    bool isEmpty() const;
    Temp Root(const Temp& flag) const;
    Temp lchild(const Temp& x, const Temp& flag) const;
    Temp rchild(const Temp& x, const Temp& flag) const;
    void delLeft(const Temp& x);
    void delRight(const Temp& x);
    void preOrder() const;
    void midOrder() const;
    void postOrder() const;
    void levelOrder() const;
    void createTree(const Temp& flag);
    Temp Parent(const Temp& x, const Temp& flag) const { return flag; }

   private:
    node* find(const Temp& x, node* t) const;
    void clear(node*& t);
    void preOrder(node* t) const;
    void midOrder(node* t) const;
    void postOrder(node* t) const;
};

template <class Temp>
void printTree(const binaryTree<Temp>& t, const Temp& flag) {
    std::queue<struct binaryTree<Temp>::node*> q;
    struct binaryTree<Temp>::node* cur = t.root;
    q.push(cur);
    Temp ldata, rdata;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (!cur->left)
            ldata = flag;
        else
            ldata = cur->left->data;
        if (!cur->right)
            rdata = flag;
        else
            rdata = cur->right->data;
        std::cout << cur->data << " " << ldata << " " << rdata << std::endl;
        if (ldata != flag)
            q.push(cur->left);
        if (rdata != flag)
            q.push(cur->right);
    }
}

template <class Temp>
binaryTree<Temp>::~binaryTree() {
    clear(root);
}

template <class Temp>
void binaryTree<Temp>::clear() {
    clear(root);
}

template <class Temp>
bool binaryTree<Temp>::isEmpty() const {
    return root == NULL;
}

template <class Temp>
Temp binaryTree<Temp>::Root(const Temp& flag) const {
    if (!root)
        return root->data;
    return flag;
}

template <class Temp>
Temp binaryTree<Temp>::lchild(const Temp& x, const Temp& flag) const {
    node* tpl = find(x, root);
    if (tpl == NULL || tpl->left == NULL)
        return flag;
    return tpl->left->data;
}

template <class Temp>
Temp binaryTree<Temp>::rchild(const Temp& x, const Temp& flag) const {
    node* tpl = find(x, root);
    if (tpl == NULL || tpl->right == NULL)
        return flag;
    return tpl->right->data;
}

template <class Temp>
void binaryTree<Temp>::delLeft(const Temp& x) {
    node* tpl = find(x, root);
    if (!tpl)
        return;
    clear(tpl->left);
}

template <class Temp>
void binaryTree<Temp>::delRight(const Temp& x) {
    node* tpl = find(x, root);
    if (!tpl)
        return;
    clear(tpl->right);
}

template <class Temp>
void binaryTree<Temp>::preOrder() const {
    std::cout << "\n前序遍历:";
    preOrder(root);
}

template <class Temp>
void binaryTree<Temp>::midOrder() const {
    std::cout << "\n中序遍历:";
    midOrder(root);
}

template <class Temp>
void binaryTree<Temp>::postOrder() const {
    std::cout << "\n后序遍历:";
    postOrder(root);
}

template <class Temp>
void binaryTree<Temp>::levelOrder() const {
    std::queue<node*> q;
    std::cout << "\n层次遍历:";
    if (root)
        q.push(root);
    while (!q.empty()) {
        node* cur = q.front();
        q.pop();
        std::cout << cur->data << " ";
        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
}

template <class Temp>
void binaryTree<Temp>::createTree(const Temp& flag) {
    std::queue<node*> q;
    node* cur;
    Temp ldata, rdata;
    root = new node;
    std::cout << "输入根节点:";
    std::cin >> root->data;
    q.push(root);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        std::cout << "\n输入" << cur->data << "的两个儿子(" << flag
                  << "表示空节点):";
        std::cin >> ldata >> rdata;
        if (ldata != flag) {
            cur->left = new node(ldata);
            q.push(cur->left);
        }
        if (rdata != flag) {
            cur->right = new node(rdata);
            q.push(cur->right);
        }
    }
    std::cout << "\ncreate completed!\n";
}

template <class Temp>
class binaryTree<Temp>::node* binaryTree<Temp>::find(
    const Temp& x,
    binaryTree<Temp>::node* t) const {
    if (t == NULL)
        return NULL;
    if (t->data == x)
        return t;
    if (find(x, t->left) == NULL)
        return find(x, t->right);
    else
        return find(x, t->left);
}

template <class Temp>
void binaryTree<Temp>::clear(binaryTree<Temp>::node*& t) {
    if (t == NULL)
        return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = NULL;
}

template <class Temp>
void binaryTree<Temp>::preOrder(node* t) const {
    if (t == NULL)
        return;
    std::cout << t->data << " ";
    preOrder(t->left);
    preOrder(t->right);
}

template <class Temp>
void binaryTree<Temp>::midOrder(node* t) const {
    if (t == NULL)
        return;
    midOrder(t->left);
    std::cout << t->data << " ";
    midOrder(t->right);
}

template <class Temp>
void binaryTree<Temp>::postOrder(node* t) const {
    if (t == NULL)
        return;
    postOrder(t->left);
    postOrder(t->right);
    std::cout << t->data << " ";
}

#endif