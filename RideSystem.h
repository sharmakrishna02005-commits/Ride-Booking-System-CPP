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

    
    Passenger* findPassenger(int id) const;
    Driver* findDriver(int id) const;

public:
    
    RideSystem();

    
    ~RideSystem();

    
    void registerDriver(int id, const std::string& name, double x, double y, double rating = 5.0);
    void registerPassenger(int id, const std::string& name, double x, double y, double destX, double destY);

    
    void requestRide(int passengerId);
    void completeRide(int driverId);

    
    const std::vector<Driver*>& getDrivers() const;
    const std::vector<Passenger*>& getPassengers() const;
    const Queue& getWaitingQueue() const;

    
    void displayStatus() const;
};

#endif 
