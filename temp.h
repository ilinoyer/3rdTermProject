#pragma once
#include<vector>

template <typename T> static void delete_ob(static std::vector<T> *a, int b) {
	a->erase(a->begin() + b - 1);
}


