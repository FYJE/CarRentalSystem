#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string id, string n, string phone)
    : customer_id(id), name(n), phone_number(phone),
    rented_car(nullptr), rental_days(0), customerNext(nullptr) {
}

void Customer::display_customer_info() {
    cout << "Customer ID: " << customer_id << "\nName: " << name
        << "\nPhone: " << phone_number << endl;
    if (rented_car != nullptr) {
        cout << "Currently Renting: " << rented_car->get_info()
            << " for " << rental_days << " days" << endl;
    }
    else {
        cout << "No car currently rented." << endl;
    }
}

bool Customer::rent_car(Car* car, int days) {
    if (rented_car != nullptr || !car->is_available()) {
        return false;
    }
    rented_car = car;
    rental_days = days;
    car->mark_rented();
    return true;
}

bool Customer::return_car() {
    if (rented_car == nullptr) {
        return false;
    }
    rented_car->mark_returned();
    rented_car = nullptr;
    rental_days = 0;
    return true;
}

string Customer::get_id() const {
    return customer_id;
}

Car* Customer::get_rented_car() const {
    return rented_car;
}

Customer* Customer::get_next() const {
    return customerNext;
}

void Customer::set_next(Customer* next) {
    customerNext = next;
}

string Customer::get_name() const {
    return name;
}

int Customer::get_rental_days() const {
    return rental_days;
}
