#include <stdexcept>
#include "MagicalContainer.hpp"

using namespace std;

namespace ariel {
    //Constructor
    MagicalContainer::MagicalContainer() : elements(0), prime_elements(0), side_cross_elements(0) {
    }

    bool MagicalContainer::isPrime(int element) {
        if (element <= 1) {
            return false;
        }
        for (int i = 2; i * i <= element; ++i) {
            if (element % i == 0) {
                return false;
            }
        }
        return true;
    }

    // Add an element to the container
    void MagicalContainer::addElement(int element) {
        // Add the element to the elements vector in ascending order
        insertInSortedOrder(element);

        // If the element is prime, add a pointer to primePointers vector in ascending order
        if (isPrime(element))
        {
            prime_elements.clear();
//            prime_elements.reserve(elements.size());
            for (int &elem : elements)
            {
                if (isPrime(elem))
                    prime_elements.push_back(&elem);
            }
        }


        // Add a pointer of element to the sideCross vector in ascending order
//        for (int element: elements) {
//            int *pointer = &element;
//
//
//        }
    }

//    void MagicalContainer::insertIntoPrime(int element) {
//        // Find the correct position to insert the prime number
//        int insertIndex = 0;
//        while (insertIndex < prime_elements.size() && element > *prime_elements[insertIndex]) {
//            insertIndex++;
//        }
//        // Insert the prime number at the found position
//        prime_elements.insert(prime_elements.begin() + insertIndex, new int(element));
//    }

    // Insert an element to the container in ascending order
    void MagicalContainer::insertInSortedOrder(int element) {
        // Check if the container is empty or if the new element is greater than the last element
        if (elements.empty() || element > elements.back()) {
            elements.push_back(element);
            return;
        }

        // Iterate through the container to find the correct position to insert the element
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (element <= *it) {
                elements.insert(it, element);
                return;
            }
        }
    }


    // Remove an element from the container
    void MagicalContainer::removeElement(int element) {
        auto it = std::find(elements.begin(), elements.end(), element);
        if (it == elements.end()) {
            throw runtime_error("Element doesn't exists");
        }
        elements.erase(it);
    }

    // Get the size of the container
    size_t MagicalContainer::size() const {
        return elements.size();
    }
}

