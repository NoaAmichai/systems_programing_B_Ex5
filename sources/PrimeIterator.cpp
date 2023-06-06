#include <stdexcept>
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(container),
                                                                              index(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator &other) : container(
        other.container), index(other.index) {
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

bool MagicalContainer::PrimeIterator::operator==(const Iterator &other) const {
    auto *other_pointer = validateAndCast(other);
    return index == other_pointer->index;
}

bool MagicalContainer::PrimeIterator::operator!=(const Iterator &other) const {
    auto *other_pointer = validateAndCast(other);
    return index != other_pointer->index;
}

bool MagicalContainer::PrimeIterator::operator<(const Iterator &other) const {
    auto *other_pointer = validateAndCast(other);
    return index < other_pointer->index;
}

bool MagicalContainer::PrimeIterator::operator>(const Iterator &other) const {
    auto *other_pointer = validateAndCast(other);
    return index > other_pointer->index;
}

const MagicalContainer::PrimeIterator *
MagicalContainer::PrimeIterator::validateAndCast(const Iterator &other) const {
    const auto *other_pointer = dynamic_cast<const PrimeIterator *>(&other);

    if (other_pointer == nullptr)
        throw std::runtime_error("Invalid iterator comparison. Only AscendingIterator can be compared.");

    if (&container != &other_pointer->container)
        throw std::runtime_error("Iterators must belong to the same container.");

    return other_pointer;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
    return index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
    return index > other.index;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
    return !(*this > other) && (other != other);
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
