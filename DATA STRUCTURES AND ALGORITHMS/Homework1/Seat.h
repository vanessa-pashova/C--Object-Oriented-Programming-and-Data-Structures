#ifndef DSA_SEAT_H
#define DSA_SEAT_H
#include <iostream>

class Seat {
private:
    bool broken, occupied;
    unsigned int index;
    unsigned int occupiedUntilTime;

public:
    Seat(unsigned int index, bool broken, bool occupied);
    Seat();

    Seat(const Seat &other);
    Seat &operator=(const Seat &other);

    bool operator==(const Seat &other) const;
    ~Seat() = default;

    bool getBroken() const;
    bool getOccupied() const;
    unsigned int getIndex() const;
    char getSign() const;
    unsigned int getOccupiedUntilTime() const;

    void setIfBroken(bool flag);
    void setIfOccupied(bool flag);
    void setIndex(unsigned int index);
    void setOccupiedUntilTime(unsigned int time);

    void printSeat() const;
};


#endif //DSA_SEAT_H