# 🚕 Ride Booking System (C++)

A backend simulation of a ride-sharing booking platform (like Uber or Lyft), built in C++ from scratch — no external libraries, no STL shortcuts for the core logic. This project demonstrates how classic data structures (a min-heap and a FIFO queue) map directly onto a real-world dispatch problem.

---

## 🚀 Key Features

- **Custom Min-Heap Matching** — a hand-built binary min-heap matches each passenger with the closest available driver in `O(log N)` time, based on real-time Euclidean distance.
- **Custom FIFO Waiting Queue** — a hand-built dynamic queue buffers waitlisted passengers when every driver is busy.
- **Auto-Assignment Loop** — the moment a driver completes a ride, the system automatically pulls the next passenger off the waiting queue and matches them — no manual re-triggering needed.
- **CSV Dataset Loading** — the system boots up with a pre-loaded pool of drivers and passengers from `data/drivers.csv` and `data/passengers.csv`, so it behaves like a populated system from the first run instead of starting empty.
- **Interactive CLI** — a validation-secured command-line menu to register drivers/passengers, request rides, complete rides, and view live system status.

---

## 🛠️ Tech Stack & Data Structures

| Component | Role |
|---|---|
| **Language** | C++11 |
| `MinHeap` | Custom binary min-heap for priority-based driver matching |
| `Queue` | Custom dynamic FIFO queue for the passenger waitlist |
| `Driver` | Class representing a driver's ID, name, location, availability, and rating |
| `Passenger` | Class representing a passenger's ID, name, pickup location, and destination |
| `RideSystem` | Coordinator class — owns the driver/passenger lists, the heap, the queue, and all matching logic |

---

## 📊 System Architecture & Flow

```
Passenger requests ride
        │
        ▼
Any driver available? ──No──▶ Enqueue passenger (FIFO waiting queue)
        │ Yes
        ▼
Insert available drivers into min-heap (by distance)
        │
        ▼
extractMin() → closest driver
        │
        ▼
Match driver & passenger, mark driver busy
        │
        ▼
Driver completes ride ──▶ dequeue next waiting passenger (if any)
        │
        ▼
      (loop)
```

*See the interactive flowchart in the project write-up for a visual version of this diagram.*

---

## 📁 Project Structure

```
Ride-Booking-System-CPP/
├── main.cpp              # Entry point — CLI menu, calls RideSystem
├── RideSystem.h / .cpp    # Coordinator — matching logic, CSV loaders
├── Driver.h / .cpp        # Driver class
├── Passenger.h / .cpp     # Passenger class
├── MinHeap.h / .cpp       # Custom min-heap
├── Queue.h / .cpp         # Custom FIFO queue
├── data/
│   ├── drivers.csv        # Sample driver dataset (id, name, x, y, rating)
│   └── passengers.csv     # Sample passenger dataset (id, name, x, y, destX, destY)
└── README.md
```

---

## 💻 How to Compile and Run

Make sure you have a C++ compiler (GCC/g++) installed.

### 1. Clone the repo

```bash
git clone https://github.com/sharmakrishna02005-commits/Ride-Booking-System-CPP.git
cd Ride-Booking-System-CPP
```

### 2. Compile

```bash
g++ -std=c++11 -I. main.cpp Driver.cpp Passenger.cpp Queue.cpp MinHeap.cpp RideSystem.cpp -o main.exe
```

### 3. Run

```bash
# Windows
.\main.exe

# macOS/Linux
./main.exe
```

The system will automatically load the sample dataset from `data/drivers.csv` and `data/passengers.csv` on startup.

### 4. Use the menu

```
=== RIDE BOOKING SYSTEM MENU ===
1. Register a Driver
2. Register a Passenger
3. Request a Ride
4. Complete a Ride
5. Display System Status
6. Exit
```

Try option `5` first to confirm the sample dataset loaded correctly.

---

## 📄 Dataset Format

Want to add your own drivers/passengers? Just edit or extend the CSV files — no code changes needed.

**`data/drivers.csv`**
```
id,name,x,y,rating
1,Amit Sharma,12.5,45.2,4.8
```

**`data/passengers.csv`**
```
id,name,x,y,destX,destY
101,Rahul Mehta,10.0,40.0,20.0,50.0
```

---

## 🔭 Possible Future Improvements

- REST API layer (`cpp-httplib`) to connect a web frontend
- Fare calculation based on distance and driver rating
- Ride history logging
- Manhattan distance / graph-based routing instead of straight-line distance
- Unit tests for `MinHeap` and `Queue`

