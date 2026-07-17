#include "Passenger.h"
#include <iostream>

// Constructor
Passenger::Passenger(int id, const std::string& name, double locationX, double locationY, double destinationX, double destinationY)
    : id(id), name(name), locationX(locationX), locationY(locationY), destinationX(destinationX), destinationY(destinationY) {}

// Getters
int Passenger::getId() const {
    return id;
}

std::string Passenger::getName() const {
    return name;
}

double Passenger::getLocationX() const {
    return locationX;
}

double Passenger::getLocationY() const {
    return locationY;
}

double Passenger::getDestinationX() const {
    return destinationX;
}

double Passenger::getDestinationY() const {
    return destinationY;
}

// Setters
void Passenger::setLocation(double x, double y) {
    locationX = x;
    locationY = y;
}

void Passenger::setDestination(double x, double y) {
    destinationX = x;
    destinationY = y;
}

// Display Passenger Info
void Passenger::display() const {
    std::cout << "[Passenger ID: " << id 
              << ", Name: " << name 
              << ", Pickup: (" << locationX << ", " << locationY << ")"
              << ", Destination: (" << destinationX << ", " << destinationY << ")"
              << "]" << std::endl;
}
