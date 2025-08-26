#include "RentalSystem.h"
#include <iostream>
#include <fstream>
using namespace std;

void print_menu() {
    cout << "**************** Main Menu ****************\n";
    cout << "1) Load file for Cars\n";
    cout << "2) Load file for Customers\n";
    cout << "3) Add a new car\n";
    cout << "4) Add a new customer\n";
    cout << "5) Rent a car\n";
    cout << "6) Return a car\n";
    cout << "7) View all available cars\n";
    cout << "8) View all customers\n";
    cout << "9) View rental history\n";
    cout << "10) Save to file (All rental history)\n";
    cout << "11) Exit\n";
    cout << "*******************************************\n";
    cout << "Please Enter Your Choice: ";
}

int main() {
    RentalSystem system;
    int choice;

    while (true) {
        print_menu();
        cin >> choice;

        if (choice == 1) {
            string filename;
            cout << "Enter car file name: ";
            cin >> filename;
            ifstream file(filename);
            string id, brand, model, fuel;
            int year;
            double rate, battery, tank;
            while (file >> id >> brand >> model >> year >> rate >> fuel >> battery >> tank) {
                Car* car = new Car(id, brand, model, year, rate, fuel, battery, tank);
                system.add_car(car);
            }
            file.close();
            cout << "Cars loaded successfully.\n";

        }
        else if (choice == 2) {
            string filename;
            cout << "Enter customer file name: ";
            cin >> filename;
            ifstream file(filename);
            string id, name, phone;
            while (file >> id >> name >> phone) {
                Customer* customer = new Customer(id, name, phone);
                system.add_customer(customer);
            }
            file.close();
            cout << "Customers loaded successfully.\n";

        }
        else if (choice == 3) {
            string id, brand, model, fuel;
            int year;
            double rate, battery = 0.0, tank = 0.0;
            cout << "Enter car ID, brand, model, year, rate, fuel type: ";
            cin >> id >> brand >> model >> year >> rate >> fuel;
            if (fuel == "electric") {
                cout << "Enter battery capacity: ";
                cin >> battery;
            }
            else {
                cout << "Enter fuel tank capacity: ";
                cin >> tank;
            }
            Car* car = new Car(id, brand, model, year, rate, fuel, battery, tank);
            system.add_car(car);
            cout << "Car added successfully.\n";

        }
        else if (choice == 4) {
            string id, name, phone;
            cout << "Enter customer ID, name, phone number: ";
            cin >> id >> name >> phone;
            Customer* customer = new Customer(id, name, phone);
            system.add_customer(customer);
            cout << "Customer added successfully.\n";

        }
        else if (choice == 5) {
            string customer_id, car_id;
            int days;
            cout << "Enter customer ID, car ID, rental days: ";
            cin >> customer_id >> car_id >> days;
            system.rent_car_to_customer(customer_id, car_id, days);

        }
        else if (choice == 6) {
            string customer_id;
            cout << "Enter customer ID to return car: ";
            cin >> customer_id;
            system.return_car_from_customer(customer_id);

        }
        else if (choice == 7) {
            system.list_available_cars();

        }
        else if (choice == 8) {
            system.list_all_customers();

        }
        else if (choice == 9) {
            system.view_rental_history();

        }
        else if (choice == 10) {
            string filename;
            cout << "Enter filename to save rental history: ";
            cin >> filename;
            system.save_rental_history_to_file(filename);
            cout << "Rental history saved.\n";

        }
        else if (choice == 11) {
            cout << "Exiting program. Goodbye!\n";
            break;

        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;
    }

    return 0;
}
