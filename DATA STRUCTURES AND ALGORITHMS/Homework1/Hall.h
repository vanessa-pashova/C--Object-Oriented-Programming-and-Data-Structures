#include "Seat.h"

#include <iostream>
#include <vector>

#ifndef DSA_HALL_H
#define DSA_HALL_H


class Hall {
private:
    unsigned int row, column, brokenSeatsCount;
    std::vector<Seat*> matrixOfSeats;
    std::vector<Seat*> brokenSeats;

    void clearSeats(std::vector<Seat*> &seats) {
        for (Seat* seat : seats) {
            delete seat;
        }
        seats.clear();
    }

public:
    Hall(unsigned int row, unsigned int column);
    ~Hall();

    Hall() = delete;
    Hall(const Hall &other) = delete;
    Hall &operator=(const Hall &other) = delete;

    unsigned int getRowsInHall() const;
    unsigned int getColumnsInHall() const;
    unsigned int getBrokenSeatsCount() const;
    const std::vector<Seat*> &getBrokenSeats() const;
    const std::vector<Seat*> &getMatrixOfSeats() const;

    void setBrokenSeatsCount(unsigned int brokenSeatsCnt);

    void insertValuesForRowAndCols(unsigned int row, unsigned int column);
    void defineBrokenSeats(std::vector<unsigned int> brokenSeatsIndexes);
    void generateAvailableSeats(std::vector<unsigned int> brokenSeatsIndexes);

    void printLayoutOfHall() const;
    bool assignSeatToStudent(unsigned int studentID, unsigned int arrivalTime, unsigned int duration);
    void releaseSeats(unsigned int currentTime);
};


#endif //DSA_HALL_H