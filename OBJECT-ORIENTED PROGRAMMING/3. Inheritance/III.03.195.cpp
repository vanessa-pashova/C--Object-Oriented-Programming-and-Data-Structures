//Да се дефинира йерархията, определяща: триъгълник, правоъгълен триъгълник и равнобедрен триъгълник. Триъгълник се задава чрез страните му. Основният клас
//Триъгълник да има методи за:
// - инициализация на страните
// - намиране на периметър и лице
// - извеждане на данни
//Производните класове да предефинират методите за инициализиране и намиране на лице
#include <iostream>
#include <cmath>
class Triangle
{
    private:
        int a, b, c;

    public:
        int getA() const;
        int getB() const;
        int getC() const;

        void insert(int, int, int);
        void Perimeter() const;
        void Area() const;
        void print() const;
};

void Triangle::insert(int a, int b, int c)
{
    if ((a > 0 && b > 0 && c > 0) && (a + b > c && b + c > a && a + c > b))
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
}

int Triangle::getA() const {
    return this->a;
}

int Triangle::getB() const {
    return this->b;
}

int Triangle::getC() const {
    return this->c;
}

void Triangle::Perimeter() const 
{
    float perimeter = this->a + this->b + this->c;
    std::cout << "[ perimeter ] -> " << perimeter << "\n\n";
}

void Triangle::Area() const 
{
    float p = (this->a + this->b + this->c) / 2;
    float area = sqrt(p * (p - this->a) * (p - this->b) * (p - this->c));
    std::cout << "[ area ] -> " << area << "\n\n";
}

void Triangle::print() const {
    std::cout << "[ sides of your triangle ] -> " << this->a << ", " << this->b << ", " << this->c << "\n\n";
}

class RightTriangle : public Triangle
{
    public:
        void insert(int, int, int);
        void area() const;
};

void RightTriangle::insert(int a, int b, int c)
{
    Triangle::insert(a, b, c);

    if ((a > 0 && b > 0 && c > 0) && (pow(a, 2) + pow(b, 2) == pow(c, 2) && pow(b, 2) + pow(c, 2) == pow(a, 2) && pow(a, 2) + pow(c, 2) == pow(b, 2)))
        std::cout << "[ your triangle is righttriangle ]\n";

    else
        std::cout << "[ your triangle is not righttriangle ]\n";
}

void RightTriangle::area() const
{
    int a = Triangle::getA();
    int b = Triangle::getB();

    double area = (1.0/2) * a * b;
    std::cout << "[ area of right triangle ] -> " << area << "\n\n"; 
}

class IsoscelesTriangle : public Triangle
{
    public:
        void insert(int, int, int);
        void area() const;
};

void IsoscelesTriangle::insert(int a, int b, int c) {
    Triangle::insert(a, b, c);
}

void IsoscelesTriangle::area() const
{
    int a = Triangle::getA();
    int b = Triangle::getB();
    int c = Triangle::getC();

    double p = (a + b + c) / 2;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    std::cout << "[ area of isosceles triangle ] -> " << area << "\n\n"; 
}

int main() 
{
    std::cout << '\n';
    std::cout << "-------------------------\n";

    Triangle t;
    t.insert(2, 3, 4);
    t.print();
    t.Area();

    RightTriangle t2;
    t2.insert(3, 4, 5);
    t2.print();
    t2.area();
}
//✅