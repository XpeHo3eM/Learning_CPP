#include <fstream>
#include <iostream>

int main() {
  std::cout << "Enter path to file: ";
  std::string path;
  std::cin >> path;

  std::ifstream file;
  file.open(path, std::ios::binary);
  if (file.is_open()) {
    // Создаем буферную переменную
    char temp[11];

    // Запоминаем размер буфера с учетом записи 0 в конец
    int sizeForRead = sizeof(temp) - 1;

    // Ставим указатель на последний байт и запоминаем оставшееся количество
    file.seekg(0, std::ios::end);
    int sizeLeft = file.tellg();

    // Ставим указатель обратно на начало
    file.seekg(0, std::ios::beg);

    while (sizeLeft > sizeForRead) {
      file.read(temp, sizeForRead);

      // Записываем в конец буфера 0 как окончание буфера
      temp[sizeForRead] = 0;
      std::cout << temp;
      sizeLeft -= sizeForRead;
    }

    // Когда осталось байт меньше буфера - записываем остатки
    file.read(temp, sizeLeft);
    temp[sizeLeft] = 0;
    std::cout << temp;

    file.close();
  } else
    std::cout << "File not found" << std::endl;

  std::cout << std::endl;
}
