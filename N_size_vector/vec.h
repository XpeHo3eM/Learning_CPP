#pragma once
#include <cmath>

class Vec
{
public:
	Vec() : size_{ 0 }, coordinate_{ nullptr }
	{
		system("cls");
		std::cout << "Enter count of dimensions your vector: ";
		int dimension = 0;
		while (dimension <= 0)
			std::cin >> dimension;

		size_ = dimension;
		coordinate_ = new int[size_]();

		std::cout << "Enter " << size_ << " coordinate: ";
		for (int i = 0; i < size_; ++i)
		{
			int tmp;
			std::cin >> tmp;
			coordinate_[i] = tmp;
		}
	}

	Vec(int size) : size_{ size }, coordinate_{ new int[size_]() }
	{
		std::cout << "Enter " << size_ << " coordinate: ";
		for (int i = 0; i < size_; ++i)
		{
			int tmp;
			std::cin >> tmp;
			coordinate_[i] = tmp;
		}
	}

	Vec(const Vec& vec): size_{vec.size_}, coordinate_{new int[size_]()}
	{
		for (int i = 0; i < vec.size_; ++i)
			coordinate_[i] = vec.coordinate_[i];
	}

	void setSize(int size) 
	{
		size_ = size;
		coordinate_ = new int[size_]();
	}

	void setCoord(int pos, int value)
	{
		coordinate_[pos] = value;
	}

	int getSize() { return size_; }
	int getCoord(int i)	{ return coordinate_[i]; }

	long double norm()
	{
		int sum = 0;
		for (int i = 0; i < size_; ++i)
			sum += std::pow(coordinate_[i], 2);

		return (static_cast<long double> (std::sqrt(sum)));
	}

	~Vec()
	{
		delete[] coordinate_;
		coordinate_ = nullptr;
	}

private:
	int size_;
	int* coordinate_;
};