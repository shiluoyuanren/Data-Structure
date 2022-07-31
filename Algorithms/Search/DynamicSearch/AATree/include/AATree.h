#ifndef _AATREE_H
#define _AATREE_H

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
class AATree : public dynamicSearchTable<KEY, OTHER> {
   private:
    struct AANode {
        SET<KEY, OTHER> data;
        AANode* left;
        AANode* right;
        int level;

        AANode(const SET<KEY, OTHER>& x,
               AANode* lt = NULL,
               AANode* rt = NULL,
               int h = 1)
            : data(x), left(lt), right(rt), level(h) {}
    };

    AANode* root;

   public:
    AATree() : root(NULL) {}
    ~AATree() { makeEmpty(root); }
    SET<KEY, OTHER>* find(const KEY& value) const;
    void insert(const SET<KEY, OTHER>& x);
    void remove(const KEY& value);

   private:
    void insert(const SET<KEY, OTHER>& x, AANode*& t);
    void remove(const KEY& value, AANode*& t);
    void makeEmpty(AANode* t);
    void LL(AANode*& t);
    void RR(AANode*& t);
    int min(int a, int b) { return a < b ? a : b; }
};

template <class KEY, class OTHER>
void AATree<KEY, OTHER>::makeEmpty(AANode* t) {
    if (t == NULL)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
    t = NULL;
}

template <class KEY, class OTHER>
SET<KEY, OTHER>* AATree<KEY, OTHER>::find(const KEY& value) const {
    AANode* t = root;
    while (t) {
        if (t->data.key == value)
            return (SET<KEY, OTHER>*)t;
        else if (t->data.key < value)
            t = t->right;
        else
            t = t->left;
    }
    return NULL;
}

template <class KEY, class OTHER>
void AATree<KEY, OTHER>::insert(const SET<KEY, OTHER>& x) {
    insert(x, root);
}

template <class KEY, class OTHER>
void AATree<KEY, OTHER>::insert(const SET<KEY, OTHER>& x, AANode*& t) {
    if (t == NULL)
        t = new AANode(x, NULL, NULL);
    else if (t->data.key < x.key)
        insert(x, t->right);
    else
        insert(x, t->left);
    LL(t);
    RR(t);
}

template <class KEY, class OTHER>
void AATree<KEY, OTHER>::LL(AANode*& t) {
    if (t->left != NULL && t->left->level == t->level) {
        AANode* tpl = t->left;
        t->left = tpl->right;
        tpl->right = t;
        t = tpl;
    }
}

template <class KEY, class OTHER>
void AATree<KEY, OTHER>::RR(AANode*& t) {
    if (t->right != NULL && t->right->right != NULL &&
        t->level == t->right->right->level) {
        AANode* tpl = t->right;
        t->right = tpl->left;
        tpl->left = t;
        t = tpl;
        ++t->level;
    }
}

template <class KEY, class OTHER>
void AATree<KEY, OTHER>::remove(const KEY& value) {
    remove(value, root);
}

template <class KEY, class OTHER>
void AATree<KEY, OTHER>::remove(const KEY& value, AANode*& t) {
    if (t == NULL)
        return;
    if (t->data.key == value) {
        if (t->left == NULL || t->right == NULL) {
            AANode* tpl = t;
            t = (t->left == NULL) ? t->right : t->left;
            delete tpl;
            tpl = NULL;
            return;
        } else {
            AANode* tpl = t->right;
            while (tpl->left)
                tpl = tpl->left;
            t->data = tpl->data;
            remove(tpl->data.key, t->right);
        }
    } else if (t->data.key < value)
        remove(value, t->right);
    else
        remove(value, t->left);
    //修改父节点的层次并调整平衡
    if (t->left == NULL || t->right == NULL)
        t->level = 1;
    else
        t->level = min(t->right->level, t->left->level) + 1;
    if (t->right != NULL && t->right->level > t->level)
        t->right->level = t->level;
    LL(t);  //消除根节点的水平左链
    if (t->right != NULL)
        LL(t->right);  //消除右节点的水平左链
    if (t->right != NULL && t->right->right != NULL)
        LL(t->right->right);  //消除右节点的右节点的水平左链
    // LL至多两次,左节点时两次,右节点时两次
    RR(t);  //消除水平右链,至多两次,左节点时一次,右节点两次
    if (t->right != NULL)
        RR(t->right);
}

#endif  // _AATREE_H