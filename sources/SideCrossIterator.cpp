#include <stdexcept>
#include "MagicalContainer.hpp"

using namespace std;

namespace ariel {
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : Iterator(container),
                                                                                          end_index(container.size() -
                                                                                                    1), reverse(false) {
    }

    // Pre-increment operator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        if (index == 0 && !reverse) {
            reverse = true;
        } else if (index == container.size() - 1 && reverse) {
            index = 1;
            reverse = false;
        } else {
            if (reverse) {
                ++index;
            } else {
                --end_index;
            }
        }
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*() {
        if (index > end_index) {
            throw out_of_range("Iterator out of range");
        }
        if (reverse) {
            reverse = !reverse;
            return container.elements[end_index];
        } else {
            reverse = !reverse;
            return container.elements[index];
        }
    }

    // Begin iterator function
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        return {(*this)};
    }

    // End iterator function
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        SideCrossIterator it(container);
        if (container.elements.size() % 2 == 0) {
            it.index = container.size() / 2;
            it.end_index = container.size() / 2;
        } else {
            it.index = container.size() / 2 + 1;
            it.end_index = container.size() / 2 - 1;
        }
        return it;
    }

    bool MagicalContainer::SideCrossIterator::operator>(MagicalContainer::Iterator &other) const {
        if (typeid(*this) != typeid(other)) {
            throw runtime_error("Comparison between iterators of different types.");
        }
        auto *other_ = dynamic_cast<SideCrossIterator *>(&other);
        if (container.elements != other_->container.elements) { //TODO not sure that this is the right way to do it
            throw runtime_error("Comparison between iterators of different containers.");
        }
        return index > other_->index;
    }

    bool MagicalContainer::SideCrossIterator::operator<(MagicalContainer::Iterator &other) const {
        if (typeid(*this) != typeid(other)) {
            throw runtime_error("Comparison between iterators of different types.");
        }
        auto *other_ = dynamic_cast<SideCrossIterator *>(&other);
        if (container.elements != other_->container.elements) { //TODO not sure that this is the right way to do it
            throw runtime_error("Comparison between iterators of different containers.");
        }
        return index < other_->index;
    }

//    bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator &other) const {
//        return index == other.index and end_index == other.end_index;
//    }
}