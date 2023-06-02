#include <stdexcept>
#include "sources/MagicalContainer.hpp"

using namespace std;

namespace ariel {
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container) : Iterator(container) {
    }

    // Pre-increment operator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        //TODO check if need out_of_range here
        ++index;
        return *this;
    }

    // Begin iterator function
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        return {*this};
    }

    // End iterator function
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        AscendingIterator it(*this);
        it.index = container.size();
        return it;
    }

    // Greater than operator
    bool MagicalContainer::AscendingIterator::operator>( MagicalContainer::Iterator &other) const {
        if (typeid(*this) != typeid(other)) {
            throw runtime_error("Comparison between iterators of different types.");
        }
        auto* other_ = dynamic_cast<AscendingIterator*>(&other);
        if (container.elements != other_->container.elements) { //TODO not sure that this is the right way to do it
            throw runtime_error("Comparison between iterators of different containers.");
        }
        return index > other_->index;
    }

    // Less than operator
    bool MagicalContainer::AscendingIterator::operator<(MagicalContainer::Iterator &other) const {
        if (typeid(*this) != typeid(other)) {
            throw runtime_error("Comparison between iterators of different types.");
        }
        auto* other_ = dynamic_cast<AscendingIterator*>(&other);
        if (container.elements != other_->container.elements) { //TODO not sure that this is the right way to do it
            throw runtime_error("Comparison between iterators of different containers.");
        }
        return index < other_->index;
    }
}