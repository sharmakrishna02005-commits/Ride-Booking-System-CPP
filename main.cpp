#include <iostream>
#include <string>
#include <limits>
#include "RideSystem.h"


double readDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        }
        std::cout << "Invalid input. Please enter a valid number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}


int readInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        }
        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}


void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    RideSystem system;
    system.loadDriversFromCSV("data/drivers.csv");
    system.loadPassengersFromCSV("data/passengers.csv");
    std::cout << "System initialized with sample data.\n" << std::endl;

    int choice = 0;
    while (true) {
        std::cout << "=== RIDE BOOKING SYSTEM MENU ===" << std::endl;
        std::cout << "1. Register a Driver" << std::endl;
        std::cout << "2. Register a Passenger" << std::endl;
        std::cout << "3. Request a Ride" << std::endl;
        std::cout << "4. Complete a Ride" << std::endl;
        std::cout << "5. Display System Status" << std::endl;
        std::cout << "6. Exit" << std::endl;
        choice = readInt("Enter your choice (1-6): ");

        if (choice == 6) {
            std::cout << "Exiting Ride Booking System. Goodbye!" << std::endl;
            break;
        }

        switch (choice) {
            case 1: {
                int id = readInt("Enter Driver ID: ");
                std::cout << "Enter Driver Name: ";
                clearInputBuffer();
                std::string name;
                std::getline(std::cin, name);
                double x = readDouble("Enter Current Location X: ");
                double y = readDouble("Enter Current Location Y: ");
                double rating = readDouble("Enter Rating (1.0 - 5.0): ");
                
                system.registerDriver(id, name, x, y, rating);
                break;
            }
            case 2: {
                int id = readInt("Enter Passenger ID: ");
                std::cout << "Enter Passenger Name: ";
                clearInputBuffer();
                std::string name;
                std::getline(std::cin, name);
                double x = readDouble("Enter Pickup Location X: ");
                double y = readDouble("Enter Pickup Location Y: ");
                double destX = readDouble("Enter Destination Location X: ");
                double destY = readDouble("Enter Destination Location Y: ");
                
                system.registerPassenger(id, name, x, y, destX, destY);
                break;
            }
            case 3: {
                int passengerId = readInt("Enter Passenger ID requesting ride: ");
                system.requestRide(passengerId);
                break;
            }
            case 4: {
                int driverId = readInt("Enter Driver ID completing ride: ");
                system.completeRide(driverId);
                break;
            }
            case 5: {
                system.displayStatus();
                break;
            }
            default: {
                std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
                break;
            }
        }
        std::cout << "\n";
    }

    return 0;
}
