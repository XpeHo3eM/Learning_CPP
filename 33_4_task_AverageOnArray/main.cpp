#include <iostream>
#include <vector>



template <typename T>
T enterNumber()
{
    T num;
    std::cin >> num;
    return num;
}



template <typename T, typename ArrType>
T averageOnArr(ArrType arr)
{
    size_t size = sizeof(arr) / sizeof(arr[0]);

    T sum = 0;
    for (size_t i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    return (sum / size);
}



int main()
{
    size_t size;
    do
    {
        std::cout << "Enter array size: ";
        size = enterNumber<size_t>();

        if (size <= 0)
        {
            std::cout << "! Array size can't below or equal zero !" << std::endl;
        }
    }
    while (size <= 0);
    
    std::vector <double> vec;
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "Enter " << i + 1 << " element from " << size << ": ";
        vec.emplace_back(enterNumber<double>());
    }

    std::cout << "Average of array is " << averageOnArr<double, std::vector<double>>(vec);
}
