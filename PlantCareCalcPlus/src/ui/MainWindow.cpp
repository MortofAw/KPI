#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , repository("profiles.json") // Вказуємо файл для збереження профілів
{
    ui->setupUi(this);

    // Підключаємо кнопки до слотів
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddProfileClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteProfileClicked);
    connect(ui->profileList, &QListWidget::currentRowChanged, this, &MainWindow::onProfileSelected);

    loadProfilesToList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

PlantProfile MainWindow::currentProfileFromForm()
{
    PlantProfile p;
    p.name = ui->nameEdit->text().toStdString();
    p.type = ui->typeBox->currentText().toStdString();
    p.soilType = ui->soilBox->currentText().toStdString();
    p.env.waterPerWeek = ui->waterSpin->value();
    p.env.lightHours = ui->lightSpin->value();
    p.env.temperature = ui->tempSpin->value();
    p.env.humidity = ui->humiditySpin->value();
    p.potVolume = ui->potSpin->value();
    return p;
}

void MainWindow::loadProfilesToList()
{
    ui->profileList->clear();
    for (const auto& profile : repository.getAllProfiles()) {
        ui->profileList->addItem(QString::fromStdString(profile.name));
    }
}

void MainWindow::onAddProfileClicked()
{
    PlantProfile p = currentProfileFromForm();
    repository.addProfile(p);
    repository.save();
    loadProfilesToList();
}

void MainWindow::onDeleteProfileClicked()
{
    int index = ui->profileList->currentRow();
    if (index >= 0) {
        repository.removeProfile(index);
        repository.save();
        loadProfilesToList();
    } else {
        QMessageBox::warning(this, "Помилка", "Оберіть профіль для видалення");
    }
}

void MainWindow::onProfileSelected()
{
    int index = ui->profileList->currentRow();
    if (index >= 0) {
        PlantProfile p = repository.getProfile(index);
        ui->nameEdit->setText(QString::fromStdString(p.name));
        ui->typeBox->setCurrentText(QString::fromStdString(p.type));
        ui->soilBox->setCurrentText(QString::fromStdString(p.soilType));
        ui->waterSpin->setValue(p.env.waterPerWeek);
        ui->lightSpin->setValue(p.env.lightHours);
        ui->tempSpin->setValue(p.env.temperature);
        ui->humiditySpin->setValue(p.env.humidity);
        ui->potSpin->setValue(p.potVolume);
    }
}
