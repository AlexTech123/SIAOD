#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool testStr(string s) {
    regex regexPattern("^(int|float|double|char|bool)\\s+(\\w+)\\s*((\\[\\d+\\])+)?\\s*(=\\s*((\\{.*\\})|([a-zA-Z0-9])+)\\s*;)$");
    return regex_match(s, regexPattern);
}

int main() {
    string input;
    cout << "Enter line: ";
    getline(std::cin, input);

    cout << (testStr(input) ? "The string matches the regular expression." : "The string does not matches the regular expression.");

    return 0;
}
