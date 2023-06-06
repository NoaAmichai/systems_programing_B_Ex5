#include <stdexcept>
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : Iterator(container) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer::SideCrossIterator &other)
        : Iterator(other) {
    if (&container != &other.container)
        throw std::runtime_error("Iterators must belong to the same container.");
}

MagicalContainer::SideCrossIterator &
MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other) {
    if (this != &other) {
        if (&container != &other.container)
            throw std::runtime_error("Iterators must belong to the same container.");
        container = other.container;
        index = other.index;
    }
    return *this;
}

// Pre-increment operator
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
    ++index;
    if (index > container.side_cross_elements.size()) {
        throw runtime_error("Iterator out of range");
    }
    return *this;
}

int MagicalContainer::SideCrossIterator::operator*() {
    if (index >= container.side_cross_elements.size())
        throw std::out_of_range("Iterator out of range");
    return *container.side_cross_elements[index];
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    return {(*this)};
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    SideCrossIterator it(*this);
    it.index = container.side_cross_elements.size();
    return it;
}