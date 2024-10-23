#include <iostream>
#include <cassert>

struct Balloon {
    int x_start;
    int x_end;
};

void swap(Balloon& a, Balloon& b) {
    Balloon temp = a;
    a = b;
    b = temp;
}

int partition(Balloon* points, int low, int high) {
    int pivot = points[high].x_end;
    int pp = low;

    for (int i = low; i < high; ++i) {
        if (points[i].x_end < pivot) {
            swap(points[pp], points[i]);
            ++pp;
        }
    }
    swap(points[pp], points[high]);
    return pp;
}

void quickSort(Balloon* points, int low, int high) {
    if (low < high) {
        int pi = partition(points, low, high);

        quickSort(points, low, pi - 1);
        quickSort(points, pi + 1, high);
    }
}

int findMinArrowShots(Balloon* points, std::size_t n) {
    if (n == 0)
        return 0;

    quickSort(points, 0, n - 1);

    int arrows = 1,
        lastEnd = points[0].x_end;

    for (std::size_t i = 1; i < n; ++i) {
        if (points[i].x_start > lastEnd) {
            arrows++;
            lastEnd = points[i].x_end;
        }
    }

    return arrows;
}

int main() {
    std::size_t n = 0;
    std::cout << "Insert number of balloons: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Invalid number of balloons!" << std::endl;
        return 1;
    }

    Balloon* points = nullptr;
    try {
        points = new Balloon[n];
    } catch (const std::bad_alloc&) {
        std::cerr << "Memory allocation problem\n";
        return 1;
    }

    std::cout << "Insert the intervals [x_start, x_end] for each balloon:\n";
    for (std::size_t i = 0; i < n; ++i) {
        std::cin >> points[i].x_start >> points[i].x_end;

        if (points[i].x_start > points[i].x_end) {
            std::cerr << "Invalid balloon interval: x_start must be <= x_end\n";
            delete[] points;
            return 1;
        }
    }

    int result = findMinArrowShots(points, n);
    std::cout << "Minimum number of arrows required: " << result << std::endl;

    delete[] points;
    return 0;
}
