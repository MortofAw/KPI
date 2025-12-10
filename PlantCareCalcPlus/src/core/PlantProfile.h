#pragma once
#include <QString>
#include <QDate>
#include <QList>
#include "core/CareCalculator.h"

class PlantProfile {
public:
    int id = 0;
    QString name;
    QString type;
    double potVolume = 1.0;
    Environment env;
    QString soilType = "Стандартний";
    double baseWater = 100.0;
    double baseFrequency = 2.0;

    QList<QDate> wateringHistory;

    double getK() const { return CareCalculator::calculateK(env); }
    double getRecommendedWater() const;
    double getRecommendedFrequency() const;
    QString getWarning() const { return CareCalculator::getWarning(env); }
};