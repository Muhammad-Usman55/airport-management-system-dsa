// Submitted by
// Hamza Asif F2022376135
//Muhammad Usman Shahid     F2022376068
//Jasim Abrar F2022376138
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_AIRPORTS = 100;

class Airport
{
private:
    char name[50];
    char airportCode[10];

public:
    Airport()
    {
        strcpy(name, "");
        strcpy(airportCode, "");
    }

    Airport(const char *name, const char *code)
    {
        strcpy(this->name, name);
        strcpy(this->airportCode, code);
    }

    void displayInformation()
    {
        cout << "Airport: " << name << " (" << airportCode << ")" << endl;
    }
};

class InternationalAirport : public Airport
{
private:
    char country[50];

public:
    InternationalAirport(const char *name, const char *code, const char *country)
        : Airport(name, code)
    {
        strcpy(this->country, country);
    }

    void displayInformation()
    {
        Airport::displayInformation();
        cout << "Country: " << country << endl;
    }
};

class DomesticAirport : public Airport
{
private:
    char region[50];

public:
    DomesticAirport(const char *name, const char *code, const char *region)
        : Airport(name, code)
    {
        strcpy(this->region, region);
    }

    void displayInformation()
    {
        Airport::displayInformation();
        cout << "Region: " << region << endl;
    }
};

class Flight
{
private:
    char flightNumber[20];
    char destination[50];

public:
    Flight(const char *flightNumber, const char *destination)
    {
        strcpy(this->flightNumber, flightNumber);
        strcpy(this->destination, destination);
    }

    void displayInformation()
    {
        cout << "Flight: " << flightNumber << " to " << destination << endl;
    }
};

class Passenger
{
private:
    char name[50];
    char passportNumber[20];
    char specialService[50];

public:
    Passenger(const char *name, const char *passportNumber) 
    {
        strcpy(this->name, name);
        strcpy(this->passportNumber, passportNumber);
    }

    const char *getPassportNumber() const
    {
        return passportNumber;
    }

    const char *getSpecialService() const
    {
        return specialService;
    }

    void setSpecialService(const char *service)
    {
        strcpy(this->specialService, service);
    }

    void displayInformation()
    {
        cout << "Passenger: " << name << " (Passport: " << passportNumber << ")";
        if (strlen(specialService) > 0)
        {
            cout << " - Special Service: " << specialService;
        }
        cout << endl;
    }
};

class Baggage
{
private:
    int weight;
    char description[50];

public:
    Baggage(int weight, const char *description) : weight(weight)
    {
        strcpy(this->description, description);
    }

    void displayInformation()
    {
        cout << "Baggage: " << weight << "kg - " << description << endl;
    }
};

class BoardingQueue
{
private:
    Airport stack[MAX_AIRPORTS];
    int top;

public:
    BoardingQueue() : top(-1) {}

    void enqueue(const Airport &airport)
    {
        if (top < MAX_AIRPORTS - 1)
        {
            top++;
            stack[top] = airport;
        }
        else
        {
            cout << "Queue is full. Cannot enqueue more airports." << endl;
        }
    }

    Airport dequeue()
    {
        if (top >= 0)
        {
            Airport airport = stack[top];
            top--;
            return airport;
        }

        return Airport("", "");
    }

    bool isEmpty() const
    {
        return top == -1;
    }
};


struct Node
{
    Passenger data;
    Node *next;
};
// class LinkedList;
//     class Board
// {
// private:
//     LinkedList boardingList;  // Non-pointer member

// public:
//     void addToBoardingList(const Passenger &passenger)
//     {
//         boardingList.insertion_end(passenger);  // Use . instead of ->
//     }

//     void displayBoardingList()
//     {
//         cout << "Passengers in Boarding List:\n";
//         boardingList.display();
//     }

class LinkedList
{
private:
    Node *head;
    int size;
    Node *tail;

public:
    LinkedList() : head(NULL), size(0), tail(NULL) {}

    Node *getHead() const
    {
        return head;
    }

    void setHead(Node *newHead)
    {
        head = newHead;
    }

    int getSize() const
    {
        return size;
    }

    void decreaseSize()
    {
        size--;
    }

    void insertion(const Passenger &passenger)
    {
        Node *newNode = new Node{passenger, NULL};

        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

        size++;
    }

