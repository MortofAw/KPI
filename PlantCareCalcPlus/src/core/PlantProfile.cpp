#include "core/PlantProfile.h"

double soilFactor(const QString& soil)
{
    if (soil == "Добре дренований") return 1.2;
    if (soil == "Вологий") return 0.8;
    return 1.0;
}

double PlantProfile::getRecommendedWater() const
{
    return CareCalculator::calculateWater(baseWater, potVolume, getK(), soilFactor(soilType));
}

double PlantProfile::getRecommendedFrequency() const
{
    return CareCalculator::calculateFrequency(baseFrequency, getK(), soilFactor(soilType));
}