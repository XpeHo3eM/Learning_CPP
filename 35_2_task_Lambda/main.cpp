#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>



int main()
{
	std::vector<int> vec = { 1, 2, 3, 3, 2, 5, 3, 4, 4, 1 };

	auto lambda = [](const std::vector<int> &vec)
	{
		std::unordered_set<int> us;
		std::vector<int> newVec;

		for (const auto& el : vec)
		{
			if (us.insert(el).second)
				newVec.emplace_back(el);
		}

		return std::make_unique<std::vector<int>>(newVec);
	};

	auto uptr = lambda(vec);

	for (const auto& el : (*uptr))
		std::cout << el << std::endl;
}