#include <stdexcept>
#include "MagicalContainer.hpp"

using namespace std;

using namespace ariel;

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(container),
                                                                                      index(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer::SideCrossIterator &other)
        : container(other.container), index(other.index) {
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

bool MagicalContainer::SideCrossIterator::operator==(const Iterator &other) const {
    auto *other_pointer = validateAndCast(other);
    return index == other_pointer->index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const Iterator &other) const {
    auto *other_pointer = validateAndCast(other);
    return index != other_pointer->index;
}

bool MagicalContainer::SideCrossIterator::operator<(const Iterator &other) const {
    auto *other_pointer = validateAndCast(other);
    return index < other_pointer->index;
}

bool MagicalContainer::SideCrossIterator::operator>(const Iterator &other) const {
    auto *other_pointer = validateAndCast(other);
    return index > other_pointer->index;
}

const MagicalContainer::SideCrossIterator *
MagicalContainer::SideCrossIterator::validateAndCast(const Iterator &other) const {
    const auto *other_pointer = dynamic_cast<const SideCrossIterator *>(&other);

    if (other_pointer == nullptr)
        throw std::runtime_error("Invalid iterator comparison. Only AscendingIterator can be compared.");

    if (&container != &other_pointer->container)
        throw std::runtime_error("Iterators must belong to the same container.");

    return other_pointer;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
    return {(*this)};
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
    SideCrossIterator it(*this);
    it.index = container.side_cross_elements.size();
    return it;
}
