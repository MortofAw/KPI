#pragma once
#include <QString>

struct Environment {
    double temperature = 20.0;
    double humidity = 50.0;
    int lightHours = 12;
};

class CareCalculator {
public:
    static double calculateK(const Environment& env);
    static double calculateWater(double baseWater, double potVolume, double k, double soilFactor = 1.0);
    static double calculateFrequency(double baseFreq, double k, double soilFactor = 1.0);
    static QString getWarning(const Environment& env);
};