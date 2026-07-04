#include <iostream>
#include <string>
#include <vector>
enum class TokenTypes {
    plus,
    minus,
    star,
    let,
    name,
};


struct Token {
    TokenTypes tokentype;
    std::string Value;
};
int main() {
    std::string Source = "12 + 20";
    std::vector<Token> tokens;
    for (const &auto :tokens) {
        
    }
    return 0;
}