#include <iostream>

int main(){
    // std::string arr[] = {"apple", "banana", "grape", "guava", "mango"};
    // std::cout << "[" ;
    // for (int i = 0; i < 4; i++) {
    //     std::cout << arr[i] << ", ";
    // }
    // std::cout << arr[4] <<"]";
    char str1[] = "Hello, World!";

    std::cout << str1 << std::endl <<std::size(str1) << std::endl;
    for (int i=0; i < std::size(str1); i++) {
        std::cout << str1[i] << std::endl;
    }
   
    return 0;
}