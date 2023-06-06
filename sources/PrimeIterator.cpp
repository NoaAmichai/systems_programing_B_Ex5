#include <stdexcept>
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : Iterator(container) {}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator &other) : Iterator(other) {
    if (&container != &other.container)
        throw std::runtime_error("Iterators must belong to the same container.");
}

MagicalContainer::PrimeIterator &
MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other) {
    if (this != &other) {
        if (&container != &other.container)
            throw std::runtime_error("Iterators must belong to the same container.");
        container = other.container;
        index = other.index;
    }
    return *this;
}

// Pre-increment operator
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
    ++index;
    if (index > container.prime_elements.size()) {
        throw runtime_error("Iterator out of range");
    }
    return *this;
}

int MagicalContainer::PrimeIterator::operator*() {
    if (index >= container.prime_elements.size())
        throw std::out_of_range("Iterator out of range");
    return *(container.prime_elements.at(index));
}

// Begin iterator function
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
    return {*this};
}

// End iterator function
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
    PrimeIterator it(*this);
    it.index = container.prime_elements.size();
    return it;
}