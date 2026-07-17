#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
private:
    int id;
    std::string name;
    double locationX;
    double locationY;
    double destinationX;
    double destinationY;

public:
    
    Passenger(int id, const std::string& name, double locationX, double locationY, double destinationX, double destinationY);

    
    int getId() const;
    std::string getName() const;
    double getLocationX() const;
    double getLocationY() const;
    double getDestinationX() const;
    double getDestinationY() const;

    
    void setLocation(double x, double y);
    void setDestination(double x, double y);

    
    void display() const;
};

#endif 
