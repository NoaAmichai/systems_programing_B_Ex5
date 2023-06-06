#include <stdexcept>
#include "MagicalContainer.hpp"

using namespace std;

using namespace ariel;

//Constructor
MagicalContainer::MagicalContainer() : elements(0), prime_elements(0), side_cross_elements(0) {
}

//Destructor
MagicalContainer::~MagicalContainer() {
    for (auto &element: prime_elements) {
        delete element;
    }
}

// Check if the given element is prime
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
    if (isPrime(element)) {
//            prime_elements.clear();
        insertIntoPrime(element);
    }

    // Rearrange the sideCross vector
    rearrangeSideCross();
}

// Insert a prime element to the primePointers vector in ascending order
void MagicalContainer::insertIntoPrime(int element) {
    // Todo - the other option to this function is to clear the prime vector and insert all the elements again
    // Find the correct position to insert the prime number
    int insertIndex = 0;
    while (insertIndex < prime_elements.size() && element > *prime_elements[insertIndex]) {
        insertIndex++;
    }
    // Insert the prime number at the found position
    prime_elements.insert(prime_elements.begin() + insertIndex, new int(element));
}

// Insert an ekement to the elements vector in ascending order
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

// Rearrange the sideCross vector in ascending order do to a new element or deleted element
void MagicalContainer::rearrangeSideCross() {
    side_cross_elements.clear();

    if (elements.empty())
        return;  // No elements to add to the cross order

    auto it_start = elements.begin();
    auto it_end = elements.end() - 1;

    while (it_start <= it_end) {
        side_cross_elements.push_back(&(*it_start));
        if (it_start != it_end)
            side_cross_elements.push_back(&(*it_end));
        ++it_start;
        --it_end;
    }
}


// Remove an element from the container if exists
void MagicalContainer::removeElement(int element) {
    auto it = std::find(elements.begin(), elements.end(), element);
    if (it == elements.end()) {
        throw runtime_error("Element doesn't exists");
    }
    elements.erase(it);

    // Rearrange the sideCross vector
    rearrangeSideCross();

    //if element is prime, remove it from prime vector and delete it's pointer
    if (isPrime(element)) {
        auto it_prime = std::find(prime_elements.begin(), prime_elements.end(), &element);
        prime_elements.erase(it_prime);
        delete &element;    // Todo - check if this is the correct way to delete the pointer
    }
}

// Get the size of the container
size_t MagicalContainer::size() const {
    return elements.size();
}
