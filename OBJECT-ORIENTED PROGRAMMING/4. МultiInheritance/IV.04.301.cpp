//Да се дефинират класове, описващи следните видове информация:
// - лични данни (име, година на раждане)
// - данни за клас от ученици (випуск, брой ученици, номер на паралелка)
// - данни за автомобил (марка и модел, регистрационен номер)
//Да се дефинират класове, описващи информацията за:
// - класен ръководител
// - собственик на автомобил
//Класовете да позволяват въвеждане на съответните данни от клавиатурата и извеждането им на екрана

#include <iostream>

class DateOfBirth
{
    private:
        //friend class PersonalIndormnation;
        int day, month, year;

        void copyFrom(const DateOfBirth &other)
        {
            this->day = other.day;
            this->month = other.month;
            this->year = other.year;
        }
        
    public:
        DateOfBirth(int = 1, int = 1, int = 1950);
        DateOfBirth &operator=(const DateOfBirth &);

        void readDateOfBirth();
        void printDateOfBirth();
};

DateOfBirth::DateOfBirth(int d, int m, int y) 
{
    if (0 < d && d < 32)
        this->day = d;

    else this->day = 1;

    if (0 < m && m < 13)
        this->month = m;

    else this->month = 1;

    if (1949 < y && y < 2023)
        this->year = y;

    else this->year = 1950;
}

DateOfBirth &DateOfBirth::operator=(const DateOfBirth &other)
{
    if (this != &other)
        this->copyFrom(other);

    return *this;
}

void DateOfBirth::readDateOfBirth() 
{
    std::cout << "> insert day: ";
    std::cin >> this->day;
    std::cout << "> insert month: ";
    std::cin >> this->month;
    std::cout << "> insert year: ";
    std::cin >> this->year;

    std::cout << "\n\n";
}

void DateOfBirth::printDateOfBirth() 
{
    std::cout << "[ birth ] --> ";

    if (0 < this->day && this->day < 10)
        std::cout << '0' << this->day << '/';

    else std::cout << this->day << '/';

    if (0 < this->month && this->month < 10)
        std::cout << '0' << this->month << '/';    

    else std::cout << this->month << '/';

    std::cout << this->year << '\n';
}

class PersonalInformation
{
    private:
        char *name;
        DateOfBirth birth;

        void copyFrom(const PersonalInformation &other)
        {   
            std::size_t len = strlen(other.name) + 1;
            this->name = new char[len];

            if (!this->name)
            {
                std::cout << "[ memory allocation problem ]\n";
                exit(1);
            }

            strcpy(this->name, other.name);
            this->birth = other.birth;
        }

        void deallocate() {
            delete [] this->name;
        }

    public:
        PersonalInformation(const char*, DateOfBirth);
        PersonalInformation();
        PersonalInformation &operator=(const PersonalInformation &);
        ~PersonalInformation();

        void readPersonlInformation();
        void printPersonlInformation();
};

PersonalInformation::PersonalInformation(const char *n, DateOfBirth birth) : birth(birth) 
{
    std::size_t len = strlen(n) + 1;
    this->name = new char[len];

    if (!this->name)
    {
        std::cout << "[ memory allocation problem ]\n";
        exit(1);
    }

    strcpy(this->name, n);
}

PersonalInformation::PersonalInformation() : birth(DateOfBirth(1, 1, 1950)) 
{
    this->name = new char[1];
    this->name[0] = '\0';
}

PersonalInformation &PersonalInformation::operator=(const PersonalInformation &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copyFrom(other);
    }

    return *this;
}

PersonalInformation::~PersonalInformation() {
    this->deallocate();
}

void PersonalInformation::readPersonlInformation() 
{
    std::cout << "> insert your name: ";
    std::cin >> this->name;
    std::cout << '\n';

    std::cout << "[ insert the needed data ]\n";
    this->birth.readDateOfBirth();
}

void PersonalInformation::printPersonlInformation()
{
    std::cout << "[ name ] --> " << this->name << '\n';
    this->birth.printDateOfBirth();
}

class ClassOfStudents
{
    private:
        int count, year, grade;

        void copyFrom(const ClassOfStudents &other)
        {
            this->count = other.count;
            this->year = other.year;
            this->grade = other.grade;
        }

    public:
        ClassOfStudents(int, int, int);
        ClassOfStudents();
        ClassOfStudents &operator=(const ClassOfStudents &);

        void readClassOfStudents();
        void printClassOfStudents();
};

