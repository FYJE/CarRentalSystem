#pragma once
#include <string>
using namespace std;

class RentalRecord {
private:
    string customer_name;
    string car_info;
    int rental_days;
    double total_cost;
    RentalRecord* recordNext;

public:
    RentalRecord(string cname, string cinfo, int days, double cost);

    string get_record() const;
    RentalRecord* get_next() const;
    void set_next(RentalRecord* next);
};
