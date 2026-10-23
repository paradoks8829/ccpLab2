#include "lab2.h"

int main() {
  setlocale(LC_ALL, "Russian");

  std::cout << "Выбери номер задачи:" << std::endl;
  // std::cout << "1 - task1_6()" << std::endl;
  std::cout << "2 - task2_4()" << std::endl;
  std::cout << "3 - task3_9()" << std::endl;
  std::cout << "4 - task4_3()" << std::endl;
  std::cout << "5 - task5_5()" << std::endl;
  std::cout << "6 - task6_14()" << std::endl;
  std::cout << "7 - task7_11()" << std::endl;
  std::cout << "8 - task8_1()" << std::endl;
  std::cout << "9 - task9_1()" << std::endl;
  std::cout << "10 - task10_2()" << std::endl;
  std::cout << "Твой выбор: ";

  int number = 0;
  std::cin >> number;

  switch (number) {
    case 2: {
      task2_4();
      break;
    }
    case 3: {
      task3_9();
      break;
    }
    case 4: {
      task4_3();
      break;
    }
    case 5: {
      task5_5();
      break;
    }
    case 6: {
      task6_14();
      break;
    }
    case 7: {
      task7_11();
      break;
    }
    case 8: {
      task8_1();
      break;
    }
    case 9: {
      task9_1();
      break;
    }
    case 10: {
      task10_2();
      break;
    }
    default:
      std::cout << "Неверный номер задачи" << std::endl;
      break;
  }

  return 0;
}