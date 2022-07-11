#include <iostream>
<<<<<<< HEAD
#include "DoublelinkList.h"
using namespace std;

int main() {
    system("title DoublelinkList");
    DoublelinkList<int>* dkl = new DoublelinkList<int>;
    dkl->insert(0, 1);
    dkl->insert(0, 2);
    dkl->insert(10, 3);
    dkl->insert(-1, 4);
    dkl->insert(4, 5);
    dkl->travel();
    cout << dkl->is_empty() << endl;
    dkl->remove(12);
    dkl->travel();
    cout << dkl->search(-9) << endl;
    cout << dkl->size() << endl;
    cout << dkl->visit(0) << endl;
    dkl->clear();
    cout << dkl->is_empty() << endl;
    system("pause");
    return 0;
=======
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
>>>>>>> SinglelinkList
}