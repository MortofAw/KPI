#pragma once
#include <QMainWindow>
#include "core/PlantProfile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calculateButton_clicked();
    void on_saveButton_clicked();
    void on_deleteButton_clicked();
    void on_profileList_currentRowChanged(int row);

private:
    Ui::MainWindow *ui;
    QVector<PlantProfile> profiles;

    void refreshProfileList();
    void fillFormFromProfile(const PlantProfile& p);
    PlantProfile currentProfileFromForm() const;
};
