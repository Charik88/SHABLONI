//
//  main.cpp
//  work_1
//
//  Created by Anastasiya Charykova on 19.09.2024.
/* Задача 1. Возведение в квадрат
 Описание

 Нужно реализовать шаблонную функцию возведения в квадрат, которая работает не только с простыми числами, но и с векторами. Для этого создайте две реализации шаблонной функции.
 
 
 Пример правильной работы программы

 [IN]: 4
 [OUT]: 16
 [IN]: -1, 4, 8
 [OUT]: 1, 16, 64

*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

// шаблонная функция для возведения в квадрат

template <typename T>
T square (T value){
    return value * value;
}

template <typename T>
std::vector <T> square (const std::vector<T>& vec){
    std::vector<T> result;
    for (const auto& value : vec){
        result.push_back(square(value));
}
return result;
}

int main(){
    int inputNumber;
    std::cout << "[IN]: ";
    std::cin >> inputNumber;
    std::cout << "[OUT]: "<< square(inputNumber) << std::endl;
    
    
    std::string inputVector;
    std::cout << "[IN]: ";
    std::cin.ignore();
    std::getline(std::cin, inputVector);
    
    std::vector<int>numbers;
    std::stringstream ss(inputVector);
    std::string item;
    
    while (std::getline(ss, item, ',')){
        numbers.push_back(std::stoi(item));
    }
    
    std::vector<int> squaredNumbers = square(numbers);
    
    std::cout << "[OUT]: ";
    for (size_t i = 0; i < squaredNumbers.size(); ++i) {
            std::cout << squaredNumbers[i];
            if (i < squaredNumbers.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;

        return 0;
    }
    
    