    void insertion_end(const Passenger &passenger)
    {
        Node *newNode = new Node{passenger, NULL};

        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    void display()
    {
        Node *current = head;
        while (current)
        {
            current->data.displayInformation();
            current = current->next;
        }
    }

    void deletion()
    {
        if (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
        }
        else
        {
            cout << "List is empty. Cannot delete from the start." << endl;
        }
    }

    void dele_end()
    {
        if (head)
        {
            if (head == tail)
            {
                delete head;
                head = tail = NULL;
            }
            else
            {
                Node *current = head;
                while (current->next != tail)
                {
                    current = current->next;
                }

                delete tail;
                tail = current;
                tail->next = NULL;
            }
            size--;
        }
        else
        {
            cout << "List is empty. Cannot delete from the end." << endl;
        }
    }

};

int main()
{
    BoardingQueue boardingQueue;		// using queues
    LinkedList passengerList;

    int choice;
    do
    {
    	cout<<"Menu and DSA concepts used in each function\n";
        cout << "1. Add Airport (using array)\n2. Remove Airport (using queue)\n3. Book Ticket (using linked lists)\n4. Display Passengers (using linked lists)\n";
        cout << "5. Check Reservations (using linked lists)\n6. Cancel Reservation (using linked lists)\n7. Book Ticket Online (using linked lists)\n";
        cout << "8. Check Airport List (using array)\n9: Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            char name[50], code[10], countryOrRegion[50];
            int typeChoice;

            cout << "Enter Airport Name: ";
            cin.ignore();
            cin.getline(name, sizeof(name));

            cout << "Enter Airport Code: ";
            cin >> code;

            cout << "1. International Airport\n2. Domestic Airport\nChoose Airport Type: ";
            cin >> typeChoice;

            if (typeChoice == 1)
            {
                cout << "Enter Country: ";
                cin.ignore();
                cin.getline(countryOrRegion, sizeof(countryOrRegion));

                InternationalAirport internationalAirport(name, code, countryOrRegion);
                boardingQueue.enqueue(internationalAirport);
            }
            else if (typeChoice == 2)
            {
                cout << "Enter Region: ";
                cin.ignore();
                cin.getline(countryOrRegion, sizeof(countryOrRegion));

                DomesticAirport domesticAirport(name, code, countryOrRegion);
                boardingQueue.enqueue(domesticAirport);
            }
            else
            {
                cout << "Invalid choice for Airport Type." << endl;
            }
            break;
        }
        case 2:
        {
            Airport removedAirport = boardingQueue.dequeue();
            removedAirport.displayInformation();
            cout << "Airport removed from the queue." << endl;
            break;
        }
       case 3:
{
    char name[50], passportNumber[20];
    cout << "Enter Passenger Name: ";
    cin.ignore();
    cin.getline(name, sizeof(name));

    cout << "Enter Passport Number: ";
    cin >> passportNumber;

    // Add this line to clear the newline character from the buffer
    cin.ignore();

    Passenger passenger(name, passportNumber);

  
    
    passengerList.insertion_end(passenger);

    cout << "Ticket booked successfully!" << endl;
    break;
}

        case 4:
            cout << "Passengers List:\n";
            passengerList.display();
            break;
        case 5: {
            // Check Reservations
            if (passengerList.getSize() > 0) {
                cout << "Reservations available.\n";
                passengerList.display();
            } else {
                cout << "No reservations available.\n";
            }
            break;
        }
        case 6:
        {
            char passportNumber[20];
            cout << "Enter Passport Number to cancel ticket: ";
            cin >> passportNumber;

            Node *current = passengerList.getHead();
            Node *prev = NULL;

            while (current && strcmp(current->data.getPassportNumber(), passportNumber) != 0)
            {
                prev = current;
                current = current->next;
            }

            if (current)
            {
                Passenger canceledPassenger = current->data;
                if (prev)
                {
                    prev->next = current->next;
                }
                else
                {
                    passengerList.setHead(current->next);
                }

                delete current;
                passengerList.decreaseSize();

                cout << "Ticket for Passenger with Passport Number " << passportNumber << " canceled successfully!\n";
                canceledPassenger.displayInformation();

                if (strcmp(canceledPassenger.getSpecialService(), "") != 0)
                {
                    cout << "Passenger has a special service: " << canceledPassenger.getSpecialService() << endl;
                }
                else
                {
                    cout << "Passenger does not have a special service.\n";
                }
            }
            else
            {
                cout << "Ticket not found for Passport Number " << passportNumber << ".\n";
            }
            break;
        }
        case 7: {
            char name[50], passportNumber[20];
            cout << "Enter Passenger Name: ";
            cin.ignore();
            cin.getline(name, sizeof(name));
            cout << "Enter Passport Number: ";
            cin >> passportNumber;

            Passenger passenger(name, passportNumber);

            int specialServiceOption;
            cout << "Does the passenger have a special service?\n1. Yes\n2. No\nEnter your choice: ";
            cin >> specialServiceOption;

            if (specialServiceOption == 1)
            {
                char service[50];
                cout << "Enter Special Service: ";
                cin.ignore();
                cin.getline(service, sizeof(service));
                passenger.setSpecialService(service);
            }

            passengerList.insertion_end(passenger);

            cout << "Ticket booked successfully!" << endl;
            break;
        }

        case 8:
        {
            // Check Airport List
            if (boardingQueue.isEmpty())
            {
                cout << "No airports available.\n";
            }
            else
            {
                cout << "Airport List:\n";
                while (!boardingQueue.isEmpty())
                {
                    Airport currentAirport = boardingQueue.dequeue();
                    currentAirport.displayInformation();
                }
            }
            break;
        }
      
        case 9:
        {
            cout << "Exiting the program.\n";
            break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }
        }
    } while (choice != 9);
    return 0;
}
    
