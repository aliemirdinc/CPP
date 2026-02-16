/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:11:22 by aldinc            #+#    #+#             */
/*   Updated: 2026/02/16 19:21:03 by aldinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <ctime>   // clock()
#include <cstdlib> // atoi, exit
#include <climits> // INT_MAX
#include <algorithm> // std::lower_bound

class PmergeMe {
    private:
        // Jacobsthal helper
        unsigned int getJacobsthal(unsigned int n);

        // vector helper functs
        void    mergeInsertionSortVector(std::vector<int>& arr);
        void    binaryInsertVector(std::vector<int>& mainChain, int value);

        // deque helper functs
        void    mergeInsertionSortDeque(std::deque<int>& arr);
        void    binaryInsertDeque(std::deque<int>& mainChain, int value);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        // main function
        void    process(int argc, char **argv);
};

#endif