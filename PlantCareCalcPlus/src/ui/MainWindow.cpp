#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "../core/PlantProfile.h"
#include "../core/ProfileRepository.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Завантажити профілі з файлу
    repository = new ProfileRepository("profiles.json");
    loadProfilesToList();

    connect(ui->addButton, &QPushButton::clicked,
            this, &MainWindow::onAddProfileClicked);

    connect(ui->deleteButton, &QPushButton::clicked,
            this, &MainWindow::onDeleteProfileClicked);

    connect(ui->profileList, &QListWidget::currentRowChanged,
            this, &MainWindow::onProfileSelected);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete repository;
}


// ===========================================================
//        Правильна функція, що повертає PlantProfile
// ===========================================================

PlantProfile MainWindow::currentProfileFromForm() const
{
    PlantProfile profile;
    profile.name = ui->nameEdit->text().toStdString();
    profile.type = ui->typeBox->currentText().toStdString();
    profile.waterPerWeek = ui->waterSpin->value();
    profile.lightHours = ui->lightSpin->value();
    return profile;
}


// ===========================================================
//                    UI → Repo → UI
// ===========================================================

void MainWindow::onAddProfileClicked()
{
    PlantProfile profile = currentProfileFromForm();   // ← ТУТ БУЛА ПОМИЛКА (без дужок)
    repository->addProfile(profile);
    repository->save();

    loadProfilesToList();
}

void MainWindow::onDeleteProfileClicked()
{
    int index = ui->profileList->currentRow();
    if (index < 0) return;

    repository->removeProfile(index);
    repository->save();

    loadProfilesToList();
}

void MainWindow::onProfileSelected(int index)
{
    if (index < 0 || index >= repository->profiles().size())
        return;

    const PlantProfile &p = repository->profiles()[index];

    ui->nameEdit->setText(QString::fromStdString(p.name));
    ui->typeBox->setCurrentText(QString::fromStdString(p.type));
    ui->waterSpin->setValue(p.waterPerWeek);
    ui->lightSpin->setValue(p.lightHours);
}


// ===========================================================
//              Заповнення списку у інтерфейсі
// ===========================================================

void MainWindow::loadProfilesToList()
{
    ui->profileList->clear();

    for (const PlantProfile &p : repository->profiles()) {
        ui->profileList->addItem(QString::fromStdString(p.name));
    }
}
