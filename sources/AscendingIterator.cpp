#include "sources/MagicalContainer.hpp"

using namespace std;

namespace ariel {
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
}