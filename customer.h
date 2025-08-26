#pragma once
#include <string>
#include "Car.h"
using namespace std;

class Customer {
private:
    string customer_id;
    string name;
    string phone_number;
    Car* rented_car;
    int rental_days;
    Customer* customerNext;

public:
    Customer(string id, string n, string phone);

    void display_customer_info();
    bool rent_car(Car* car, int days);
    bool return_car();

    
    string get_id() const;
    Car* get_rented_car() const;
    Customer* get_next() const;
    string get_name() const;
    int get_rental_days() const;

    
    void set_next(Customer* next);
};
