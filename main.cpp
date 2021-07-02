#include <iostream>

bool emailFirstPartDictionaryValidation (char c) {
    std::string dictionaryOfSymbols = "!#$%&'*+-/=?^_`{|}~";
    if (c > 'A' && c < 'Z') return true;
    else if (c > 'a' && c < 'z') return true;
    else if (c == '-' || c == '.') return true;
    else {
        for (int i = 0; i < dictionaryOfSymbols.length(); ++i) {
            if (c == dictionaryOfSymbols[i]) return true;
        }
    }
    return false;
}
bool emailSecondPartDictionaryValidation (char c) {
    if (c > 'A' && c < 'Z') return true;
    else if (c > 'a' && c < 'z') return true;
    else if (c == '-' || c == '.') return true;
    return false;
}

bool emailValidation (std::string email) {
    std::string firstPart, secondPart;
    bool correct = true;

    //check symbol "."
    if (email[0] == '.' || email[email.length() - 1] == '.') return false;

    //check symbol "@"
    if (email.find('@') == std::string::npos) return false;
    else if (email.find('@') != email.rfind('@')) return false;

    firstPart = email.substr(0, email.find('@'));
    secondPart = email.substr(email.find('@') + 1, email.length());

    //First part validation
    for (int i = 0; correct == true && i < firstPart.length(); ++i) {
        if (firstPart.length() < 1 || firstPart.length() > 64) correct = false;
        else if (!emailFirstPartDictionaryValidation(firstPart[i])) correct = false;
        else if (i > 0 && (firstPart[i] == '.' && firstPart[i - 1] == '.')) correct = false;
        else correct = true;
    }
    if (correct == false) return false;

    //Second part validation
    for (int i = 0; correct == true && i < secondPart.length(); ++i) {
        if (secondPart.length() < 1 || secondPart.length() > 63) correct = false;
        else if (!emailSecondPartDictionaryValidation(secondPart[i])) correct = false;
        else if (i > 0 && (secondPart[i] == '.' && secondPart[i - 1] == '.')) correct = false;
        else correct = true;
    }

    return correct;
}

int main() {
    std::string email;

    std::cout << "Input email: " << std::endl;
    std::cin >> email;

    std::cout << "qwe: " << (emailValidation(email) ? "yes" : "no" ) << "\n";\
}
