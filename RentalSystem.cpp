#include "RentalSystem.h"
using namespace std;

RentalSystem::RentalSystem()
    : carHead(nullptr), customerHead(nullptr), recordHead(nullptr) {
}

void RentalSystem::add_car(Car* car) {
    car->set_next(carHead);
    carHead = car;
}

void RentalSystem::add_customer(Customer* customer) {
    customer->set_next(customerHead);
    customerHead = customer;
}

Car* RentalSystem::find_car_by_id(const string& id) {
    Car* current = carHead;
    while (current != nullptr) {
        if (current->get_id() == id) return current;
        current = current->get_next();
    }
    return nullptr;
}

Customer* RentalSystem::find_customer_by_id(const string& id) {
    Customer* current = customerHead;
    while (current != nullptr) {
        if (current->get_id() == id) return current;
        current = current->get_next();
    }
    return nullptr;
}

bool RentalSystem::customer_has_rented(const string& customer_id) {
    Customer* customer = find_customer_by_id(customer_id);
    return customer && customer->get_rented_car() != nullptr;
}

void RentalSystem::rent_car_to_customer(const string& customer_id, const string& car_id, int rental_days) {
    Customer* customer = find_customer_by_id(customer_id);
    Car* car = find_car_by_id(car_id);

    if (customer && car && car->is_available() && !customer_has_rented(customer_id)) {
        if (customer->rent_car(car, rental_days)) {
            double cost = calculate_rental_price(car, rental_days);
            RentalRecord* record = new RentalRecord(customer->get_name(), car->get_info(), rental_days, cost);
            record->set_next(recordHead);
            recordHead = record;
            cout << "Rental successful!" << endl;
        }
        else {
            cout << "Rental failed: car unavailable or customer already renting." << endl;
        }
    }
    else {
        cout << "Invalid rental request." << endl;
    }
}

void RentalSystem::return_car_from_customer(const string& customer_id) {
    Customer* customer = find_customer_by_id(customer_id);
    if (customer && customer->return_car()) {
        cout << "Car returned successfully." << endl;
    }
    else {
        cout << "Return failed: no car rented." << endl;
    }
}

void RentalSystem::list_available_cars() {
    Car* current = carHead;
    while (current != nullptr) {
        if (current->is_available()) {
            current->display_details();
            cout << "------------------------" << endl;
        }
        current = current->get_next();
    }
}

void RentalSystem::list_all_customers() {
    Customer* current = customerHead;
    while (current != nullptr) {
        current->display_customer_info();
        cout << "------------------------" << endl;
        current = current->get_next();
    }
}

double RentalSystem::calculate_rental_price(Car* car, int days) {
    return car->get_rate() * days;
}

void RentalSystem::view_rental_history() {
    RentalRecord* current = recordHead;
    while (current != nullptr) {
        cout << current->get_record() << endl;
        current = current->get_next();
    }
}

void RentalSystem::save_rental_history_to_file(const string& filename) {
    ofstream file(filename);
    RentalRecord* current = recordHead;
    while (current != nullptr) {
        file << current->get_record() << endl;
        current = current->get_next();
    }
    file.close();
}
