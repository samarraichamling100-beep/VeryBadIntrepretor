#include <iostream>
#include <string>
#include <vector>
#include <cctype>

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
    int WordProcessed = 0;
    std::vector<std::string> wordlist;
    std::vector<Token> SourceCode;
    bool Completed = false;

    std::string word;
    std::string Source = "100 + 200";
    
    for(int x = 0;x <= Source.length();x++){
        if (std::isspace(Source[x])){
            wordlist.push_back(word);
            word = "";
        }

        else if (x == Source.length()){
            wordlist.push_back(word);
            word = "";
        }
        else{
            word += Source[x];
        }
    }
    for (std::string word :wordlist){
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
        else if (static_cast<int>(std::stoi(word)) ){
            Token element;
            element.tokentype = TokenTypes::num;
            element.IntValue = std::stoi(word);
            element.StrValue = "";
            SourceCode.push_back(element);
        }
        
    }
    if (SourceCode.size() > 0) {
        for (int ListIndex = 0;ListIndex < SourceCode.size();ListIndex ++){
            if ((SourceCode[ListIndex].StrValue) == "+"){
                int expressionHolder = ListIndex;
                int FirstNum = ListIndex - 1;
                int SecondNum = ListIndex + 1;
                std::cout << SourceCode[FirstNum].IntValue + SourceCode[SecondNum].IntValue << std::endl;
            }
        }
    }
    return 0;
}