#ifndef _REDBLACKTREE_H
#define _REDBLACKTREE_H

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
class RedBlackTree : public dynamicSearchTable<KEY, OTHER> {
   private:
    enum colourT { RED, BLACK };  //枚举类型
    struct RedBlackNode {
        SET<KEY, OTHER> data;
        RedBlackNode* left;
        RedBlackNode* right;
        colourT colour;

        RedBlackNode(const SET<KEY, OTHER>& x,
                     RedBlackNode* lt = NULL,
                     RedBlackNode* rt = NULL,
                     colourT h = RED)
            : data(x), left(lt), right(rt), colour(h) {}
    };

    RedBlackNode* root;

   public:
    RedBlackTree(RedBlackNode* t = NULL) : root(t) {}
    ~RedBlackTree() { makeEmpty(root); }
    SET<KEY, OTHER>* find(const KEY& key) const;
    void insert(const SET<KEY, OTHER>& x);
    void remove(const KEY& value);

   private:
    void makeEmpty(RedBlackNode* t);
    void insertAdjust(RedBlackNode* gp, RedBlackNode* p, RedBlackNode* t);
    void removeAdjust(RedBlackNode*& p,
                      RedBlackNode*& c,
                      RedBlackNode*& t,
                      const KEY& del);
    void LL(RedBlackNode* gp);
    void LR(RedBlackNode* gp);
    void RL(RedBlackNode* gp);
    void RR(RedBlackNode* gp);
};

template <class KEY, class OTHER>
SET<KEY, OTHER>* RedBlackTree<KEY, OTHER>::find(const KEY& value) const {
    RedBlackNode* p = root;
    while (p) {
        if (p->data.key == value)
            return (SET<KEY, OTHER>*)p;
        else if (p->data.key < value)
            p = p->right;
        else
            p = p->left;
    }
    return NULL;
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::makeEmpty(RedBlackNode* t) {
    if (t == NULL)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
    t = NULL;
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::insert(const SET<KEY, OTHER>& x) {
    RedBlackNode *t, *p, *gp;
    t = p = gp = root;
    if (root == NULL) {
        root = new RedBlackNode(x, NULL, NULL, BLACK);
        return;
    }
    while (t) {
        if (t->left && t->left->colour == RED && t->right &&
            t->right->colour == RED) {
            t->colour = RED;
            t->left->colour = t->right->colour = BLACK;
            insertAdjust(gp, p, t);
        }
        gp = p;
        p = t;
        t = (t->data.key > x.key) ? t->left : t->right;
    }
    t = new RedBlackNode(x);
    if (p->data.key > x.key)
        p->left = t;
    else
        p->right = t;
    insertAdjust(gp, p, t);
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::insertAdjust(RedBlackNode* gp,
                                            RedBlackNode* p,
                                            RedBlackNode* t) {
    if (p->colour == RED) {
        if (p == root) {
            p->colour = BLACK;
            return;
        }
        if (gp->left == p)
            if (p->left == t)
                LL(gp);
            else
                LR(gp);
        else if (p->left == t)
            RL(gp);
        else
            RR(gp);
    }
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::LL(RedBlackNode* gp) {
    RedBlackNode tpl = *gp;  // tpl如果是指针,值会发生变化,无法交换
    RedBlackNode* p = gp->left;
    RedBlackNode* t = p->left;
    gp->data = p->data;
    gp->left = t;
    gp->right = p;
    p->data = tpl.data;
    p->left = p->right;
    p->right = tpl.right;
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::LR(RedBlackNode* gp) {
    RR(gp->left);
    LL(gp);
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::RR(RedBlackNode* gp) {
    RedBlackNode* p = gp->right;
    RedBlackNode* t = p->right;
    RedBlackNode tpl = *gp;
    gp->data = p->data;
    gp->right = t;
    gp->left = p;
    p->right = p->left;
    p->left = tpl.left;
    p->data = tpl.data;
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::RL(RedBlackNode* gp) {
    LL(gp->right);
    RR(gp);
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::remove(const KEY& value) {
    RedBlackNode *t, *p, *c;
    KEY del = value;
    t = p = c = root;
    if (root->data.key == del && root->left == NULL && root->right == NULL) {
        delete root;
        root = NULL;
        return;
    }
    while (c) {
        removeAdjust(p, c, t, del);
        if (c->data.key == del) {
            if (c->left == NULL || c->right == NULL) {
                RedBlackNode* tpl = c;
                c = (c->left == NULL) ? c->right : c->right;
                if (del == p->data.key) {
                    if (del > value)
                        p->right = c;
                    else
                        p->left = c;
                } else {
                    if (p->data.key < value)
                        p->right = c;
                    else
                        p->left = c;
                }
                delete tpl;
                tpl = NULL;
                root->colour = BLACK;
                return;
            } else {
                RedBlackNode* tpl = c->right;
                while (tpl->left)
                    tpl = tpl->left;
                c->data = tpl->data;
                del = tpl->data.key;
                p = c;
                c = c->right;
                t = p->left;
                continue;
            }
        } else if (c->data.key < del) {
            p = c;
            c = c->right;
            t = p->left;
        } else {
            p = c;
            c = c->left;
            t = p->right;
        }
    }
}

template <class KEY, class OTHER>
void RedBlackTree<KEY, OTHER>::removeAdjust(RedBlackNode*& p,
                                            RedBlackNode*& c,
                                            RedBlackNode*& t,
                                            const KEY& del) {
    if (c->colour == RED)
        return;
    // if (c == root) {
    //     if (c->left && c->right && c->left->colour == c->right->colour) {
    //         c->colour = RED;
    //         c->left->colour = c->right->colour = BLACK;
    //         return;
    //     }
    // }
    if ((c->left == NULL || c->left && c->left->colour) &&
        (c->right == NULL || c->right && c->right->colour)) {
        if ((t->left == NULL || t->left && t->left->colour) &&
            (t->right == NULL || t->right && t->right->colour)) {
            p->colour = BLACK;
            t->colour = c->colour = RED;
        } else {
            if (p->left == t) {
                if (t->left && t->left->colour == RED) {
                    t->left->colour = BLACK;
                    LL(p);
                } else {
                    t->right->colour = BLACK;
                    LR(p);
                }
            } else if (t->right && t->right->colour == RED) {
                t->right->colour = BLACK;
                RR(p);
            } else {
                t->left->colour = BLACK;
                RL(p);
            }
            p = t;
            c->colour = RED;
        }
    } else {
        if (c->data.key == del) {
            if (c->left && c->right) {
                if (c->right->colour == BLACK) {
                    LL(c);
                    c = c->right;
                }
                return;
            }
            if (c->left) {
                LL(c);
                p = c;
                c = c->right;
            } else {
                RR(c);
                p = c;
                c = c->left;
            }
        } else {
            p = c;
            c = (c->data.key < del) ? c->right : c->left;
            t = (c == p->left) ? p->right : p->left;
            if (c->colour == BLACK) {
                if (t == p->right)
                    RR(p);
                else
                    LL(p);
                p = t;
                t = (c == p->left) ? p->right : p->left;
                removeAdjust(p, c, t, del);
            }
        }
    }
}

#endif /* _REDBLACKTREE_H */