#include <iostream>
#include <fstream>
#include <queue>
#include "EntranceManager.h"

int main() {
    try {
        EntranceManager manager("input.txt");
        manager.execution();
        manager.printOutcome();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}