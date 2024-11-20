#ifndef DSA_SEAT_H
#define DSA_SEAT_H
#include <iostream>

class Seat {
private:
    bool broken, occupied;
    unsigned int row, column;

public:
    Seat(unsigned int row, unsigned int column, bool broken, bool occupied);
    Seat() = default;
    Seat(const Seat &other) = delete;
    Seat &operator=(const Seat &other) = delete;
    bool &operator==(const Seat &other) const;
    ~Seat() = default;

    bool getBroken() const;
    bool getOccupied() const;
    unsigned int getRow() const;
    unsigned int getColumn() const;

    void setIfBroken(bool flag);
    void setIfOccupied(bool flag);
    void setRow(unsigned int row);
    void setColumn(unsigned int column);

    void printSeat() const;
};


#endif //DSA_SEAT_H
