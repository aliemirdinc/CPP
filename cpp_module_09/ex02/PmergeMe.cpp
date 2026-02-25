/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:15:12 by aldinc            #+#    #+#             */
/*   Updated: 2026/02/25 17:34:40 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <algorithm>

// Constructor & Destructor
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

// -----------------------------------------------------------------------------
// HELPER FUNCTIONS (JACOBSTHAL)
// -----------------------------------------------------------------------------

// Jacobsthal Sequence: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171...
// Optimizes binary insertion order
unsigned int PmergeMe::getJacobsthal(unsigned int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2);
}

// -----------------------------------------------------------------------------
// VECTOR IMPLEMENTATION
// -----------------------------------------------------------------------------

// Binary insert
void PmergeMe::binaryInsertVector(std::vector<int>& mainChain, int value) {
	std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
	mainChain.insert(it, value);
}

void PmergeMe::mergeInsertionSortVector(std::vector<int>& arr) {
	size_t n = arr.size();
	if (n <= 1) return;

	// Separate straggler if odd
	int straggler = -1;
	bool hasStraggler = (n % 2 != 0);
	if (hasStraggler) {
		straggler = arr.back();
		arr.pop_back();
	}

	// Create and sort pairs
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size(); i += 2) {
		if (arr[i] > arr[i+1])
			pairs.push_back(std::make_pair(arr[i+1], arr[i]));
		else
			pairs.push_back(std::make_pair(arr[i], arr[i+1]));
	}

	// Sort winners
	std::vector<int> largerElements;
	for (size_t i = 0; i < pairs.size(); ++i) {
		largerElements.push_back(pairs[i].second);
	}

	mergeInsertionSortVector(largerElements);

	// Build chains
	std::vector<int> mainChain;

	mainChain = largerElements;

	// Insert first pending
	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].second == mainChain[0]) {
			mainChain.insert(mainChain.begin(), pairs[i].first);
			pairs.erase(pairs.begin() + i);
			break;
		}
	}

	// Collect pending
	std::vector<int> orderedPending;
	for (size_t i = 1; i < largerElements.size(); ++i) {
		 for (size_t j = 0; j < pairs.size(); ++j) {
			if (pairs[j].second == largerElements[i]) {
				orderedPending.push_back(pairs[j].first);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}

	// Insert with Jacobsthal
	size_t pendingSize = orderedPending.size();
	size_t jacobsthalIndex = 1; // J_1
	size_t prevJacobsthal = 0;  // J_0

	size_t insertedCount = 0;

	while (insertedCount < pendingSize) {
		size_t nextJacobsthal = getJacobsthal(jacobsthalIndex + 2);
		size_t limit = nextJacobsthal - 1;
		if (limit >= pendingSize)
			limit = pendingSize - 1;

		for (size_t i = limit; i > prevJacobsthal || (prevJacobsthal == 0 && i == 0); --i) {
			 int val = orderedPending[i];
			 binaryInsertVector(mainChain, val);
			 insertedCount++;
			 if (i == 0)
			 	break;
		}

		prevJacobsthal = limit;
		jacobsthalIndex++;
	}

	// Insert straggler if exists
	if (hasStraggler) {
		binaryInsertVector(mainChain, straggler);
	}

	arr = mainChain;
}

// -----------------------------------------------------------------------------
// DEQUE IMPLEMENTATION
// -----------------------------------------------------------------------------

void PmergeMe::binaryInsertDeque(std::deque<int>& mainChain, int value) {
	std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
	mainChain.insert(it, value);
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int>& arr) {
	size_t n = arr.size();
	if (n <= 1) return;

	int straggler = -1;
	bool hasStraggler = (n % 2 != 0);
	if (hasStraggler) {
		straggler = arr.back();
		arr.pop_back();
	}

	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < arr.size(); i += 2) {
		if (arr[i] > arr[i+1])
			pairs.push_back(std::make_pair(arr[i], arr[i+1]));
		else
			pairs.push_back(std::make_pair(arr[i+1], arr[i]));
	}

	std::deque<int> largerElements;
	for (size_t i = 0; i < pairs.size(); ++i) {
		largerElements.push_back(pairs[i].first);
	}

	mergeInsertionSortDeque(largerElements);

	std::deque<int> mainChain = largerElements;
	std::deque<int> orderedPending;

	for (size_t i = 0; i < pairs.size(); ++i) {
		if (pairs[i].first == mainChain[0]) {
			mainChain.push_front(pairs[i].second);
			pairs.erase(pairs.begin() + i);
			break;
		}
	}

	for (size_t i = 1; i < largerElements.size(); ++i) {
		 for (size_t j = 0; j < pairs.size(); ++j) {
			if (pairs[j].first == largerElements[i]) {
				orderedPending.push_back(pairs[j].second);
				pairs.erase(pairs.begin() + j);
				break;
			}
		 }
	}

	size_t pendingSize = orderedPending.size();
	size_t jacobsthalIndex = 1;
	size_t prevJacobsthal = 0;
	size_t insertedCount = 0;

	while (insertedCount < pendingSize) {
		size_t nextJacobsthal = getJacobsthal(jacobsthalIndex + 2);
		size_t limit = nextJacobsthal - 1;
		if (limit >= pendingSize) limit = pendingSize - 1;

		for (size_t i = limit; i > prevJacobsthal || (prevJacobsthal == 0 && i == 0); --i) {
			 binaryInsertDeque(mainChain, orderedPending[i]);
			 insertedCount++;
			 if (i == 0) break;
		}
		prevJacobsthal = limit;
		jacobsthalIndex++;
	}

	if (hasStraggler) {
		binaryInsertDeque(mainChain, straggler);
	}

	arr = mainChain;
}

// -----------------------------------------------------------------------------
// MAIN PROCESS
// -----------------------------------------------------------------------------

void PmergeMe::process(int argc, char **argv) {
	std::vector<int> input_data;

	// Parse input only once to validate and store in a temporary buffer
	for (int i = 1; i < argc; ++i) {
		std::string s = argv[i];
		for (size_t j = 0; j < s.length(); ++j) {
			if (!isdigit(s[j]))
				throw std::runtime_error("Error: Invalid input (not a positive number).");
		}
		long val = std::atol(s.c_str());
		if (val < 0 || val > 2147483647)
			 throw std::runtime_error("Error: Input number out of integer range.");
		
		input_data.push_back(static_cast<int>(val));
	}

	// Display before
	std::cout << "Before: ";
	size_t printLimit = (input_data.size() > 5) ? 5 : input_data.size();
	for (size_t i = 0; i < printLimit; ++i) {
		std::cout << input_data[i] << " ";
	}
	if (input_data.size() > 5) std::cout << "[...]";
	std::cout << std::endl;

	// --- MEASURE VECTOR ---
	// Time includes: copying data to container + sorting
	std::vector<int> vec;
	clock_t startVec = clock();
	
	// Data management: transfer to vector
	vec = input_data; 
	// Sorting
	mergeInsertionSortVector(vec);
	
	clock_t endVec = clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

	// --- MEASURE DEQUE ---
	// Time includes: copying data to container + sorting
	std::deque<int> deq;
	clock_t startDeq = clock();
	
	// Data management: transfer to deque
	deq.assign(input_data.begin(), input_data.end());
	// Sorting
	mergeInsertionSortDeque(deq);
	
	clock_t endDeq = clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

	// Display after (using vector results)
	std::cout << "After:  ";
	for (size_t i = 0; i < printLimit; ++i) {
		std::cout << vec[i] << " ";
	}
	if (vec.size() > 5) std::cout << "[...]";
	std::cout << std::endl;

	// Display times
	std::cout << "Time to process a range of " << vec.size() 
			  << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;

	std::cout << "Time to process a range of " << deq.size() 
			  << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
	
	// Verify sizes
	if (vec.size() != deq.size()) {
		std::cerr << "Error: Container sizes mismatch!" << std::endl;
	}
}
