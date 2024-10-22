//Да се дефинира основен клас Работник, който определя работник с: име и заплащане за един час.
//Да се дефинират два производни на Работник класа: ПочасовРаботник, определящ почасов работник; ЗаплатенРаботник, определящ щатен работник.
//За всеки работник се задават часовете, които той е работил през седмицата и видът на работата, която е работил (символен низ). 
//Работник може да извършва само един вид работа през седмицата
// --- ПочасовРаботник получава заплата по следното правило: всеки час до 40 часа се заплаща по указаната цена; за всеки час от 41 до 60 часа се заплаща 1.5 пъти повече 
//от указаната цена, а за над 60 часа - двойно на указаната цена
// --- ЗаплатенРаботник: получава заплата за указана цена до 40 часа, независимо колко е работил

//Класовете да реализират голяма четворка. Да се сързададат два динамични масива: първият да съдържа информация само за ПочасовРаботник, а вторият - само за ЗаплатенРаботник
//Да се пресметне и изведе заплатата на всеки работник. Да се изведе информацията за всеки работник, сортирана по размер на заплатата

#include <iostream>

class Worker
{
    private:
        char *name;
        double salary;

        void copyFrom(const Worker &other)
        {
            std::size_t nameLen = strlen(other.name);
            this->name = new char[nameLen];

            if (!this->name)
            {
                std::cout << "[ memory errror ]\n";
                exit(1);
            }

            strcpy(this->name, other.name);
            this->salary = other.salary;
        }

        void deallocate() {
            delete [] this->name;
        }

    public:
        Worker(const char* = "", double = 0.0);
        Worker(const Worker &);
        Worker &operator=(const Worker &);
        ~Worker();

        void print() const;
        double getSalary() const;

};

Worker::Worker(const char* n, double s)
{
    std::size_t len = strlen(n) + 1;
    this->name = new char[len];

    if (!this->name)
    {
        std::cout << "[ memory errror ]\n";
        exit(1);
    }

    strcpy(this->name, n);
    this->salary = s;
}

Worker::Worker(const Worker &other)
{
    this->deallocate();
    this->copyFrom(other);
}

Worker &Worker::operator=(const Worker &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copyFrom(other);
    }

    return *this;
}

Worker::~Worker() {
    this->deallocate();
}

void Worker::print() const {
    std::cout << "Worker's name: " << this->name << "\nWorker's salary per hour: " << this->salary << '\n';
}

double Worker::getSalary() const {
    return this->salary;
}

class HourlyWorker : public Worker
{
    private:
        char *work;
        int hours;

        void copyFromHW(const HourlyWorker &other)
        {
            std::size_t lenWork = strlen(other.work) + 1;
            this->work = new char[lenWork];

            if (!this->work)
            {
                std::cout << "[ memory allocation problem ]\n";
                exit(1);
            }
            
            strcpy(this->work, other.work);
            this->hours = other.hours;
        }

        void deallocateHW() {
            delete [] this->work;
        }

    public:
        HourlyWorker(const char* = "", double = 0.0, const char* = "", int = 0);
        HourlyWorker(const HourlyWorker &);  
        HourlyWorker &operator=(const HourlyWorker &);  
        ~HourlyWorker();

        double weeklySalary() const;
        void print() const;
};

HourlyWorker::HourlyWorker(const char* n, double s, const char* w, int h) : Worker(n, s)
{
    this->hours = h;

    std::size_t lenWork = strlen(w) + 1;
    this->work = new char[lenWork];

    if (!this->work)
    {
        std::cout << "[ memory allocation problem ]\n";
        exit(1);
    }

    strcpy(this->work, w);
}

HourlyWorker::HourlyWorker(const HourlyWorker &other) : Worker(other)
{
    this->deallocateHW();
    this->copyFromHW(other);
}

HourlyWorker &HourlyWorker::operator=(const HourlyWorker &other)
{
    if (this != &other)
    {
        Worker::operator=(other);

        this->deallocateHW();
        this->copyFromHW(other);
    }

    return *this;
}

HourlyWorker::~HourlyWorker() {
    this->deallocateHW();
}

double HourlyWorker::weeklySalary() const
{
    double perWeek, perHour = getSalary();
    if (this->hours < 41) 
        perWeek = perHour * this->hours;

    else if (40 < this->hours && this->hours < 61)
        perWeek = (40 * perHour) + ((this->hours - 40) * 1.5);

    else 
         perWeek = (40 * perHour) + (20 * perHour * 1.5) + ((this->hours - 60) * perHour * 2);

    return perWeek;
}

void HourlyWorker::print() const {
    Worker::print();
    std::cout << "Worker's work type: " << this->work << "\nWorker's hours: " << this->hours << '\n';
}

class SalaryWorker : public Worker
{
    private:
        char *work;
        int hours;

        void copyFromSW(const SalaryWorker &other)
        {
            std::size_t lenWork = strlen(other.work) + 1;
            this->work = new char[lenWork];

            if (!this->work)
            {
                std::cout << "[ memory allocation problem ]\n";
                exit(1);
            }
            
            strcpy(this->work, other.work);
            this->hours = other.hours;
        }

        void deallocateSW() {
            delete [] this->work;
        }

    public:
        SalaryWorker(const char* = "", double = 0.0, const char* = "", int = 0);
        SalaryWorker(const SalaryWorker &);  
        SalaryWorker &operator=(const SalaryWorker &);  
        ~SalaryWorker();

        double weeklySalary() const;
        void print() const;
};

SalaryWorker::SalaryWorker(const char* n, double s, const char* w, int h) : Worker(n, s)
{
    this->hours = h;

    std::size_t lenWork = strlen(w) + 1;
    this->work = new char[lenWork];

    if (!this->work)
    {
        std::cout << "[ memory allocation problem ]\n";
        exit(1);
    }

    strcpy(this->work, w);
}

SalaryWorker::SalaryWorker(const SalaryWorker &other) : Worker(other)
{
    this->deallocateSW();
    this->copyFromSW(other);
}

SalaryWorker &SalaryWorker::operator=(const SalaryWorker &other)
{
    if (this != &other)
    {
        Worker::operator=(other);

        this->deallocateSW();
        this->copyFromSW(other);
    }

    return *this;
}

SalaryWorker::~SalaryWorker() {
    this->deallocateSW();
}

double SalaryWorker::weeklySalary() const 
{
    double perHours = getSalary();

    return perHours * this->hours;
}

void SalaryWorker::print() const {
    Worker::print();
    std::cout << "Worker's work type: " << this->work << "\nWorker's hours: " << this->hours << '\n';
}

void create_HourlyWorker_Arr(int m, HourlyWorker **&arr)
{
    arr = new HourlyWorker*[m];

    if (!arr)
    {
        std::cout << "[ memory allocaiton problem ]\n";
        exit(1);
    }

    for (int i = 0; i < m; i++)
    {
        char n[100];
        std::cout << "> name of worker needed: ";
        std::cin.getline(n, 100);
        double s;
        std::cout << "> salary per hour needed: ";
        std::cin >> s;

        std::cin.ignore();

        char w[100];
        std::cout << "> position of worker needed: ";
        std::cin.getline(w, 100);
        double h;
        std::cout << "> all hours needed: ";
        std::cin >> h;

        std::cin.ignore();

        arr[i] = new HourlyWorker(n, s, w, h);
        if(!arr)
        {
            std::cout << "[ memory allocaiton problem ]\n";
            exit(1);
        } 
    }
}

void print_HourlyWorker_arr(int m, HourlyWorker **arr)
{
    for (std::size_t i = 0; i < m; i++)
        arr[i]->print();
}

//не е пълен