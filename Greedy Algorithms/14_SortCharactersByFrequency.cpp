#include <iostream>
#include <string>
#include <cassert>

struct CharFrequency {
    char character;
    int frequency;
};

int partition(CharFrequency* arr, int low, int high) {
    CharFrequency pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j].frequency > pivot.frequency) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(CharFrequency* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void calculateFrequencies(const std::string &s, CharFrequency *&charFreq, std::size_t &uniqueCharsCount) {
    int frequencies[256] = {0};  // Брояч за символите (256 символа за ASCII)

    for (char c : s)
        frequencies[(int)c]++;

    uniqueCharsCount = 0;
    for (int i = 0; i < 256; ++i) {
        if (frequencies[i] > 0)
            uniqueCharsCount++;
    }

    try {
        charFreq = new CharFrequency[uniqueCharsCount];
    } catch (const std::bad_alloc&) {
        std::cerr << "Memory allocation problem\n";
        throw;
    }

    std::size_t index = 0;
    for (int i = 0; i < 256; ++i) {
        if (frequencies[i] > 0) {
            charFreq[index].character = (char)i;
            charFreq[index].frequency = frequencies[i];
            index++;
        }
    }
}

std::string generateSortedString(CharFrequency* charFreq, std::size_t uniqueCharsCount) {
    std::string result;
    for (std::size_t i = 0; i < uniqueCharsCount; ++i)
        result.append(charFreq[i].frequency, charFreq[i].character);

    return result;
}

int main() {
    std::string s;
    std::cout << "Insert a string: ";
    std::getline(std::cin, s);

    assert(!s.empty() && "String should not be empty");

    CharFrequency* charFreq = nullptr;
    std::size_t uniqueCharsCount = 0;

    try {
        calculateFrequencies(s, charFreq, uniqueCharsCount);
    } catch (...) {
        return 1;
    }

    quickSort(charFreq, 0, uniqueCharsCount - 1);

    std::string result = generateSortedString(charFreq, uniqueCharsCount);

    std::cout << "Sorted string by frequency: " << result << '\n';

    delete[] charFreq;
    return 0;
}
