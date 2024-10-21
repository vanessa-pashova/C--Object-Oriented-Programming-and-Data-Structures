#include <iostream>

template <typename T>
struct Point {
    T x, y;

    Point(T x, T y) : x(x), y(y) {};
    Point() : x(0), y(0) {}
};

template <typename T>
int partition(T* arr, int low, int high) {
    T pivot = arr[high];
    int pp = low;

    for (int i = low; i < high; ++i) {
        if (arr[i] <= pivot) {
            std::swap(arr[i], arr[pp]);
            pp++;
        }
    }

    std::swap(arr[pp], arr[high]);
    return pp;
}

template <typename T>
void quickSort(T* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template <typename T>
bool operator<=(const Point<T>& a, const Point<T>& b) {
    return a.x <= b.x;
}

int main() {
    std::size_t n = 0;
    std::cout << "Insert the count of the points: ";
    std::cin >> n;

    try {
        Point<int>* points = new Point<int>[n];

        std::cout << "Insert the values of the points:\n";
        for (std::size_t i = 0; i < n; ++i)
            std::cin >> points[i].x >> points[i].y;

        quickSort(points, 0, n - 1);

        int maxWidth = 0;
        for (std::size_t i = 1; i < n; ++i) {
            int current = abs(points[i].x - points[i - 1].x);

            if (maxWidth < current)
                maxWidth = current;
        }

        std::cout << "MaxWidth: " << maxWidth << '\n';
        delete[] points;
    }

    catch (const std::bad_alloc&) {
        std::cout << "Memory allocation problem\n";
        return 1;
    }

    catch (...) {
        std::cout << "Some kind of error\n";
        return 1;
    }

    return 0;
}
