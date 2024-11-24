#include "Seat.h"

#include <iostream>
#include <vector>

#ifndef DSA_HALL_H
#define DSA_HALL_H

class Hall {
private:
    unsigned int row, column, brokenSeatsCount, startTime;
    std::vector<Seat*> matrixOfSeats;
    std::vector<Seat*> brokenSeats;

    void clearSeats(std::vector<Seat*> &seats) {
        for (Seat* seat : seats)
            delete seat;

        seats.clear();
    }

    std::string formatTime(unsigned int minutes) const {
        unsigned int hours = minutes / 60;
        unsigned int mins = minutes % 60;

        std::string time = std::to_string(hours) + ":";
        time += (mins < 10 ? "0" : "") + std::to_string(mins);
        return time;
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
    unsigned int getStartTime() const;
    const std::vector<Seat*> &getBrokenSeats() const;
    const std::vector<Seat*> &getMatrixOfSeats() const;

    void setBrokenSeatsCount(unsigned int brokenSeatsCnt);
    void setStartTime();

    void insertValuesForRowAndCols(unsigned int row, unsigned int column);
    void defineBrokenSeats(std::vector<unsigned int> brokenSeatsIndexes);
    void generateAvailableSeats(std::vector<unsigned int> brokenSeatsIndexes);

    bool assignSeatToStudent(unsigned int studentID, unsigned int arrivalTime, unsigned int duration);
    void releaseSeats(unsigned int currentTime);
    void printLayoutOfHall() const;
    bool hasFreeSeats() const;
};

#endif //DSA_HALL_H