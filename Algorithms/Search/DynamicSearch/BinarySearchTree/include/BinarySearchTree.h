#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

#include <iostream>

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
class dynamicSearchTable {
   public:
    virtual ~dynamicSearchTable() {}
    virtual SET<KEY, OTHER>* find(const KEY& value) const = 0;
    virtual void insert(const SET<KEY, OTHER>& x) = 0;
    virtual void remove(const KEY& value) = 0;
};

template <class KEY, class OTHER>
class BinarySearchTree : public dynamicSearchTable<KEY, OTHER> {
   private:
    struct BinaryNode {
        SET<KEY, OTHER> data;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const SET<KEY, OTHER>& x,
                   BinaryNode* lt = NULL,
                   BinaryNode* rt = NULL)
            : data(x), left(lt), right(rt) {}
    };
    BinaryNode* root;

   public:
    BinarySearchTree();
    ~BinarySearchTree();
    SET<KEY, OTHER>* find(const KEY& value) const;
    void insert(const SET<KEY, OTHER>& x);
    void remove(const KEY& value);

   private:
    void insert(const SET<KEY, OTHER>& x, BinaryNode*& t);
    void remove(const KEY& value, BinaryNode*& t);
    SET<KEY, OTHER>* find(const KEY& value, BinaryNode* t) const;
    void makeEmpty(BinaryNode* t);
};

template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::BinarySearchTree() {
    root = NULL;
}

template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::~BinarySearchTree() {
    makeEmpty(root);
}

template <class KEY, class OTHER>
SET<KEY, OTHER>* BinarySearchTree<KEY, OTHER>::find(const KEY& value) const {
    return find(value, root);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER>& x) {
    insert(x, root);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY& value) {
    remove(value, root);
}

template <class KEY, class OTHER>
SET<KEY, OTHER>* BinarySearchTree<KEY, OTHER>::find(const KEY& value,
                                                    BinaryNode* t) const {
    if (!t || t->data.key == value)
        return (SET<KEY, OTHER>*)t;
    if (t->data.key < value)
        return find(value, t->right);
    else
        return find(value, t->left);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert(const SET<KEY, OTHER>& x,
                                          BinaryNode*& t) {
    if (!t)
        t = new BinaryNode(x);
    else if (t->data.key < x.key)
        insert(x, t->right);
    else if (t->data.key > x.key)
        insert(x, t->left);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY& value, BinaryNode*& t) {
    if (!t)
        return;
    else if (t->data.key == value) {
        if (t->left == NULL || t->right == NULL) {
            BinaryNode* tpl = t;
            t = (t->left != NULL) ? t->left : t->right;
            delete tpl;
            tpl = NULL;
        } else {
            BinaryNode* tpl = t->right;
            while (tpl->left != NULL)
                tpl = tpl->left;
            SET<KEY, OTHER> add = t->data;
            t->data = tpl->data;
            tpl->data = add;
            remove(t->data.key, t->right);
        }
    } else if (t->data.key < value)
        remove(value, t->right);
    else
        remove(value, t->left);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::makeEmpty(BinaryNode* t) {
    if (!t)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
    t = NULL;
}

#endif  // _BINARYSEARCHTREE_H