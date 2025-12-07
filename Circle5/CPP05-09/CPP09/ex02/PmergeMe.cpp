/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:32:38 by jramos-a          #+#    #+#             */
/*   Updated: 2025/09/24 11:32:38 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool isPositiveInteger(const char* s) {
	if (!s || *s == '\0') return false;
	int i = 0;
	if (s[0] == '+') {
		if (s[1] == '\0') return false;
		i = 1;
	}
	for (; s[i] != '\0'; ++i) {
		if (s[i] < '0' || s[i] > '9') return false;
	}
	char* endptr = NULL;
	long val = std::strtol(s, &endptr, 10);
	if (endptr == NULL || *endptr != '\0') return false;
	if (val <= 0) return false;
	return true;
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	vec = other.vec;
	deq = other.deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		vec = other.vec;
		deq = other.deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::insertValues(char** values, int count) {
	for (int i = 0; i < count; ++i) {
		if (!isPositiveInteger(values[i])) {
			std::cerr << "Error: invalid input '" << values[i] << "' (only positive integers allowed)" << std::endl;
			std::exit(1);
		}
		int val = std::atoi(values[i]);
		vec.push_back(val);
		deq.push_back(val);
	}
}

void PmergeMe::sortAndDisplay() {
	std::cout << "Unsorted sequence: ";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << (i + 1 < vec.size() ? " " : "");
	}
	std::cout << std::endl;

	std::vector<int> vec_to_sort = vec;
	std::deque<int> deq_to_sort = deq;

	std::clock_t start_vec = std::clock();
	mergeInsertSort(vec_to_sort);
	std::clock_t end_vec = std::clock();
	long long dur_vec = static_cast<long long>((end_vec - start_vec) * 1000000LL / CLOCKS_PER_SEC);

	std::clock_t start_deq = std::clock();
	mergeInsertSort(deq_to_sort);
	std::clock_t end_deq = std::clock();
	long long dur_deq = static_cast<long long>((end_deq - start_deq) * 1000000LL / CLOCKS_PER_SEC);

	std::cout << "Sorted sequence: ";
	for (size_t i = 0; i < vec_to_sort.size(); ++i) {
		std::cout << vec_to_sort[i] << (i + 1 < vec_to_sort.size() ? " " : "");
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << dur_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << dur_deq << " us" << std::endl;
}

void PmergeMe::mergeInsertSort(std::vector<int>& container) {
	if (container.size() <= 1) {
		return;
	}
	size_t mid = container.size() / 2;
	std::vector<int> left(container.begin(), container.begin() + mid);
	std::vector<int> right(container.begin() + mid, container.end());
	mergeInsertSort(left);
	mergeInsertSort(right);
	size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i] < right[j]) {
			container[k++] = left[i++];
		} else {
			container[k++] = right[j++];
		}
	}
	while (i < left.size()) {
		container[k++] = left[i++];
	}
	while (j < right.size()) {
		container[k++] = right[j++];
	}
}

void PmergeMe::mergeInsertSort(std::deque<int>& container) {
	if (container.size() <= 1) {
		return;
	}
	size_t mid = container.size() / 2;
	std::deque<int> left;
	std::deque<int> right;
	for (size_t i = 0; i < mid; ++i) left.push_back(container[i]);
	for (size_t i = mid; i < container.size(); ++i) right.push_back(container[i]);
	mergeInsertSort(left);
	mergeInsertSort(right);
	size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i] < right[j]) {
			container[k++] = left[i++];
		} else {
			container[k++] = right[j++];
		}
	}
	while (i < left.size()) {
		container[k++] = left[i++];
	}
	while (j < right.size()) {
		container[k++] = right[j++];
	}
}
