#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int packing() {
  char g;                     /*код стану*/
  char s;                     /*ознака помилки*/
  char p;                     /*ознака зайнятості*/
  unsigned int UnitStateWord; /*слово стану*/

  printf("Ідентифікатор групи, до якої належить користувач (0-255): ");
  scanf("%hhd", &g);
  printf("Код системи, яка завантажується для користувача (0-15): ");
  scanf("%hhd", &s);
  printf("Ознака привілейованого користувача (0/1):");
  scanf("%hhd", &p);

  // формування
  UnitStateWord = ((unsigned char)g & 0xFF) << 8; // FF-255=2^8
  UnitStateWord |= ((unsigned char)s & 0xF) << 4; // F-16=2^4
  UnitStateWord |= ((unsigned char)p & 1) << 3;

  // результат
  printf("\nСлово стану пристрою = %04x\n", UnitStateWord);
  return 0;
}

int unpacking() {
  unsigned char g;            /*код стану*/
  char s;                     /*ознака помилки*/
  char p;                     /*ознака зайнятості*/
  unsigned int UnitStateWord; /*уведення слова стану пристрою*/

  printf("Уведіть cлово стану пристрою\n");
  printf("(16-кове число від 0 до 0xFFFF): ");
  scanf("%x", &UnitStateWord);

  /*виділення складових частин*/
  g = (UnitStateWord >> 8) & 0xFF;
  s = (UnitStateWord >> 4) & 0x0F;
  p = (UnitStateWord >> 3) & 0x01;

  // результати
  putchar('\n');
  printf("Ідентифікатор групи, до якої належить користувач = %d\n", g);
  printf("Код системи, яка завантажується для користувача = %d\n", s);
  printf("Ознака привілейованого користувача = %d\n", p);
  return 0;
}

float volume_prism(float a, float b, float h) { return 0.5 * a * b * h; }

void fx(float b) {
  for (int i = 1; i <= 5; i++) {
    printf("f(%d) = %.4f\n", i, (i * i + b));
  }
}

float input_number() {
  float number;
  while (scanf("%f", &number) != 1) {
    printf("Помилка! Будь ласка, введіть правильне число: ");
    while (getchar() != '\n')
      ;
  }
  return number;
}

int input_integer() {
  int number;
  while (scanf("%d", &number) != 1) {
    printf("Помилка! Будь ласка, введіть ціле число: ");
    while (getchar() != '\n')
      ;
  }
  return number;
}

void firstTaskMenu() {
  int subtask;
  printf("\nВиберіть підзавдання (1 або 2): ");
  scanf("%d", &subtask);

  if (subtask == 1) {
    float a, b, h;

    printf("Введіть катет a: ");
    a = input_number();

    printf("Введіть катет b: ");
    b = input_number();

    printf("Введіть висоту призми h: ");
    h = input_number();

    printf("Об'єм призми: %.2f\n", volume_prism(a, b, h));

  } else if (subtask == 2) {
    float b;

    printf("Введіть параметр b: ");
    b = input_number();

    fx(b);
  } else {
    printf("Некоректне введення підзавдання, спробуйте знов.\n");
  }
}

void secondTask() {
  int check;

  printf("\n1. Програма упакування.");
  printf("\n2. Програма розпакування.");

  printf("\nВиберіть підзавдання (1 або 2): ");
  check = input_integer();

  if (check == 1) {
    packing();
  } else if (check == 2) {
    unpacking();
  } else {
    printf("Некоректне введення, спробуйте знов.\n"); // повідомлення помилки
  }
}

int main() {

  printf("ЛАБОРАТОРНА РОБОТА №1\n");
  printf("Тема: Базові типи даних, уведення-виведення, бітові операції, "
         "операції зсуву.\n");
  printf("ВАРІАНТ 10\n");
  printf("Виконала студентка групи КМ-33 Гула Дарина.\n");

  printf("\n1. Обчислити об'єм прямої призми або обчислити f(x).");
  printf("\n2. Елемент профілю користувача.");

  int check;

  while (1) {

    printf("\nВиберіть завдання (1 або 2, або 3 для виходу з програми): ");
    check = input_integer();
    if (check == 3) {
      break;
    } else if (check == 1) {
      firstTaskMenu();
    } else if (check == 2) {
      secondTask();
    } else {
      printf("Некоректне введення, спробуйте знов.\n");
      continue;
    }
  }
  return 0;
}
