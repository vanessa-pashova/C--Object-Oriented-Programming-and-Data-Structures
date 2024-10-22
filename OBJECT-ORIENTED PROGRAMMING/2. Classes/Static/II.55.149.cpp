//Лекар трябва да поддържа статистика за броя на посещенията, които са направили пациентите му. За всеки пациент лекарят записва името, дадата на раждане и 
//броя на посещенията, които е направил пациентът през една календарна година. Да се напише програма, която за лекар:
// - създава списък с пациентите му
// - намира среден брой посещения на пациентите му
// - намира пациентите, които са надвишили обичайния лимит за посещения
//За имената на пациентите и лекарите програмата заделя памет, колкото е дължината им, а списъкът от пациенти на лекар да е разположен в динамичната памет.
//Класовете реализиращи данните за пациент и лекар, да поддържат канонично представяне. Освен това, чрез статична данн, инициализирана с нула, да се задава индексът на текущо
//регистриран пациент.

#include <iostream>
#include <fstream>

class Name 
{
    private: 
        char *name;
        char *surname;

        void deallocate() {
            delete [] name;
            delete [] surname;
        }

        void copyFrom(const Name &other) 
        {
            int sizeName = strlen(other.name) + 1;
            int sizeSurname = strlen(other.surname) + 1;

            name = new char[sizeName];
            surname = new char[sizeSurname];

            strcpy(name, other.name);
            strcpy(surname, other.surname);
        }

    public: 
        Name();
        Name(const char *, const char *);
        ~Name();
        Name(const Name &);
        Name &operator=(const Name &);

        const char *getName () const;
        const char *getSurname () const;

        friend std::ostream &operator<<(std::ostream &out, const Name &name);

        void print();
};

Name::Name() : name(nullptr), surname(nullptr) {}

Name::Name(const char *name, const char *surname)
{
    int sizeName = strlen(name) + 1;
    int sizeSurname = strlen(surname) + 1;

    this->name = new char[sizeName];
    this->surname = new char[sizeSurname];

    strcpy(this->name, name);
    strcpy(this->surname, surname);
}

Name::~Name() {
    deallocate();
}

Name::Name(const Name &other) : name(nullptr), surname(nullptr) {
    copyFrom(other);
}

Name &Name::operator=(const Name &other) {
    if (this != &other) {
        deallocate();
        copyFrom(other);
    }
    return *this;
}

const char *Name::getName() const {
    return name;
}

const char *Name::getSurname() const {
    return surname;
}

std::ostream &operator<<(std::ostream &out, const Name &name) {
    out << name.getName() << ' ' << name.getSurname();
    return out;
}

void Name::print() {
    std::cout << "[ Name ] -> " << name << ' ' << surname << "\n\n";
}

class DateOfBirth
{
    private:
        int day, month, year;

        void copyFrom(const DateOfBirth &other)
        {
            this->day = other.day;
            this->month = other.month;
            this->year = other.year;
        }
   
    public:
        DateOfBirth();
        DateOfBirth(int, int, int);
        
        int getDay () const;
        int getMonth () const;
        int getYear () const;

        DateOfBirth &operator=(const DateOfBirth &);

        friend std::ostream &operator<<(std::ostream &out, const DateOfBirth &dob);

        void print();
};

DateOfBirth::DateOfBirth() : day(1), month(1), year(1910) {}

DateOfBirth::DateOfBirth(int day, int month, int year)
{
    if (day < 1 || 31 < day || month < 1 || 12 < month || year < 1910 || 2024 < year)
    {
        std::cout << "[ wrong date ]\n";
        exit(1);
    }

    this->day = day;
    this->month = month;
    this->year = year;
}

int DateOfBirth::getDay() const {
    return this->day;
}

int DateOfBirth::getMonth() const {
    return this->month;
}

int DateOfBirth::getYear() const {
    return this->year;
}

DateOfBirth &DateOfBirth::operator=(const DateOfBirth &other)
{
    if (this != &other)
        copyFrom(other);

    return *this;
}

std::ostream &operator<<(std::ostream &out, const DateOfBirth &dob)
{
    out << dob.getDay() << '.' << dob.getMonth() << '.' << dob.getYear();
    return out;
}

void DateOfBirth::print() {
    std::cout << "[ date of birth ] -> " << this->day << '.' << this->month << '.' << this->year << "\n\n";
}

