#include <stdexcept>
#include "MagicalContainer.hpp"

using namespace std;

using namespace ariel;

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : container(container),
                                                                                      index(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator &other)
        : container(other.container), index(other.index) {
    if (&container != &other.container)
        throw std::runtime_error("Iterators must belong to the same container.");
}

MagicalContainer::AscendingIterator &
MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other) {
    if (this != &other) {
        if (&container != &other.container)
            throw std::runtime_error("Iterators must belong to the same container.");
        container = other.container;
        index = other.index;
    }
    return *this;
}

// Pre-increment operator
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    ++index;
    if (index > container.elements.size()) {
        throw runtime_error("Iterator out of range");
    }
    return *this;
}

int MagicalContainer::AscendingIterator::operator*() {
    if (index >= container.elements.size())
        throw std::out_of_range("Iterator out of range");
    return container.elements[index];
}

bool MagicalContainer::AscendingIterator::operator==(const Iterator &other) const {
    auto *other_pointer = validateAndCast(other);
    return index == other_pointer->index;
}

bool MagicalContainer::AscendingIterator::operator!=(const Iterator &other) const {
    auto *other_pointer = validateAndCast(other);
    return index != other_pointer->index;
}

bool MagicalContainer::AscendingIterator::operator<(const Iterator &other) const {
    auto *other_pointer = validateAndCast(other);
    return index < other_pointer->index;
}

bool MagicalContainer::AscendingIterator::operator>(const Iterator &other) const {
    auto *other_pointer = validateAndCast(other);
    return index > other_pointer->index;
}

const MagicalContainer::AscendingIterator *
MagicalContainer::AscendingIterator::validateAndCast(const Iterator &other) const {
    const auto *other_pointer = dynamic_cast<const AscendingIterator *>(&other);

    if (other_pointer == nullptr)
        throw std::runtime_error("Invalid iterator comparison. Only AscendingIterator can be compared.");

    if (&container != &other_pointer->container)
        throw std::runtime_error("Iterators must belong to the same container.");

    return other_pointer;
}

// Begin iterator function
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
    return {*this};
}

// End iterator function
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    AscendingIterator it(*this);
    it.index = container.elements.size();
    return it;
}