ClassOfStudents::ClassOfStudents(int c, int y, int g) 
{
    if (19 < c && c < 29) 
        this->count = c;
        
    else this->count = 25;

    if (1959 < y && y < 2024)
        this->year = y;

    else this->year = 2023;

    if (0 < g && g < 13)
        this->grade = g;

    else this->grade = 12;
}

ClassOfStudents::ClassOfStudents() : count(25), year(2023), grade(12) {}

ClassOfStudents &ClassOfStudents::operator=(const ClassOfStudents &other)
{
    if (this != &other)
        this->copyFrom(other);

    return *this;
}

void ClassOfStudents::readClassOfStudents()
{
    std::cout << "> how many students in class: ";
    std::cin >> this->count;
    std::cout << "> what's the year: ";
    std::cin >> this->year;
    std::cout << "> what's the grade: ";
    std::cin >> this->grade;
    std::cout << '\n';
}

void ClassOfStudents::printClassOfStudents() {
    std::cout << "[ count of studs ] --> " << this->count << "\n[ year ] --> " << this->year << "\n[ grade ] --> " << this->grade << "\n\n";
}

class Teacher : public PersonalInformation, public ClassOfStudents
{
    public:
        void readTeacher();
        void printTeacher();
};

void Teacher::readTeacher() {
    PersonalInformation::readPersonlInformation();
    ClassOfStudents::readClassOfStudents();
}

void Teacher::printTeacher() {
    PersonalInformation::printPersonlInformation();
    ClassOfStudents::printClassOfStudents();
}

class Car
{
    private:
        char *brand, *model, *number;

        void copyFrom(const Car &other)
        {
            std::size_t lenB = strlen(other.brand) + 1, lenM = strlen(other.model) + 1, lenN = strlen(other.number) + 1;
            this->brand = new char[lenB];
            this->model = new char[lenM];
            this->number = new char[lenN];

            if (!this->brand || !this->model || !this->number)
            {
                std::cout << "[ memory allocation problem]\n";
                exit(1);
            }

            strcpy(this->brand, other.brand);
            strcpy(this->model, other.model);
            strcpy(this->number, other.number);
        }

        void deallocate() 
        {
            delete [] this->brand;
            delete [] this->model;
            delete [] this->number;
        }

    public:
        Car(const char*, const char*, const char*);
        Car();
        Car &operator=(const Car &);
        ~Car();

        void readCar();
        void printCar();
};

Car::Car(const char* b, const char* m, const char* n)
{
    std::size_t lenB = strlen(b) + 1, lenM = strlen(m) + 1, lenN = strlen(n) + 1;
    this->brand = new char[lenB];
    this->model = new char[lenM];
    this->number = new char[lenN];

    if (!this->brand || !this->model || !this->number)
    {
        std::cout << "[ memory allocation problem]\n";
        exit(1);
    }

    strcpy(this->brand, b);
    strcpy(this->model, m);
    strcpy(this->number, n);
}

Car::Car()
{
    this->brand = new char[1];
    this->model = new char[1];
    this->number = new char[1];

    strcpy(this->brand, "");
    strcpy(this->model, "");
    strcpy(this->number, "");
}

Car &Car::operator=(const Car &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copyFrom(other);
    }

    return *this;
}

Car::~Car() {
    this->deallocate();
}

void Car::readCar() 
{
    std::cout << "> brand of the car: ";
    std::cin >> this->brand;
    std::cout << "> model: ";
    std::cin >> this->model;
    std::cout << "> number: ";
    std::cin >> this->number;
    std::cout <<'\n';
}

void Car::printCar() {
    std::cout << "[ brand of the car ] --> " << this->brand << "\n[ model ] --> " << this->model << "\n[ number ] --> " << this->number << "\n\n"; 
}

class CarOwner : public PersonalInformation, public Car
{
    public:
        void readOwner();
        void printOwner();
};

void CarOwner::readOwner()
{
    PersonalInformation::readPersonlInformation();
    Car::readCar();
}

void CarOwner::printOwner()
{
    PersonalInformation::printPersonlInformation();
    Car::readCar();
}

int main()
{
    std::cout << '\n';
    std::cout << "-------------------------------------\n";

    // DateOfBirth dob(1, 1, 2003); // Създаване на обект от тип DateOfBirth
    // PersonalInformation b("Vanesa", dob); // Подаване на обекта dob на конструктора на PersonalInformation
    // b.printPersonlInformation();

    // PersonalInformation d;
    // d.readPersonlInformation();
    // d.printPersonlInformation();

    Teacher t;
    t.readTeacher();
    t.printTeacher();

    CarOwner c;
    c.readOwner();
    c.printOwner();
}
//✅

