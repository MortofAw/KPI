#pragma once

#include <QMainWindow>
#include <QString>
#include "../storage/ProfileRepository.h"
#include "../core/PlantProfile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddProfileClicked();
    void onDeleteProfileClicked();
    void onProfileSelected();

private:
    Ui::MainWindow *ui;
    ProfileRepository repository;

    PlantProfile currentProfileFromForm();
    void loadProfilesToList();
};
