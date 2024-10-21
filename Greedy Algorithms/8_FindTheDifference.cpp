#include <iostream>

char findTheDiff(char *s, char *t, std::size_t size) {
    char result = 0;
    std::size_t sSize = size + 1, tSize = size + 2;

    for(std::size_t i = 0; i < sSize; ++i)
        result ^= s[i];

    for(std::size_t i = 0; i < tSize; ++i)
        result ^= t[i];

    return result;
}

int main() {
    std::size_t size = 0;
    std::cout << "Insert the lenght of the string: ";
    std::cin >> size;

    try {
        char *s = new char[size + 1],
        *t = new char[size + 2];

        std::cout << "Insert s-string: ";
        std::cin >> s;

        std::cout << "Insert t-string: ";
        std::cin >> t;

        if(strlen(t) != strlen(s) + 1) {
            std::cerr << "t-string must be with exactly one char more longer\n";
            delete [] s;
            delete [] t;
            return 1;
        }

        char additionalChar = findTheDiff(s, t, size);
        std::cout << "The different char in t-string is: " << additionalChar << '\n';

        delete [] s;
        delete [] t;
    }

    catch(const std::bad_alloc&) {
        std::cerr << "Memory allocation problem\n";
        return 1;
    }

    return 0;
}