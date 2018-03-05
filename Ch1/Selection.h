#include<vector>
#include<iostream>


template<typename object>

	bool selection(const std::vector<object> &v, const object k){

		for (auto i = 0; i < v.size(); ++i) {

			if (v[i] == k) {

				std::cout << "Find it at index: " << i << "\n";

				return true;

			}
		}

		std::cout << "Cant be found yo\n";
		return false;
	}