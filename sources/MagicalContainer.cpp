#include <stdexcept>
#include "MagicalContainer.hpp"

namespace ariel {

    //Constructor
    MagicalContainer::MagicalContainer() : elements(0) {
    }

    // Add an element to the container
    void MagicalContainer::addElement(int element) {
        elements.push_back(element);
        std::sort(elements.begin(), elements.end());
    }

    // Remove an element from the container
    void MagicalContainer::removeElement(int element) {
        auto it = std::find(elements.begin(), elements.end(), element);
        if (it != elements.end()) {
            elements.erase(it);
        }
    }

    // Get the size of the container
    size_t MagicalContainer::size() const {
        return elements.size();
    }

}

