#include <iostream>
#include "classHeader.h"

int main(void)
{
    // Static obj
    Passprt staticPassport("Jane Doe", 28, "456 Elm St.");
    staticPassport.Print();

    // Dynamic obj
    Passprt* dynamicPassport = new Passprt("John Smith", 35, "789 Maple Ave.");
    dynamicPassport->Print();
    delete dynamicPassport;

    // Static array
    Passprt staticPassports[2] = {
        Passprt("Alice", 22, "101 Oak St."),
        Passprt("Bob", 25, "202 Pine St.")
    };
    staticPassports[0].Print();
    staticPassports[1].Print();

    // Dynamic array of objects
    Passprt* dynamicPassports = new Passprt[2];
    dynamicPassports[0].SetAll("Charlie", 27, "303 Cedar St.");
    dynamicPassports[1].SetAll("Dave", 29, "404 Birch St.");
    dynamicPassports[0].Print();
    dynamicPassports[1].Print();
    delete[] dynamicPassports;

    // Obj pointer
    Passprt* passportPtr = new Passprt("John Doe", 30, "123 Main St.");
    passportPtr->Print();
    delete passportPtr;

    // Method pointer
    Passprt passport("Eve", 31, "505 Spruce St.");
    void (Passprt:: * setNamePtr)(const char*) = &Passprt::SetName;
    (passport.*setNamePtr)("Eva Green");
    passport.Print();

	return 0;
}