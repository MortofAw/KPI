#pragma once
#include "core/PlantProfile.h"
#include <QVector>

class ProfileRepository {
public:
    static ProfileRepository& instance();
    bool init();
    QVector<PlantProfile> loadAll() const;
    void save(const PlantProfile& profile);
    void update(const PlantProfile& profile);
    void remove(int id);
    PlantProfile getById(int id) const;

    // Додаємо публічний конструктор і деструктор — це ВАЖЛИВО для MSVC
    ProfileRepository() = default;
    ~ProfileRepository() = default;

private:
    ProfileRepository(const ProfileRepository&) = delete;
    ProfileRepository& operator=(const ProfileRepository&) = delete;
};
