#include "sources/MagicalContainer.hpp"

using namespace std;

namespace ariel {
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
}