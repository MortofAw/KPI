cmake_minimum_required(VERSION 3.16)
project(PlantCareCalcPlus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Widgets Sql REQUIRED)

add_executable(PlantCareCalcPlus
    main.cpp
    src/ui/MainWindow.cpp
    src/ui/MainWindow.ui
    src/core/CareCalculator.cpp
    src/core/PlantProfile.cpp
    src/storage/ProfileRepository.cpp
)

target_include_directories(PlantCareCalcPlus PRIVATE src)

target_link_libraries(PlantCareCalcPlus Qt6::Core Qt6::Widgets Qt6::Sql)