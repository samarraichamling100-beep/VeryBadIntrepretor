#include <iostream>
#include <string>
int main (){
    int Integer = 100;
    if(std::isdigit(Integer)){
        std::cout << "It is True" << std::endl;
        std::cout << "It is True" << std::endl;
        bool state = std::isdigit(Integer);
        std::cout << state << std::endl;
    }

}