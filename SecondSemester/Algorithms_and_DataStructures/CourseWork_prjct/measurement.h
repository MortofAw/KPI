#ifndef __MEASUREMENT_H__
#define __MEASUREMENT_H__

#include <time.h>

// загальна кількість вимірів часу роботи алгоритма
#define measurements_number 28

// кількість відкинутих початкових вимірів
#define rejected_number 2

// кількість відкинутих вимірів з мінімільними та максимальними значеннями
#define min_max_number 3

// масив значень часу роботи алгоритма
extern clock_t  Res[measurements_number];

// функція обробки і усереднення значень вимірів часу роботи алгоритма. Повертає усереднене значення часу роботи алгоритма.
float MeasurementProcessing();

// експорт функцій для виконання вимірів часу для масивів
void select2_measurement (char fillMethod);
void select7_measurement (char fillMethod);
void exchange2_measurement (char fillMethod);

// експорт функцій для виконання вимірів часу для векторів
void Select2_measurement (char fillMethod);
void Select7_measurement (char fillMethod);
void Exchange2_measurement (char fillMethod);

#endif // __MEASUREMENT_H__
