#include "Seat.h"

#include <iostream>
#include <vector>

#ifndef DSA_HALL_H
#define DSA_HALL_H


class Hall {
private:
    unsigned int row, column, brokenSeatsCount;
    std::vector<Seat*> matrixOfSeats; //can be just a vector and every new row starts on every mod column index
    std::vector<Seat*> brokenSeats;

public:
    Hall(unsigned int row, unsigned int column);

    Hall() = delete;
    Hall(const Hall &other) = delete;
    Hall &operator=(const Hall &other) = delete;
    ~Hall();

    unsigned int getRowsInHall() const;
    unsigned int getColumnsInHall() const;
    unsigned int getBrokenSeatsCount() const;
    const std::vector<Seat*>& getBrokenSeats() const;

    void setBrokenSeatsCount(unsigned int brokenSeatsCnt);

    void insertValuesForRowAndCols();
    void defineBrokenSeats();
    void generateAvailableSeats();
//    void orderStudents();
};


#endif //DSA_HALL_H