class Patient
{
    private:
        Name *name;
        DateOfBirth date;
        unsigned int visits;

    public:
        Patient() : visits(0) {}
        Patient(const Name& name, const DateOfBirth& date, unsigned int visits);
        ~Patient();

        Patient &operator=(const Patient &);

        const Name *getName () const;
        int getVisits () const;

        void print();
        bool out_of_limits(int);
};

Patient::Patient(const Name& name, const DateOfBirth& date, unsigned int visits) : date(date), visits(visits) {
    this->name = new Name(name);
}

Patient::~Patient() {}

Patient &Patient::operator=(const Patient &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->date = other.date;
        this->visits = other.visits;
    }

    return *this;
}

int Patient::getVisits() const {
    return this->visits;
}

const Name* Patient::getName() const {
    return this->name;
}

//За да изведем името, трябва да използваме оператора << върху обекта Name, а не директно върху указателя към обекта Name. 
void Patient::print() {
    std::cout << "[ Patient (name, DOB, visits) ] -> " << *this->name << ", " << this->date << ", " << this->visits << '\n';
}

bool Patient::out_of_limits(int max) {
    return this->visits > max;
}

class Doctor
{
    private:
        Name *name;
        Patient *patients;
        static int Registreted;

    public:
        Doctor(const char* = "", int = 0);
        Doctor(Name &name);
        ~Doctor();

        Doctor &operator=(const Doctor &);

        void registration_list(const Patient &pat);
        double avg_visits();
        void out_of_limit_list(int);
};
int Doctor::Registreted = 0;

Doctor::Doctor(Name &name)
{
    this->name = new Name(name);
    patients = new Patient[100]; // Заделяме памет за масива от пациенти
}

Doctor::~Doctor()
{
    delete name;
    delete[] patients; // Освобождаваме заделената памет за масива от пациенти
}

Doctor &Doctor::operator=(const Doctor &other)
{
    if (this != &other)
    {
        delete name;
        name = new Name(*other.name); // Тук трябва да извършим дълбоко копиране на пациентите
    }

    return *this;
}

void Doctor::registration_list(const Patient &pat) {
    patients[Registreted] = pat;
    Registreted++;
}

double Doctor::avg_visits() 
{
    int totalV = 0, reg = Registreted;
    for (std::size_t i = 0; i < reg; i++)
        totalV += patients[i].getVisits();

    if (reg != 0)
        return double(totalV)/reg;

    else
        return 0;
}

void Doctor::out_of_limit_list(int max) {
    int reg = Registreted;
    for (std::size_t i = 0; i < reg; i++)
    {
        if (max < patients[i].getVisits())
            std::cout << *patients[i].getName() << '\n';
    }

    std::cout << '\n';
}

int main()
{
    std::cout << '\n';
    std::cout << "-----------------------\n";
 
    // Създаване на обекти от тип Name за лекаря и пациентите
    Name doctorName("Dr. Smith", "Johnson");
    Name patient1Name("John", "Doe");
    Name patient2Name("Jane", "Smith");
    Name patient3Name("Michael", "Brown");

    // Създаване на обекти от тип DateOfBirth за пациентите
    DateOfBirth patient1DOB(10, 5, 1990);
    DateOfBirth patient2DOB(15, 8, 1985);
    DateOfBirth patient3DOB(20, 3, 1978);

    // Създаване на обекти от тип Patient
    Patient patient1(patient1Name, patient1DOB, 3);
    Patient patient2(patient2Name, patient2DOB, 5);
    Patient patient3(patient3Name, patient3DOB, 2);

    // Създаване на обект от тип Doctor
    Doctor doctor(doctorName);

    // Регистриране на пациентите при лекаря
    doctor.registration_list(patient1);
    doctor.registration_list(patient2);
    doctor.registration_list(patient3);

    // Извеждане на средния брой посещения на пациентите при лекаря
    double avgVisits = doctor.avg_visits();
    std::cout << "Average visits per patient: " << avgVisits << std::endl;

    // Извеждане на пациентите, които са надвишили обичайния лимит за посещения
    int maxVisits = 4;
    std::cout << "Patients with visits exceeding the limit of " << maxVisits << ": ";
    doctor.out_of_limit_list(maxVisits);

    std::cout << "Doctor: " << doctorName << std::endl;
    std::cout << "Patients: " << std::endl;
    patient1.print();
    patient2.print();
    patient3.print();

    return 0;
}
//✅