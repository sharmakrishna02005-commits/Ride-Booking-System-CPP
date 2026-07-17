#ifndef DRIVER_H
#define DRIVER_H

#include <string>

class Driver {
private:
    int id;
    std::string name;
    double locationX;
    double locationY;
    bool available;
    double rating;

public:
    
    Driver(int id, const std::string& name, double locationX, double locationY, double rating = 5.0);

    
    int getId() const;
    std::string getName() const;
    double getLocationX() const;
    double getLocationY() const;
    bool isAvailable() const;
    double getRating() const;

    
    void setLocation(double x, double y);
    void setAvailable(bool avail);
    void setRating(double rate);

    
    void display() const;
};

#endif 
