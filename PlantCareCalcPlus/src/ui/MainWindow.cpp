#include "ui/MainWindow.h"
#include "ui_mainwindow.h"
#include "storage/ProfileRepository.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->typeCombo->addItems({"Орхідея", "Кактус", "Фікус", "Інша"});
    ui->soilCombo->addItems({"Стандартний", "Добре дренований", "Вологий"});

    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::on_calculateButton_clicked);
    connect(ui->saveButton,    &QPushButton::clicked, this, &MainWindow::on_saveButton_clicked);
    connect(ui->deleteButton,  &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);
    connect(ui->profileList,   &QListWidget::currentRowChanged, this, &MainWindow::on_profileList_currentRowChanged);

    refreshProfileList();
}

MainWindow::~MainWindow() { delete ui; }

PlantProfile MainWindow::currentProfileFromForm() const
{
    PlantProfile p;
    p.name = ui->nameEdit->text();
    p.type = ui->typeCombo->currentText();
    p.potVolume = ui->potVolumeSpin->value();
    p.env.temperature = ui->temperatureSpin->value();
    p.env.humidity = ui->humiditySpin->value();
    p.env.lightHours = ui->lightHoursSpin->value();
    p.soilType = ui->soilCombo->currentText();

    if (p.type == "Орхідея") { p.baseWater = 80; p.baseFrequency = 2; }
    else if (p.type == "Кактус") { p.baseWater = 50; p.baseFrequency = 1; }
    else if (p.type == "Фікус") { p.baseWater = 100; p.baseFrequency = 3; }
    else { p.baseWater = 100; p.baseFrequency = 2; }

    return p;
}

void MainWindow::on_calculateButton_clicked()
{
    PlantProfile p = currentProfileFromForm();
    double k = p.getK();
    double water = p.getRecommendedWater();
    double freq = p.getRecommendedFrequency();

    QString text = QString(
        "<h3>Рекомендації для %1</h3>"
        "<b>Коефіцієнт K:</b> %2<br>"
        "<b>Води за раз:</b> %3 мл<br>"
        "<b>Частота:</b> %4 разів/тиждень<br><br>"
        "%5")
        .arg(p.name.isEmpty() ? "рослини" : p.name)
        .arg(k, 0, 'f', 2)
        .arg(qRound(water))
        .arg(freq, 0, 'f', 1)
        .arg(p.getWarning());

    ui->resultLabel->setText(text);
}

void MainWindow::refreshProfileList()
{
    profiles = ProfileRepository::instance().loadAll();
    ui->profileList->clear();
    for (const auto& p : profiles)
        ui->profileList->addItem(p.name.isEmpty() ? "Без назви" : p.name);
}

void MainWindow::on_saveButton_clicked()
{
    PlantProfile p = currentProfileFromForm();
    if (p.name.isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Введіть назву");
        return;
    }
    ProfileRepository::instance().save(p);
    refreshProfileList();
    QMessageBox::information(this, "Готово", "Профіль збережено");
}

void MainWindow::on_deleteButton_clicked()
{
    int row = ui->profileList->currentRow();
    if (row >= 0) {
        ProfileRepository::instance().remove(profiles[row].id);
        refreshProfileList();
    }
}

void MainWindow::on_profileList_currentRowChanged(int row)
{
    if (row >= 0 && row < profiles.size())
        fillFormFromProfile(profiles[row]);
}

void MainWindow::fillFormFromProfile(const PlantProfile& p)
{
    ui->nameEdit->setText(p.name);
    ui->typeCombo->setCurrentText(p.type);
    ui->potVolumeSpin->setValue(p.potVolume);
    ui->temperatureSpin->setValue(p.env.temperature);
    ui->humiditySpin->setValue(p.env.humidity);
    ui->lightHoursSpin->setValue(p.env.lightHours);
    ui->soilCombo->setCurrentText(p.soilType);
}
