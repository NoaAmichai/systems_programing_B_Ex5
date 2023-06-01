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

    // Iterator class
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
            throw std::out_of_range("Iterator out of range");
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

    // AscendingIterator class
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : Iterator(container) {
    }

    // Pre-increment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        ++position;
        return *this;
    }

    // Begin iterator function
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        return AscendingIterator(*this);
    }


    // End iterator function
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        AscendingIterator it(*this);
        it.position = container.size();
        return it;
    }

    bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::Iterator &other) const {
        return false;
    }

    bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::Iterator &other) const {
        return false;
    }

    // SideCrossIterator class
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : Iterator(container) {
    }

    // Pre-increment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        if (position % 2 == 0) {
            position += 2;
        } else {
            position = container.size() - 1 - (position - 1);
        }
        return *this;
    }

    // Begin iterator function
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        return SideCrossIterator(*this);
    }

    // End iterator function
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        SideCrossIterator it(*this);
        it.position = container.size();
        return it;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::Iterator &other) const {
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::Iterator &other) const {
        return false;
    }

    // PrimeIterator class
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : Iterator(container) {
        while (position < container.size() && !isPrime(container.elements[position])) {
            ++position;
        }
    }

    bool MagicalContainer::PrimeIterator::isPrime(int number) {
        if (number <= 1) {
            return false;
        }
        if (number == 2) {
            return true;
        }
        if (number % 2 == 0) {
            return false;
        }

        int sqrtNum = static_cast<int>(std::sqrt(number));
        for (int i = 3; i <= sqrtNum; i += 2) {
            if (number % i == 0) { return false; }
        }

        return true;
    }

    // Pre-increment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
        ++position;
        while (position < container.size() && !isPrime(container.elements[position])) {
            ++position;
        }
        return *this;
    }

    // Begin iterator function
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        return PrimeIterator(*this);
    }

    // End iterator function
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        PrimeIterator it(*this);
        it.position = container.size();
        return it;
    }

    bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::Iterator &other) const {
        return false;
    }

    bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::Iterator &other) const {
        return false;
    }
}

