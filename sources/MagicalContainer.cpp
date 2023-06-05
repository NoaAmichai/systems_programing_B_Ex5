#include <stdexcept>
#include "MagicalContainer.hpp"

using namespace std;

namespace ariel {
    //Constructor
    MagicalContainer::MagicalContainer() : elements(0), prime_elements(0), side_cross_elements(0) {
    }

    // Add an element to the container
    void MagicalContainer::addElement(int element) {

        // Add the element to the integer vector in ascending order
        auto intIt = elements.begin();
        while (intIt != elements.end() && *intIt < element) {
            ++intIt;
        }
        elements.insert(intIt, element);

        // If the element is prime, add its pointer to primePointers vector in ascending order
        if (isPrime(element)) {
            auto primeIt = prime_elements.begin();
            while (primeIt != prime_elements.end() && **primeIt < element) {
                ++primeIt;
            }
            prime_elements.insert(primeIt, new int(element));
        }


    }

    //Help function to add an element in the right place
    void MagicalContainer::addInRightPlace(int element, vector<int> &vec) {
        auto it = vec.begin();
        while (it != vec.end() && *it < element) {
            ++it;
        }
        vec.insert(it, element);
    }

    //Help function to add a pointer in the right place
    void MagicalContainer::PointerInRightPlace(int* element, vector<int*> &vec) {
        auto it = vec.begin();
        while (it != vec.end() && *it < element) {
            ++it;
        }
        vec.insert(it, element);
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

    bool MagicalContainer::isPrime(int element) {
        if (element <= 1) {
            return false;
        }
        if (element == 2) {
            return true;
        }
        if (element % 2 == 0) {
            return false;
        }

        int sqrtNum = int(sqrt(element));
        for (int i = 3; i <= sqrtNum; i += 2) {
            if (element % i == 0) { return false; }
        }

        return true;
    }


}

