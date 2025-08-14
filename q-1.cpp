#include <iostream>
#include <string>
using namespace std;

class Train {
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;
    static int trainCount;

public:
    Train() {
        trainNumber = 0;
        trainName = "";
        source = "";
        destination = "";
        trainTime = "";
        trainCount++;
    }

    Train(int number, string name, string src, string dest, string time) {
        trainNumber = number;
        trainName = name;
        source = src;
        destination = dest;
        trainTime = time;
        trainCount++;
    }

    ~Train() {
        trainCount--;
    }

    void inputTrainDetails() {
        cout << "\nEnter Train Number: ";
        cin >> trainNumber;
        cin.ignore();
        cout << "Enter Train Name: ";
        getline(cin, trainName);
        cout << "Enter Source: ";
        getline(cin, source);
        cout << "Enter Destination: ";
        getline(cin, destination);
        cout << "Enter Train Time: ";
        getline(cin, trainTime);
    }

    void displayTrainDetails() const {
        cout << "\nTrain Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    int getTrainNumber() const {
        return trainNumber;
    }

    static int getTrainCount() {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwayStation {
private:
    Train trains[100];
    int totalTrains = 0;

public:
    void addTrain() {
        if (totalTrains < 100) {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
            cout << "Train added successfully!\n";
        } else {
            cout << "Train limit reached.\n";
        }
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "No train records available.\n";
            return;
        }
        for (int i = 0; i < totalTrains; i++) {
            trains[i].displayTrainDetails();
            cout << "-----------------------------\n";
        }
    }

    void searchTrain(int number) const {
        bool found = false;
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "Train Found:\n";
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Train Not Found!\n";
        }
    }
};

int main() {
    RailwayStation rs;
    int choice, num;

    do {
        cout << "\n---------- Railway Reservation System Menu ----------\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rs.addTrain();
                break;
            case 2:
                rs.displayAllTrains();
                break;
            case 3:
                cout << "Enter Train Number to Search: ";
                cin >> num;
                rs.searchTrain(num);
                break;
            case 4:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}