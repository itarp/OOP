#include <iostream>
#include <cstdint>
#include <cmath>

// Задание 1. Класс Power ------------------------------------------------------
class Power {
 private:
  double base_;
  double degree_;
 public:
  Power() {base_ = 0; degree_ = 0;}
  void set(double base, double degree) {base_ = base; degree_ = degree;}
  double calculate();
  
};

double Power::calculate() {
  return pow(base_, degree_);
}

// Задание 2. Класс RGBA -----------------------------------------------------
class RGBA {
 private:
  std::uint8_t m_red;
  std::uint8_t m_green;
  std::uint8_t m_blue;
  std::uint8_t m_alpha;
 public:
  RGBA() {m_red = m_green = m_blue = 0; m_alpha = 255;}
  RGBA(std::uint8_t  red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) {
    m_red = red;
    m_green = green;
    m_blue = blue;
    m_alpha = alpha;}
  void print();
};

void RGBA::print() {
  std::cout << "red:   " << (int)m_red << std::endl;
  std::cout << "green: " << (int)m_green << std::endl;
  std::cout << "blue:  " << (int)m_blue << std::endl;  
  std::cout << "alpha: " << (int)m_alpha << std::endl;  
}

// Задание 3. Класс Stack --------------------------------------------------
class Stack {
 private:
  static const size_t maxSize = 10;
  int ar[maxSize];
  size_t size;
 public:
  Stack() {size = 0;}
  void reset();
  bool push(int num);
  int pop();
  void print();
};

void Stack::reset() {
  for(int i = 0; i < maxSize; i++)
    ar[i] = 0;
  size = 0;
}

bool Stack::push(int num) {
  if(size >= maxSize)
    return false;
  ar[size] = num;
  size++;
  return true;
}

int Stack::pop() {
  if(size <= 0){
    std::cout << "Cтек пуст" << std::endl;
    return 0;
  }
  ar[--size];
  return 0;
}

void Stack::print() {
  std::cout << "( ";
  for(int i = 0; i < size; i++) 
    std::cout << ar[i] << ' ';
  std::cout << ')';    
  std::cout << std::endl;
}

// --------------------------  Старт программы -------------------------------
int main() {
  //Тест. Задание 1
  Power task1;
  
  task1.set(2.2, 3.3);
  std::cout << "== Задание 1. Класс Power ==" << std::endl;
  std::cout << task1.calculate() << std::endl << std::endl;

  //Тест. Задание 2  
  RGBA color;
  std::cout << "== Задание 2. Класс RGBA  ==" << std::endl;
  color.print();
  RGBA color2(25, 30 ,5 , 100);
  std::cout << std::endl;
  color2.print();
  std::cout << std::endl << std::endl;

  //Тест. Задание 3
  Stack stack;
  std::cout << "== Задание 3. Класс Stack ==" << std::endl;  
  stack.reset();
  stack.print();

  stack.push(3);
  stack.push(7);
  stack.push(5);
  stack.print();

  stack.pop();
  stack.print();

  stack.pop();
  stack.pop();
  stack.print();
  return 0;
}
