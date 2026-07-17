#include "RideSystem.h"
#include <iostream>
#include <cmath>


RideSystem::RideSystem() {}


RideSystem::~RideSystem() {
    for (Driver* d : drivers) {
        delete d;
    }
    drivers.clear();

    for (Passenger* p : passengers) {
        delete p;
    }
    passengers.clear();
}


Passenger* RideSystem::findPassenger(int id) const {
    for (Passenger* p : passengers) {
        if (p->getId() == id) {
            return p;
        }
    }
    return nullptr;
}


Driver* RideSystem::findDriver(int id) const {
    for (Driver* d : drivers) {
        if (d->getId() == id) {
            return d;
        }
    }
    return nullptr;
}

// Register driver
void RideSystem::registerDriver(int id, const std::string& name, double x, double y, double rating) {
    if (findDriver(id) != nullptr) {
        std::cout << "Error: Driver with ID " << id << " already exists." << std::endl;
        return;
    }
    drivers.push_back(new Driver(id, name, x, y, rating));
    std::cout << "Driver " << name << " registered successfully." << std::endl;
}

// Register passenger
void RideSystem::registerPassenger(int id, const std::string& name, double x, double y, double destX, double destY) {
    if (findPassenger(id) != nullptr) {
        std::cout << "Error: Passenger with ID " << id << " already exists." << std::endl;
        return;
    }
    passengers.push_back(new Passenger(id, name, x, y, destX, destY));
    std::cout << "Passenger " << name << " registered successfully." << std::endl;
}

// Request ride
void RideSystem::requestRide(int passengerId) {
    Passenger* passenger = findPassenger(passengerId);
    if (passenger == nullptr) {
        std::cout << "Error: Passenger ID " << passengerId << " not found." << std::endl;
        return;
    }

    // Check if there are any available drivers
    bool anyAvailable = false;
    for (Driver* d : drivers) {
        if (d->isAvailable()) {
            anyAvailable = true;
            break;
        }
    }

    if (!anyAvailable) {
        std::cout << "No drivers available. Placing Passenger " << passenger->getName() 
                  << " in the waiting queue." << std::endl;
        waitingQueue.enqueue(passenger);
        return;
    }

    // Load available drivers into MinHeap
    MinHeap heap;
    for (Driver* d : drivers) {
        if (d->isAvailable()) {
            double dist = std::sqrt(std::pow(d->getLocationX() - passenger->getLocationX(), 2) +
                                    std::pow(d->getLocationY() - passenger->getLocationY(), 2));
            heap.insert(d, dist);
        }
    }

    // Match with closest
    Driver* closestDriver = heap.extractMin();
    if (closestDriver != nullptr) {
        double dist = std::sqrt(std::pow(closestDriver->getLocationX() - passenger->getLocationX(), 2) +
                                std::pow(closestDriver->getLocationY() - passenger->getLocationY(), 2));
        
        closestDriver->setAvailable(false);
        activeRides[closestDriver->getId()] = passenger;

        std::cout << "Matched Passenger " << passenger->getName() 
                  << " with closest available Driver " << closestDriver->getName() 
                  << " (Distance: " << dist << " units)." << std::endl;
    }
}


void RideSystem::completeRide(int driverId) {
    Driver* driver = findDriver(driverId);
    if (driver == nullptr) {
        std::cout << "Error: Driver ID " << driverId << " not found." << std::endl;
        return;
    }

    auto it = activeRides.find(driverId);
    if (it == activeRides.end()) {
        std::cout << "Error: Driver " << driver->getName() << " is not currently on an active ride." << std::endl;
        return;
    }

    Passenger* passenger = it->second;
    double destX = passenger->getDestinationX();
    double destY = passenger->getDestinationY();

    
    driver->setLocation(destX, destY);
    activeRides.erase(it);

    std::cout << "Driver " << driver->getName() << " completed the ride for " << passenger->getName() 
              << ". New location: (" << destX << ", " << destY << ")." << std::endl;

    
    if (!waitingQueue.isEmpty()) {
        Passenger* nextPassenger = waitingQueue.dequeue();
        
        
        driver->setAvailable(false);
        activeRides[driverId] = nextPassenger;

        double dist = std::sqrt(std::pow(driver->getLocationX() - nextPassenger->getLocationX(), 2) +
                                std::pow(driver->getLocationY() - nextPassenger->getLocationY(), 2));

        std::cout << "Driver " << driver->getName() << " immediately matched with waitlisted Passenger " 
                  << nextPassenger->getName() << " (Distance: " << dist << " units)." << std::endl;
    } else {
        
        driver->setAvailable(true);
        std::cout << "Driver " << driver->getName() << " is now available." << std::endl;
    }
}


const std::vector<Driver*>& RideSystem::getDrivers() const {
    return drivers;
}

const std::vector<Passenger*>& RideSystem::getPassengers() const {
    return passengers;
}

const Queue& RideSystem::getWaitingQueue() const {
    return waitingQueue;
}


void RideSystem::displayStatus() const {
    std::cout << "\n=== RIDE SYSTEM STATUS ===" << std::endl;
    
    std::cout << "\nDrivers:" << std::endl;
    if (drivers.empty()) {
        std::cout << "  No registered drivers." << std::endl;
    } else {
        for (Driver* d : drivers) {
            std::cout << "  ";
            d->display();
        }
    }

    std::cout << "\nPassengers:" << std::endl;
    if (passengers.empty()) {
        std::cout << "  No registered passengers." << std::endl;
    } else {
        for (Passenger* p : passengers) {
            std::cout << "  ";
            p->display();
        }
    }

    std::cout << "\nWaiting Queue size: " << waitingQueue.getSize() << std::endl;
    if (!waitingQueue.isEmpty()) {
        Passenger* front = waitingQueue.peek();
        std::cout << "  Next in line: " << front->getName() << " (ID: " << front->getId() << ")" << std::endl;
    }
    std::cout << "==========================\n" << std::endl;
}
