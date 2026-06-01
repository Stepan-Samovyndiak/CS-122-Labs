#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

int strcmp_case_insensitive(const string& str1, const string& str2) {
    size_t i = 0;
    
    while (i < str1.length() && i < str2.length()) {
        char c1 = tolower(static_cast<unsigned char>(str1[i]));
        char c2 = tolower(static_cast<unsigned char>(str2[i]));
        
        if (c1 != c2) {
            return (c1 < c2) ? -1 : 1;
        }
        i++;
    }
    
    if (str1.length() < str2.length()) return -1;
    if (str1.length() > str2.length()) return 1;
    
    return 0;
}

int main() {
    cout << "The comparison of \"String one\" and \"string two\" returns " << strcmp_case_insensitive("String one", "string two") << ".\n";
    cout << "The comparison of \"String one\" and \"string one\" returns " << strcmp_case_insensitive("String one", "string one") << ".\n";
    cout << "The comparison of \"String two\" and \"string one\" returns " << strcmp_case_insensitive("String two", "string one") << ".\n";
    
    cout << "Running case-insensitive string comparison tests...\n";

    assert(strcmp_case_insensitive("hello", "hello") == 0);
    assert(strcmp_case_insensitive("String one", "string one") == 0);
    assert(strcmp_case_insensitive("ABC", "abc") == 0);
    assert(strcmp_case_insensitive("String one", "string two") == -1);
    assert(strcmp_case_insensitive("apple", "Banana") == -1); 
    assert(strcmp_case_insensitive("string two", "String one") == 1);
    assert(strcmp_case_insensitive("cherry", "Banana") == 1); 
    assert(strcmp_case_insensitive("cat", "cats") == -1);
    assert(strcmp_case_insensitive("cats", "cat") == 1);

    cout << "All tests passed successfully! Exiting gracefully.\n";
    return 0;
}