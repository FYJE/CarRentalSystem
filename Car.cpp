#include "Car.h"
#include <iostream>
using namespace std;

Car::Car(string id, string b, string m, int y, double rate, string fuel,
    double battery, double tank)
    : car_id(id), brand(b), model(m), year(y), rental_rate_per_day(rate),
    available(true), fuel_type(fuel), battery_capacity(battery),
    fuel_tank_capacity(tank), carNext(nullptr) {
}

void Car::display_details() {
    cout << "Car ID: " << car_id << "\nBrand: " << brand << "\nModel: " << model
        << "\nYear: " << year << "\nRate per Day: " << rental_rate_per_day
        << "\nFuel Type: " << fuel_type << "\nAvailability: "
        << (available ? "Available" : "Rented") << endl;
    display_fuel_info();
}

void Car::display_fuel_info() {
    if (fuel_type == "electric") {
        cout << "Battery Capacity: " << battery_capacity << " kWh" << endl;
    }
    else {
        cout << "Fuel Tank Capacity: " << fuel_tank_capacity << " liters" << endl;
    }
}

void Car::mark_rented() {
    available = false;
}

void Car::mark_returned() {
    available = true;
}

string Car::get_id() const {
    return car_id;
}

bool Car::is_available() const {
    return available;
}

double Car::get_rate() const {
    return rental_rate_per_day;
}

string Car::get_info() const {
    return brand + " " + model + " (" + car_id + ")";
}

Car* Car::get_next() const {
    return carNext;
}

void Car::set_next(Car* next) {
    carNext = next;
}
