#include <stdexcept>
#include "MagicalContainer.hpp"

using namespace std;

namespace ariel {
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : Iterator(container) {
//        while (index < container.size() && !isPrime(container.elements[index])) {
//            ++index;
//        }
    }

//    bool MagicalContainer::PrimeIterator::isPrime(int number) {
//        if (number <= 1) {
//            return false;
//        }
//        if (number == 2) {
//            return true;
//        }
//        if (number % 2 == 0) {
//            return false;
//        }
//
//        int sqrtNum = int(sqrt(number));
//        for (int i = 3; i <= sqrtNum; i += 2) {
//            if (number % i == 0) { return false; }
//        }
//
//        return true;
//    }

// Pre-increment operator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
        ++index;
//        while (index < container.size() && !isPrime(container.elements[index])) {
//            ++index;
//        }
        if (index > container.elements.size()) {
            throw runtime_error("Iterator out of range");
        }
        return *this;
    }

    // Begin iterator function
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        return {*this};
    }

    // End iterator function
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        PrimeIterator it(*this);
        it.index = container.size();
        return it;
    }

    bool MagicalContainer::PrimeIterator::operator>(MagicalContainer::Iterator &other) const {
        if (typeid(*this) != typeid(other)) {
            throw runtime_error("Comparison between iterators of different types.");
        }
        auto *other_ = dynamic_cast<PrimeIterator *>(&other);
        if (container.elements != other_->container.elements) { //TODO not sure that this is the right way to do it
            throw runtime_error("Comparison between iterators of different containers.");
        }
        return index > other_->index;
    }

    bool MagicalContainer::PrimeIterator::operator<(MagicalContainer::Iterator &other) const {
        if (typeid(*this) != typeid(other)) {
            throw runtime_error("Comparison between iterators of different types.");
        }
        auto *other_ = dynamic_cast<PrimeIterator *>(&other);
        if (container.elements != other_->container.elements) { //TODO not sure that this is the right way to do it
            throw runtime_error("Comparison between iterators of different containers.");
        }
        return index < other_->index;
    }
}