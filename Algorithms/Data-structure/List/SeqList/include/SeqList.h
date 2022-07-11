#ifndef _SEQLIST_H
#define _SEQLIST_H

#include <iostream>
#define LE 10
using namespace std;

template <typename Temp>  //线性表的抽象类
class List {
   public:
    virtual void add(const Temp& value) = 0;                //头插法
    virtual void append(const Temp& value) = 0;             //尾插法
    virtual void insert(int index, const Temp& value) = 0;  //指定位置插入
    virtual void remove(int index) = 0;                     //删除
    virtual int search(const Temp& value) const = 0;        //查找元素
    virtual bool is_empty() const = 0;                      //判空
    virtual int size() const = 0;                           //求表长
    virtual void travel() const = 0;                        //遍历
    virtual void clear() = 0;                               //清除所有元素
    virtual Temp visit(int index) const = 0;  //访问第index个元素的值
    virtual ~List(){};                        //虚析构函数
};

template <typename Temp>
class SeqList : public List<Temp> {
   private:
    int max_size;
    int now_size;
    Temp* data;
    void double_size();

   public:
    SeqList(int size = LE);
    ~SeqList();
    void add(const Temp& value);
    void append(const Temp& value);
    void insert(int index, const Temp& value);
    void remove(int index);
    int search(const Temp& value) const;
    bool is_empty() const;
    int size() const;
    void travel() const;
    void clear();
    Temp visit(int index) const;
};

template <typename Temp>
SeqList<Temp>::SeqList(int size) {
    data = new Temp[size];
    max_size = size;
    now_size = 0;
}

template <typename Temp>
SeqList<Temp>::~SeqList() {
    delete[] data;
    cout << "hello" << endl;
}

template <typename Temp>
void SeqList<Temp>::add(const Temp& value) {
    if (max_size == now_size)
        double_size();
    int i;
    for (i = now_size - 1; i > 0; --i)
        data[i] = data[i - 1];
    data[0] = value;
    now_size++;
}

template <typename Temp>
void SeqList<Temp>::append(const Temp& value) {
    if (max_size == now_size)
        double_size();
    data[now_size] = value;
    now_size++;
}

template <typename Temp>
void SeqList<Temp>::insert(int index, const Temp& value) {
    if (max_size == now_size)
        double_size();
    int i;
    for (i = now_size; i > index; --i)
        data[i] = data[i - 1];
    data[i] = value;
    now_size++;
}

template <typename Temp>
void SeqList<Temp>::remove(int index) {
    int i;
    for (i = index; i < now_size; i++)
        data[i] = data[i + 1];
    now_size--;
}

template <typename Temp>
int SeqList<Temp>::search(const Temp& value) const {
    int i;
    for (i = 0; i < now_size; i++)
        if (data[i] == value)
            return true;
    return false;
}

template <typename Temp>
bool SeqList<Temp>::is_empty() const {
    return now_size == 0;
}

template <typename Temp>
int SeqList<Temp>::size() const {
    return now_size;
}

template <typename Temp>
void SeqList<Temp>::travel() const {
    int i;
    for (i = 0; i < now_size; i++)
        cout << data[i] << " ";
    cout << endl;
}

template <typename Temp>
void SeqList<Temp>::clear() {
    now_size = 0;
}

template <typename Temp>
Temp SeqList<Temp>::visit(int index) const {
    return data[index];
}

template <typename Temp>
void SeqList<Temp>::double_size() {
    Temp* tpl = data;
    max_size *= 2;
    data = new Temp[max_size];
    for (int i = 0; i < now_size; i++)
        data[i] = tpl[i];
    delete[] tpl;
}

#endif