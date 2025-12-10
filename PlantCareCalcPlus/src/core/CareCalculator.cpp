#include "core/CareCalculator.h"
#include <QtMath>

double CareCalculator::calculateK(const Environment& env)
{
    return (env.temperature / 25.0) *
           ((100.0 - env.humidity) / 100.0) *
           (static_cast<double>(env.lightHours) / 12.0);
}

double CareCalculator::calculateWater(double baseWater, double potVolume, double k, double soilFactor)
{
    return baseWater * (potVolume / 1.0) * k * soilFactor; // 1 л — базовий горщик
}

double CareCalculator::calculateFrequency(double baseFreq, double k, double soilFactor)
{
    return baseFreq * k * soilFactor;
}

QString CareCalculator::getWarning(const Environment& env)
{
    if (env.temperature > 28.0 && env.humidity < 40.0)
        return "<span style='color:red'><b>Ризик пересушення!</b></span>";
    return "";
}