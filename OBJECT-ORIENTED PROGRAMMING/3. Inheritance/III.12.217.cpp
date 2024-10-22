//Да се напише програма, която позволява да се извършват следните поерации с четириъгълници, разположени в равнината
// - намиране на периметър
// - намиране на лицето
// - мащабиране
// - транслация
//Освен горните операции, програмата да намира и диагонала на четириъгълник (ако е квадрат или правоъгълник)
#include <iostream>
#include <cmath>

class Point
{
    private:
        int x, y;

        void copyFrom(const Point &other)
        {
            this->x = other.x;
            this->y = other.y;
        }

    public:
        Point();
        Point(int, int);
        Point &operator=(const Point &);

        void scale(int);
        void translate(int, int);
        int distance(const Point &other) const;
        void print() const;
};

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y) : x(x), y(y) {}

Point &Point::operator=(const Point &other) {
    this->copyFrom(other);

    return *this;
}

void Point::scale(int k) 
{
    this->x *= k;
    this->y *= k;
}

void Point::translate(int h, int v)
{
    this->x += h;
    this->y += v;
}

int Point::distance(const Point &other) const 
{
    Point temp;
    temp.x = other.x - this->x;
    temp.y = other.y - this->y;

    return (sqrt(pow(temp.x, 2) + pow(temp.y, 2)));
}

void Point::print() const {
    std::cout << '(' << this->x << ", " << this->y << ')' << "\n\n";
}

class Shape
{
    private:
        double triangleArea(Point, Point, Point) const;

    protected:
        Point a, b, c, d;

    public:
        Shape(Point, Point, Point, Point);
        void scale(int);
        void translate(int, int);

        int perimeter() const;
        double area() const;
        void print() const;
};

Shape::Shape(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d) {}

void Shape::scale(int k)
{
    a.scale(k);
    b.scale(k);
    c.scale(k);
    d.scale(k);
}

void Shape::translate(int h, int v)
{
    a.translate(h, v);
    b.translate(h, v);
    c.translate(h, v);
    d.translate(h, v);
}

int Shape::perimeter() const {
    return (a.distance(b) + b.distance(c) + c.distance(d) + d.distance(a));
}

double Shape::triangleArea(Point a, Point b, Point c) const {
    int first = a.distance(b);
    int second = b.distance(c);
    int third = c.distance(a);

    double p = (first + second + third) / 2;
    return sqrt(p * (p - first) * (p - second) * (p - third));
}

double Shape::area() const {
    return triangleArea(a, b, c) + triangleArea(a, c, d);
}