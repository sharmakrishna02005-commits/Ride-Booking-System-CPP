#include "Driver.h"
#include <iostream>

// Constructor
Driver::Driver(int id, const std::string& name, double locationX, double locationY, double rating)
    : id(id), name(name), locationX(locationX), locationY(locationY), available(true), rating(rating) {}

// Getters
int Driver::getId() const {
    return id;
}

std::string Driver::getName() const {
    return name;
}

double Driver::getLocationX() const {
    return locationX;
}

double Driver::getLocationY() const {
    return locationY;
}

bool Driver::isAvailable() const {
    return available;
}

double Driver::getRating() const {
    return rating;
}

// Setters
void Driver::setLocation(double x, double y) {
    locationX = x;
    locationY = y;
}

void Driver::setAvailable(bool avail) {
    available = avail;
}

void Driver::setRating(double rate) {
    rating = rate;
}

// Display Driver Info
void Driver::display() const {
    std::cout << "[Driver ID: " << id 
              << ", Name: " << name 
              << ", Location: (" << locationX << ", " << locationY << ")"
              << ", Rating: " << rating 
              << ", Status: " << (available ? "Available" : "Busy") 
              << "]" << std::endl;
}
