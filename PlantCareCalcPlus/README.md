# PlantCareCalcPlus — Догляд за рослинами з урахуванням середовища

Десктопний додаток (C++17 + Qt 6 + SQLite) для розрахунку оптимального поливу, добрив та попереджень на основі температури, вологості та освітлення.

## Структура проєкту 

PlantCareCalcPlus/
├── CMakeLists.txt
├── main.cpp
├── README.md
├── .gitignore
├── src/
│   ├── core/
│   │   ├── CareCalculator.h
│   │   ├── CareCalculator.cpp
│   │   ├── PlantProfile.h
│   │   └── PlantProfile.cpp
│   ├── storage/
│   │   ├── ProfileRepository.h
│   │   └── ProfileRepository.cpp
│   └── ui/
│       ├── MainWindow.h
│       ├── MainWindow.cpp
│       └── MainWindow.ui
└── resources/

## Вимоги
- Qt 6+
- CMake 3.16+
- SQLite (вбудовано в Qt)

## Збірка (Windows)
1. `mkdir build && cd build`
2. `cmake ..`
3. `cmake --build .`

## Kanban-дошка
[Посилання на GitHub Projects](https://github.com/users/MortofAw/projects/3)

