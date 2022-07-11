#include <iostream>
#include "SinglelinkList.h"
using namespace std;

int main() {
    SinglelinkList<int>* skl = new SinglelinkList<int>;
    skl->insert(0, 1);
    skl->insert(0, 2);
    skl->insert(0, 3);
    skl->insert(0, 4);
    skl->insert(0, 5);
    skl->travel();
    cout << skl->is_empty() << endl;
    skl->remove(4);
    skl->travel();
    cout << skl->search(5) << endl;
    cout << skl->size() << endl;
    cout << skl->visit(2) << endl;
    skl->clear();
    cout << skl->size() << endl;
    cout << skl->is_empty() << endl;
    system("pause");
}