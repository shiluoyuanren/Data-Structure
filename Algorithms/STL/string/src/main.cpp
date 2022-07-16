#include <iostream>
#include <string>

int main() {
    std::string s1("hello world");
    std::string s2 = ",I am Iron Man!";
    std::string s3;
    s3 = s1 + s2;
    std::cout << s3 << std::endl;
    std::cout << s3.find(s2) << std::endl;
    system("pause");
    return 0;
}