#include <stdexcept>
#include "MagicalContainer.hpp"

using namespace std;
// Iterator class
namespace ariel {
    MagicalContainer::Iterator::Iterator(MagicalContainer &container) : container(container), index(0) {
    }

    // Equality comparison
    bool MagicalContainer::Iterator::operator==(const MagicalContainer::Iterator &other) const {
        return index == other.index;
    }

    // Inequality comparison
    bool MagicalContainer::Iterator::operator!=(const MagicalContainer::Iterator &other) const { //TODO check
        return index != other.index;
    }

    // Dereference operator
    int MagicalContainer::Iterator::operator*() {
        if (index >= container.size()) {
            throw out_of_range("Iterator out of range");
        }
        return container.elements[index];
    }

    MagicalContainer::Iterator &MagicalContainer::Iterator::operator=(const MagicalContainer::Iterator &other) {
        if (typeid(*this) != typeid(other)) {
            throw runtime_error("Comparison between iterators of different types.");
        }
        if (container.elements != other.container.elements) { //TODO check
            throw runtime_error("Different containers.");
        }
        if (*this != other) {
            index = other.index;
        }
        return *this;
    }
}