#include <iostream>
#include "vec.h"

void output(Vec &, std::string);

int main() {
  Vec vec{10};
  Vec vec2;
  Vec vec3 = vec2;

  system("cls");
  output(vec, "vec");
  std::cout << std::endl;
  output(vec2, "vec2");
  std::cout << std::endl;
  output(vec3, "vec3");
}

void output(Vec &vec, std::string name) {
  std::cout << "Your vector " << name << " has " << vec.getSize()
            << " dimensions" << std::endl;
  std::cout << "Vector's coordinates: (";
  for (int i = 0; i < vec.getSize(); ++i) {
    std::cout << vec.getCoord(i);
    if (i + 1 != vec.getSize()) std::cout << ", ";
  }
  std::cout << ')' << std::endl;

  std::cout << "Normalize of your vector: " << vec.norm() << std::endl;
}