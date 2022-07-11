#include <iostream>
#include "SeqList.h"
using namespace std;

int main() {
    // SeqList<int> sql(5);
    // sql.add(10);
    // sql.append(23);
    // sql.insert(0, 9);
    // sql.travel();
    // cout << sql.is_empty() << endl;
    // sql.remove(1);
    // sql.travel();
    // cout << sql.search(9) << endl;
    // cout << sql.size() << endl;
    // cout << sql.visit(1) << endl;
    // sql.clear();
    // sql.travel();
    // cout << sql.size() << endl;
    // system("pause");
    // return 0;
    SeqList<int>* sql = new SeqList<int>(5);
    sql->add(10);
    sql->append(23);
    sql->insert(0, 9);
    sql->travel();
    cout << sql->is_empty() << endl;
    sql->remove(1);
    sql->travel();
    cout << sql->search(9) << endl;
    cout << sql->size() << endl;
    cout << sql->visit(1) << endl;
    cout << sql->size() << endl;
    delete sql;
    system("pause");
    return 0;
}