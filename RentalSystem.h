#pragma once
#include "Car.h"
#include "Customer.h"
#include "RentalRecord.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

class RentalSystem {
private:
    Car* carHead;
    Customer* customerHead;
    RentalRecord* recordHead;

    Car* find_car_by_id(const string& id);
    Customer* find_customer_by_id(const string& id);
    bool customer_has_rented(const string& customer_id);

public:
    RentalSystem();

    void add_car(Car* car);
    void add_customer(Customer* customer);
    void rent_car_to_customer(const string& customer_id, const string& car_id, int rental_days);
    void return_car_from_customer(const string& customer_id);
    void list_available_cars();
    void list_all_customers();
    double calculate_rental_price(Car* car, int days);
    void view_rental_history();
    void save_rental_history_to_file(const string& filename);
};
