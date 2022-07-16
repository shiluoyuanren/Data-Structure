#include <iostream>
#include "LinkString.h"

// namespace sp {
// class test {
//     int a;
//     friend void put(const test& t);

//    public:
//     test(int x = 10) : a(x) {}
// };

// void put(const test& t);

// }  // namespace sp

// void sp::put(const sp::test& t) {
//     std::cout << t.a << std::endl;
// }

int main() {
    Ur::LinkString s1("hello world");
    std::cout << "s1 " << s1.length() << std::endl;
    // std::cout << s1 << std::endl;
    Ur::LinkString s2 = s1;
    // std::cout << s2.length() << std::endl;
    // std::cout << s2 << std::endl;
    Ur::LinkString s3("1234 綦杰");
    std::cout << "s3 " << s3.length() << std::endl;
    Ur::LinkString s4(s2);
    // s4 = s1.subStr(1, 19);
    std::cout << "s4 " << s4.length() << std::endl;
    Ur::LinkString s5("綦杰");
    s1.insert(10, s5);
    // std::cout << s1 << std::endl;
    s2.remove(6, 9);
    // std::cout << s2 << std::endl;
    // bool atm = (s3 != s4);
    s5 = s3 + s4;
    std::cout << "s5 " << s5 << std::endl;
    system("pause");
    return 0;
}