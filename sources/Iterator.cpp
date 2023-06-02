#include <stdexcept>
#include "sources/MagicalContainer.hpp"

using namespace std;
// Iterator class
namespace ariel {
    MagicalContainer::Iterator::Iterator(MagicalContainer &container) : container(container), position(0) {
    }

// Equality comparison
    bool MagicalContainer::Iterator::operator==(const MagicalContainer::Iterator &other) const {
        return position == other.position;
    }

// Inequality comparison
    bool MagicalContainer::Iterator::operator!=(const MagicalContainer::Iterator &other) const { //TODO check
        return !(*this == other);
    }

// Dereference operator
    int MagicalContainer::Iterator::operator*() const {
        if (position >= container.size()) {
            throw out_of_range("Iterator out of range");
        }
        return container.elements[position];
    }

    MagicalContainer::Iterator &MagicalContainer::Iterator::operator=(const MagicalContainer::Iterator &other) {
        if (this != &other) {
            container = other.container;
            position = other.position;
        }
        return *this;
    }
}