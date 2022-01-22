#include <iostream>
#include <filesystem>
#include <string>



namespace fs = std::filesystem;



int main()
{
    std::cout << "Enter path: ";
    fs::path path;
    std::cin >> path;
    std::cout << "Enter extension to find: ";
    std::string extension;
    std::cin >> extension;
    if (extension[0] != '.')
        extension.insert(extension.begin(), '.');

    auto findFileByExtension = [](fs::path file, const std::string &extension)
    {
        const int compareEqual = 0;
        if (fs::is_regular_file(file) && (file.extension().compare(extension) == compareEqual))
                std::cout << file << std::endl;
    };

    for (const auto &f : fs::recursive_directory_iterator(path))
    {
        findFileByExtension(f.path(), extension);
    }        
}