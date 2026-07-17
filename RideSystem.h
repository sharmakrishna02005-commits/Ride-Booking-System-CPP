#ifndef RIDESYSTEM_H
#define RIDESYSTEM_H

#include <vector>
#include <string>
#include <unordered_map>
#include "Driver.h"
#include "Passenger.h"
#include "Queue.h"
#include "MinHeap.h"

class RideSystem {
private:
    std::vector<Driver*> drivers;
    std::vector<Passenger*> passengers;
    Queue waitingQueue;
    std::unordered_map<int, Passenger*> activeRides; // Tracks driverId -> Passenger*

    // Helper methods to find passenger and driver by ID
    Passenger* findPassenger(int id) const;
    Driver* findDriver(int id) const;

public:
    // Constructor
    RideSystem();

    // Destructor
    ~RideSystem();

    // Registration
    void registerDriver(int id, const std::string& name, double x, double y, double rating = 5.0);
    void registerPassenger(int id, const std::string& name, double x, double y, double destX, double destY);

    // Ride operations
    void requestRide(int passengerId);
    void completeRide(int driverId);

    // Getters
    const std::vector<Driver*>& getDrivers() const;
    const std::vector<Passenger*>& getPassengers() const;
    const Queue& getWaitingQueue() const;

    // Display system status
    void displayStatus() const;
};

#endif // RIDESYSTEM_H
