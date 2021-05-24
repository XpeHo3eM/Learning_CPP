#include <iostream>
#include <fstream>
#include <string>

// Проверка корректности расширения файла на *.png
bool fileExtension(const std::string &path)
{
    int pos = -1;
    int length = path.length();

    for (int i = 0; i < length; ++i)
        if (path[i] == '.')
            pos = i;

    // Переводим расширение в нижний регистр
    std::string extension = "";
    for (int i = pos + 1; i < length; ++i)
        extension += std::tolower(path[i]);

    return (extension == "png");
}

int main()
{
    std::cout << "Input path to file: ";
    std::string path;
    std::cin >> path;

    std::ifstream file;
    file.open(path, std::ios::binary);

    if (file.is_open())
    {
        // Необходима проверка первых 4 байт на корректность png
        char tmp[4];
        file.read(tmp, sizeof(tmp));
        if (fileExtension(path) && (int)tmp[0] == -119 && tmp[1] == 'P' && tmp[2] == 'N' && tmp[3] == 'G')
            std::cout << "File is png" << std::endl;
        else
            std::cout << "File is not png" << std::endl;
    }
    else
        std::cout << "File not found" << std::endl;
}