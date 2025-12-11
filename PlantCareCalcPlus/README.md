# PlantCareCalc+  
**Інтелектуальний калькулятор догляду за кімнатними рослинами**

Десктопний додаток на C++17 + Qt 6 + SQLite, який розраховує оптимальний полив, частоту підживлення та видає попередження про ризик пересушення/переливу з урахуванням:

- типу рослини  
- об’єму горщика  
- температури, вологості та освітлення  
- типу ґрунту  

**Лабораторна робота №3**  
дисципліна «Технології та інструменти розробки програмного забезпечення»  
студент групи КВ-34 — Фесенко Денис  
КПІ ім. Ігоря Сікорського, 2025

## Структура проєкту

```text
PlantCareCalcPlus/
├── CMakeLists.txt
├── main.cpp
├── README.md
├── .gitignore
├── src/
│   ├── core/
│   │   ├── CareCalculator.h / .cpp
│   │   └── PlantProfile.h / .cpp
│   ├── storage/
│   │   ├── ProfileRepository.h / .cpp
│   └── ui/
│       ├── MainWindow.h / .cpp
│       └── MainWindow.ui
└── build/                  (створюється при збірці)

Функціонал MVP (реалізовано)

Створення, редагування, видалення профілів рослин
Розрахунок за формулою:
K = (T/25) × (100−H)/100 × (L/12)
Автоматичне коригування за типом ґрунту
Попередження про пересушення (T > 28°C і H < 40%)
Збереження історії поливів
Локальна база даних SQLite (файл у %AppData%)

Технології

C++17
Qt 6 (Widgets + Sql)
CMake ≥ 3.16
Git + GitHub Flow
GitHub Projects (Kanban)
Pull Requests + Code Review

Збірка (Windows)

git clone https://github.com/MortofAw/KPI.git
cd KPI/PlantCareCalcPlus
mkdir build && cd build
cmake ..
cmake --build . --config Release

Виконуваний файл: build\Release\PlantCareCalcPlus.exe

Kanban-дошка
https://github.com/users/MortofAw/projects/3/views/1

тимчасово :
+ тест CI