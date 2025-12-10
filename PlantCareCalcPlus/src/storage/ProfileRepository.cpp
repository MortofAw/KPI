#include "storage/ProfileRepository.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>

ProfileRepository& ProfileRepository::instance()
{
    static ProfileRepository inst;
    return inst;
}

bool ProfileRepository::init()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(path);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path + "/plantcare.db");

    if (!db.open()) {
        qWarning() << "DB open failed:" << db.lastError().text();
        return false;
    }

    QSqlQuery q(db);
    bool ok = q.exec(R"(
        CREATE TABLE IF NOT EXISTS profiles (
            id              INTEGER PRIMARY KEY AUTOINCREMENT,
            name            TEXT NOT NULL,
            type            TEXT,
            potVolume       REAL,
            temperature     REAL,
            humidity        REAL,
            lightHours      INTEGER,
            soilType        TEXT,
            baseWater       REAL,
            baseFrequency   REAL,
            history         TEXT
        )
    )");

    if (!ok) qWarning() << "Table create failed:" << q.lastError().text();
    return ok;
}

QVector<PlantProfile> ProfileRepository::loadAll() const
{
    QVector<PlantProfile> list;
    QSqlQuery q("SELECT * FROM profiles ORDER BY name");
    while (q.next()) {
        PlantProfile p;
        p.id               = q.value("id").toInt();
        p.name             = q.value("name").toString();
        p.type             = q.value("type").toString();
        p.potVolume        = q.value("potVolume").toDouble();
        p.env.temperature   = q.value("temperature").toDouble();
        p.env.humidity     = q.value("humidity").toDouble();
        p.env.lightHours   = q.value("lightHours").toInt();
        p.soilType         = q.value("soilType").toString();
        p.baseWater        = q.value("baseWater").toDouble();
        p.baseFrequency    = q.value("baseFrequency").toDouble();

        QStringList dates = q.value("history").toString().split(';', Qt::SkipEmptyParts);
        for (const QString& d : dates) {
            QDate date = QDate::fromString(d, "yyyy-MM-dd");
            if (date.isValid()) p.wateringHistory.append(date);
        }
        list.append(p);
    }
    return list;
}

void ProfileRepository::save(const PlantProfile& p)
{
    QSqlQuery q;
 q.prepare(R"(
     INSERT INTO profiles
     (name,type,potVolume,temperature,humidity,lightHours,soilType,baseWater,baseFrequency,history)
     VALUES (?,?,?,?,?,?,?,?,?,?)
 )");

 QStringList dates;
 for (const QDate& d : p.wateringHistory)
     dates << d.toString("yyyy-MM-dd");

 q.addBindValue(p.name);
 q.addBindValue(p.type);
 q.addBindValue(p.potVolume);
 q.addBindValue(p.env.temperature);
 q.addBindValue(p.env.humidity);
 q.addBindValue(p.env.lightHours);
 q.addBindValue(p.soilType);
 q.addBindValue(p.baseWater);
 q.addBindValue(p.baseFrequency);
 q.addBindValue(dates.join(";"));

 if (!q.exec())
     qWarning() << "Save failed:" << q.lastError().text();
}

void ProfileRepository::update(const PlantProfile& p)
{
    // для MVP можна залишити порожнім або скопіювати логіку save + WHERE id=?
    // або просто викликати remove + save — працює для лабораторної
    remove(p.id);
    save(p);
}

void ProfileRepository::remove(int id)
{
    QSqlQuery q;
    q.prepare("DELETE FROM profiles WHERE id = ?");
    q.addBindValue(id);
    q.exec();
}

PlantProfile ProfileRepository::getById(int id) const
{
    PlantProfile p;
    QSqlQuery q;
    q.prepare("SELECT * FROM profiles WHERE id = ?");
    q.addBindValue(id);
    if (q.exec() && q.next()) {
        // заповнення як у loadAll() — можна скопіювати
        p.id = q.value(0).toInt();
        // ... інші поля
    }
    return p;
}