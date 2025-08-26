#include "RentalRecord.h"
using namespace std;

RentalRecord::RentalRecord(string cname, string cinfo, int days, double cost)
    : customer_name(cname), car_info(cinfo), rental_days(days),
    total_cost(cost), recordNext(nullptr) {
}

string RentalRecord::get_record() const {
    return "Customer: " + customer_name + ", Car: " + car_info +
        ", Days: " + to_string(rental_days) +
        ", Total Cost: " + to_string(total_cost);
}

RentalRecord* RentalRecord::get_next() const {
    return recordNext;
}

void RentalRecord::set_next(RentalRecord* next) {
    recordNext = next;
}
