#pragma once
#include <string>
using namespace std;

class Car {
private:
    string car_id;
    string brand;
    string model;
    int year;
    double rental_rate_per_day;
    bool available;
    string fuel_type;
    double battery_capacity;
    double fuel_tank_capacity;
    Car* carNext;

    void display_fuel_info(); 

public:
    Car(string id, string b, string m, int y, double rate, string fuel,
        double battery = 0.0, double tank = 0.0);

    void display_details();
    void mark_rented();
    void mark_returned();

    
    string get_id() const;
    bool is_available() const;
    double get_rate() const;
    string get_info() const;
    Car* get_next() const;

    
    void set_next(Car* next);
};
