#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stdexcept> // Added for std::stoi safety

std::string SRC(){
    std::string line;
    std::getline(std::cin,line);
    std::cout << "WE HAVE GOTTEN THE LINE" << std::endl;
    return line;
}

enum class TokenTypes {
    plus,
    minus,
    star,
    divide,
    let,
    num,
    name,
};

struct Token {
    TokenTypes tokentype;
    std::string StrValue;
    int IntValue;
};

int main() {
    std:: cout << "Enter An Operation to Interprete: ";
    std::string Source = SRC();
    int WordProcessed = 0;
    std::vector<std::string> wordlist;
    std::vector<Token> SourceCode;
    bool Completed = false;

    std::string word;

    for(int x = 0; x < Source.length(); x++){
        if (std::isspace(static_cast<unsigned char>(Source[x]))){
            if (!word.empty()) { // Only push if word isn't empty
                std::cout << "words is pushed" << std::endl;
                wordlist.push_back(word);
                word = "";
            }
        }
        else{
            word += Source[x];
        }
    }
    if (!word.empty()) {
        wordlist.push_back(word);
        std::cout << word << std::endl;
        word = "";
    }

    for (std::string word : wordlist){
        if (word == "+"){
            Token element;
            element.tokentype = TokenTypes::plus;
            element.StrValue = "+";
            SourceCode.push_back(element);
        }
        else if (word == "-"){
            Token element;
            element.tokentype = TokenTypes::minus;
            element.StrValue = "-";
            SourceCode.push_back(element);
        }
        else if (word == "*"){
            Token element;
            element.tokentype = TokenTypes::star;
            element.StrValue = "*";
            SourceCode.push_back(element);
        }
        else if (word == "/"){
            Token element;
            element.tokentype = TokenTypes::divide;
            element.StrValue = "/";
            SourceCode.push_back(element);
        }
        else {
            try {
                int parsedNum = std::stoi(word);
                Token element;
                element.tokentype = TokenTypes::num;
                element.StrValue = word;
                element.IntValue = parsedNum; 
                SourceCode.push_back(element);
            }
            catch (...) {
                Token element;
                element.tokentype = TokenTypes::name;
                element.StrValue = word;
                SourceCode.push_back(element);
            }
        }
    } 

    std::cout << "Inilzed Lexer"<< std::endl;

    if (SourceCode.size() > 0) {
        for (int ListIndex = 1; ListIndex < static_cast<int>(SourceCode.size()) - 1; ListIndex ++){
            if ((SourceCode[ListIndex].StrValue) == "+"){
                int expressionHolder = ListIndex;
                int FirstNum = ListIndex - 1;
                int SecondNum = ListIndex + 1;
                std::cout << SourceCode[FirstNum].IntValue + SourceCode[SecondNum].IntValue << std::endl;
            }
            else if ((SourceCode[ListIndex].StrValue) == "*"){
                int expressionHolder = ListIndex;
                int FirstNum = ListIndex - 1;
                int SecondNum = ListIndex + 1;
                std::cout << SourceCode[FirstNum].IntValue * SourceCode[SecondNum].IntValue << std::endl;
            }
            else if ((SourceCode[ListIndex].StrValue) == "-"){
                int expressionHolder = ListIndex;
                int FirstNum = ListIndex - 1;
                int SecondNum = ListIndex + 1;
                std::cout << SourceCode[FirstNum].IntValue - SourceCode[SecondNum].IntValue << std::endl;
            }
            else if ((SourceCode[ListIndex].StrValue) == "/"){
                int expressionHolder = ListIndex;
                int FirstNum = ListIndex - 1;
                int SecondNum = ListIndex + 1;
                if (SourceCode[SecondNum].IntValue != 0) {
                    std::cout << SourceCode[FirstNum].IntValue / SourceCode[SecondNum].IntValue << std::endl;
                } else {
                    std::cout << "Error: Division by zero" << std::endl;
                }
            }
        }
    }
    return 0;
}
