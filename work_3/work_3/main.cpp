//
//  main.cpp
//  work_3
//
//  Created by Anastasiya Charykova on 20.09.2024.
//

/*Задача 3. Счётчик чисел
Описание

В этом задании вам нужно реализовать функтор, который подсчитывает сумму и количество чисел, делящихся на 3.

Должны быть реализованы 2 функции:

    get_sum()
    get_count()

Пример правильной работы программы

[IN]: 4 1 3 6 25 54
[OUT]: get_sum() = 63
[OUT]: get_count() = 3
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

// Функтор для подсчета суммы и количества чисел, делящихся на 3
class DivisibleBy3Counter{
private:
int sum = 0; // инициализация суммы
int count = 0; // инициализация счетчика

public:

// ф-ия для подсчета суммы чисел, делящихся на 3
void operator()(int number) {
  if (number % 3 == 0) {
    sum += number;
    count++;
  }
}
// метод для получения суммы
int get_sum() const{
  return sum;
}
// метод для получения кол-ва чисел
int get_count() const{
  return count;
}
};

int main() {
  DivisibleBy3Counter counter; // создаем обьект класса DivisibleBy3Counter
  std::cout << "[IN]: ";
  std::vector<int> numbers;
  std::string line;
  
   // Считываем числа до нажатия Enter без ввода
  while (std::getline(std::cin, line) && !line.empty()) { // читаем строку из ввода
    std::istringstream iss(line); // создаем поток из строки
    int number;

     // Считываем каждое число из строки
    while (iss >> number) { // читаем число из потока
        numbers.push_back(number); // Добавляем введенное число в вектор
    }
    // Обрабатываем каждое число из вектора
    for (const auto& num : numbers) { // проходим по всем числам в векторе
        counter(num); // Вызываем функтор для текущего числа
    }
    
  std::cout << "[OUT]: " << counter.get_sum() << std::endl;
  std::cout << "[OUT]: " << counter.get_count() << std::endl;
  
  return 0;
}
}
