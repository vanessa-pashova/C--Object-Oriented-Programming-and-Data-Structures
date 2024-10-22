//Да се изгради подходяща йерархия, представяща множеството от фигури в равнината. Възможните фигури са:
// - окръжност, квадрат и правоъгълник.
//Класовете от йерархията да поддържат следните операции:
// - създаване на фигури чрез координати на медицентъра и размери
// - намиране на лице
// - намиране на периметър
// - извеждане на данни за фигурата
#include <iostream>
const double PI = 3.14;

class Point
{
    private:
        double x, y;

        void copyFrom(const Point &other)
        {
            this->x = other.x;
            this->y = other.y;
        }

    public:
        Point(double, double);
        Point();
        Point &operator=(const Point &);

        void readPoint();
        void printPoint();
};

Point::Point(double x, double y) : x(x), y(y) {}
Point::Point() : x(0), y(0) {}

Point &Point::operator=(const Point &other)
{
    if (this != &other)
        this->copyFrom(other);

    return *this;
}

void Point::readPoint()
{
    std::cout << "> insert x: ";
    std::cin >> this->x;
    std::cout << "> insert y: ";
    std::cin >> this->y;
    std::cout << '\n';
}

void Point::printPoint() {
    std::cout << "[ x ] --> " << this->x << "\n[ y ] --> " << this->y << "\n\n";
}

class Figure
{
    private:
        Point coordinates;

        void copyFrom(const Figure &other) {
            this->coordinates = other.coordinates;
        }

    public:
        Figure(Point coordinates);
        Figure();
        Figure &operator=(const Figure &);

        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual void information() const;
};

Figure::Figure(Point coordinates) : coordinates(coordinates) {}
Figure::Figure() : coordinates(0, 0) {}

Figure &Figure::operator=(const Figure &other)
{
    if (this != &other)
        this->copyFrom(other);

    return *this;
}

class Circle : public Figure
{
    private:
        double radius;

    public:
        Circle(Point, double);
        
        double area() const;
        double perimeter() const;
        virtual void print() const;
};

Circle::Circle(Point center, double r) : Figure(center), radius(r) {}

double Circle::area() const {
    return PI * this->radius * this->radius;
}

double Circle::perimeter() const {
    return 2 * PI * this->radius;
}

void Circle::print() const {
    std::cout << "[ raduis ] --> " << this->radius << "\n\n";
    Figure::information();
}

class Square : public Figure
{
    private:
        double side;

    public:
        Square(Point, double);

        double area() const;
        double perimeter() const;
        virtual void print() const;
};

double Square::area() const {
    return this->side * this->side;
}

double Square::perimeter() const {
    return 4 * this->side;
}

void Square::print() const {
    std::cout << "[ side ] --> " << this->side << "\n\n";
}

class Rectangle : public Figure
{
    private:
        double a, b;

    public:
        Rectangle(Point, double, double);

        double area() const;
        double perimeter() const;
        virtual void print() const;
};

Rectangle::Rectangle(Point center, double a, double b) : Figure(center), a(a), b(b) {}

double Rectangle::area() const {
    return this->a * this->b;
}

double Rectangle::perimeter() const {
    return (2 * this->a) + (2 * this->b);
}

void Rectangle::print() const {
    std::cout << "[ sides ] --> " << this->a << ", " << this->b << "\n\n";
}

int main ()
{
    std::cout << '\n';
    std::cout << "--------------------------------\n";

    Figure *arr[3];
    Point pC(2, 3);
    arr[0] = new Circle(pC, 4);
    arr[1] = new Square(pC, 9);
    arr[2] = new Rectangle(pC, 10, 1995);
}