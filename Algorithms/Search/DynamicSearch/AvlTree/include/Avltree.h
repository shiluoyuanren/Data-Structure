#ifndef _AVLTREE_H
#define _AVLTREE_H

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
class AvlTree : public dynamicSearchTable<KEY, OTHER> {
   private:
    struct AvlNode {
        SET<KEY, OTHER> data;
        AvlNode* left;
        AvlNode* right;
        int height;

        AvlNode(const SET<KEY, OTHER>& x,
                AvlNode* lt = NULL,
                AvlNode* rt = NULL,
                int h = 1)
            : data(x), left(lt), right(rt), height(h) {}
    };
    AvlNode* root;

   public:
    AvlTree() { root = NULL; }
    ~AvlTree() { makeEmpty(root); }
    SET<KEY, OTHER>* find(const KEY& value) const;
    void insert(const SET<KEY, OTHER>& x);
    void remove(const KEY& value);

   private:
    void insert(const SET<KEY, OTHER>& x, AvlNode*& t);
    bool remove(const KEY& value, AvlNode*& t);
    void makeEmpty(AvlNode* t);
    int height(AvlNode* t) const { return t == NULL ? 0 : t->height; }
    void LL(AvlNode*& t);
    void LR(AvlNode*& t);
    void RL(AvlNode*& t);
    void RR(AvlNode*& t);
    int max(int a, int b) { return (a > b) ? a : b; }
    bool adjust(AvlNode*& t, int subTree);
};

template <class KEY, class OTHER>
SET<KEY, OTHER>* AvlTree<KEY, OTHER>::find(const KEY& value) const {
    AvlNode* cur = root;
    while (cur != NULL) {
        if (cur->data.key == value)
            return (SET<KEY, OTHER>*)cur;
        else if (cur->data.key < value)
            cur = cur->right;
        else
            cur = cur->left;
    }
    return NULL;
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::LL(AvlNode*& t) {
    AvlNode* t1 = t->left;  //未来节点
    t->left = t1->right;
    t1->right = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    t1->height = max(height(t1->left), height(t)) + 1;
    t = t1;
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::RR(AvlNode*& t) {
    AvlNode* t1 = t->right;
    t->right = t1->left;
    t1->left = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    t1->height = max(height(t), height(t1->right)) + 1;
    t = t1;
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::LR(AvlNode*& t) {
    RR(t->left);
    LL(t);
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::RL(AvlNode*& t) {
    LL(t->right);
    RR(t);
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::insert(const SET<KEY, OTHER>& x) {
    insert(x, root);
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::insert(const SET<KEY, OTHER>& x, AvlNode*& t) {
    if (!t)
        t = new AvlNode(x);
    else if (t->data.key < x.key) {
        insert(x, t->right);
        if (height(t->right) - height(t->left) == 2)
            if (x.key < t->right->data.key)
                RL(t);
            else
                RR(t);
    } else {
        insert(x, t->left);
        if (height(t->left) - height(t->right) == 2)
            if (x.key < t->left->data.key)
                LL(t);
            else
                LR(t);
    }

    t->height = max(height(t->right), height(t->left)) + 1;
    //重新计算高度,不可省略
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::remove(const KEY& value) {
    remove(value, root);
}

template <class KEY, class OTHER>
bool AvlTree<KEY, OTHER>::remove(const KEY& value, AvlNode*& t) {
    if (!t)
        return true;
    else if (t->data.key == value) {
        if (t->left == NULL || t->right == NULL) {
            AvlNode* tpl = t;
            t = (t->left == NULL) ? t->right : t->left;
            delete tpl;
            tpl = NULL;
            return false;
        } else {
            AvlNode* tpl = t->right;
            while (tpl->left != NULL)
                tpl = tpl->left;
            t->data = tpl->data;
            if (remove(tpl->data.key, t->right))
                return true;
            else
                return adjust(t, 1);
        }
    } else if (t->data.key < value) {
        if (remove(value, t->right))
            return true;
        else
            return adjust(t, 1);
    } else {
        if (remove(value, t->left))
            return true;
        else
            return adjust(t, 0);
    }
}

template <class KEY, class OTHER>  //平衡性检查
bool AvlTree<KEY, OTHER>::adjust(AvlNode*& t, int subTree) {
    if (subTree) {
        if (height(t->left) - height(t->right) == 1)  //情况1
            return true;
        if (height(t->left) == height(t->right)) {  //情况2
            --t->height;
            return false;
        }
        if (height(t->left) - height(t->right) == 2) {
            if (height(t->left->right) - height(t->left->left) == 1) {  //情况3
                LR(t);
                return false;
            } else if (height(t->left->left) - height(t->left->right) == 1) {
                LL(t);  //情况4
                return false;
            } else {  //情况5
                LL(t);
                return true;
            }
        }
    } else {
        if (height(t->right) - height(t->left) == 1)
            return true;
        if (height(t->left) == height(t->right)) {
            --t->height;
            return false;
        }
        if (height(t->right) - height(t->left) == 2) {
            if (height(t->right->right) - height(t->right->left) == 1) {
                RR(t);
                return false;
            } else if (height(t->right->left) - height(t->right->right) == 1) {
                RL(t);
                return false;
            } else {
                RR(t);
                return true;
            }
        }
    }
}

template <class KEY, class OTHER>
void AvlTree<KEY, OTHER>::makeEmpty(AvlNode* t) {
    if (!t)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
    t = NULL;
}

#endif  // _AVLTREE_H