#include "Affine.hpp"
#include <iostream>

int main()
{
    Affine a1;
    a1.set_text_source("Hello, my name is John. I am seventeen and I love playing the guitar");
    a1.encrypt("3,4");
    a1.text_modified_out(std::cout);
    std::cout << std::endl;

    a1.set_text_source(a1.get_text_modified());
    a1.decrypt("3,4");
    a1.text_modified_out(std::cout);
    std::cout << std::endl;

    a1.set_text_source("Hello, my name is John. I am seventeen and I love playing the guitar");
    a1.encrypt("27,3");
    a1.set_text_source(a1.get_text_modified());
    a1.crack();
    a1.text_modified_out(std::cout);
    std::cout << std::endl;

    Affine a2;
    std::cout << "Print your text:\n";
    a2.text_source_in(std::cin);
    std::cout << "\nYour text_source\n: " << a2.get_text_source() << std::endl;
    std::cout << "Print your key in format \"a,b\": ";
    std::string key;
    std::cin >> key;
    a2.encrypt(key);
    std::cout << "\nYour encrypt_text\n: " << a2.get_text_modified() << std::endl;
    a2.crack();
    std::cout << "\nYour crack_text\n:" << a2.get_text_modified() << std::endl;

    getchar();
    return 0;
}