# ✈️ Airport Management System

A command-line based Airport Management System developed in C++ that simulates real-world functionalities such as booking tickets, managing flights, baggage tracking, and handling reservations. Built using core **Data Structures and Algorithms**.


---

## 📌 Features
- Add & remove **domestic/international airports**
- Book & cancel tickets (manual/online)
- Display passenger lists and reservations
- Queue-based boarding simulation
- Baggage tracking
- Exit option for safe shutdown

---

## 🏗️ Components

### Classes Implemented:
- `Airport`  
  - Domestic & International subclasses  
- `Flight`  
- `Passenger`  
  - Includes optional special services  
- `Baggage`  
- `BoardingQueue`  
  - Stack-based structure for managing airports  
- `LinkedList`  
  - For managing passenger records

---

## 📚 DSA Concepts Used
- **Arrays**: String manipulation and object data handling
- **Stack**: Airport queue management (boarding)
- **Linked List**: Efficient passenger reservation system
- **Linear Search**: For passenger lookup and deletion
- **Dynamic Memory**: Manual memory handling using `new` and `delete`

---

## 🚀 Usage

### Compile and Run
```bash
g++ main.cpp -o airport
./airport
