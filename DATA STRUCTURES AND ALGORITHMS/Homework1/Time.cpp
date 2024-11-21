//#include "Time.h"
//#include <iostream>
//#include <cassert>
//
//Time::Time(short hour, short minutes) {
//    this->setHour(hour);
//    this->setMinutes(minutes);
//}
//
//Time::Time(const Time &other) : hour(other.getHour()), minutes(other.getMinutes()) {}
//
//short Time::getHour() const {
//    return this->hour;
//}
//
//short Time::getMinutes() const {
//    return this->minutes;
//}
//
//void Time::setHour(short hour) {
//    assert(0 <= hour && hour <= 23);
//
//    if(hour <= 7 || hour >= 18)
//        throw std::invalid_argument("Invalid hour given or student came too early/late.");
//
//    this->hour = hour;
//}
//
//void Time::setMinutes(short minutes) {
//    if(0 <= minutes && minutes <= 59)
//        this->minutes = minutes;
//
//    else
//        throw std::invalid_argument("Minutes can't extend [0, 59] interval.");
//}
//
//Time Time::fromString(const std::string& timeStr) {
//    if (timeStr.size() != 5 || timeStr[2] != ':')
//        throw std::invalid_argument("Invalid time format. Expected format: HH:MM");
//
//    short hour = std::stoi(timeStr.substr(0, 2));
//    short minutes = std::stoi(timeStr.substr(3, 2));
//
//    return Time(hour, minutes);
//}
//
//void Time::printTime() const {
//    std::cout << '[';
//
//    if(8 <= this->getHour() && this->getHour() <= 9)
//        std::cout << '0' << this->hour << ':';
//
//    else
//        std::cout << this->hour << ':';
//
//    if(0 <= this->getMinutes() && this->getMinutes() <= 9)
//        std::cout << '0' << this->minutes << "]\n";
//
//    else
//        std::cout << this->minutes << "]\n";
//}
//
//
//
////int main() {
////    try {
////        Time validTime = Time::fromString("08:30");
////        std::cout << "Valid time: " << validTime.getHour() << ":" << validTime.getMinutes() << "\n";
////
////        Time invalidTime = Time::fromString("25:61");
////        std::cout << "Invalid time: " << invalidTime.getHour() << ":" << invalidTime.getMinutes() << "\n";
////
////    } catch (const std::invalid_argument& e) {
////        std::cerr << "Error: " << e.what() << std::endl;
////    }
////
////    return 0;
////}
