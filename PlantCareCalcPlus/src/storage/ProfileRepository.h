#pragma once

#include "core/PlantProfile.h"
#include <QVector>

class ProfileRepository
{
public:
    static ProfileRepository& instance();

    // Ініціалізація БД (викликати один раз при старті програми)
    bool init();

    // CRUD-операції
    QVector<PlantProfile> loadAll() const;
    void save(const PlantProfile& profile);
    void update(const PlantProfile& profile);
    void remove(int id);

    // Допоміжний метод — отримання профілю за id (зручно для редагування)
    PlantProfile getById(int id) const;

private:
    ProfileRepository() = default;
    ~ProfileRepository() = default;

    // Забороняємо копіювання та присвоєння (singleton)
    ProfileRepository(const ProfileRepository&) = delete;
    ProfileRepository& operator=(const ProfileRepository&) = delete;
};