#include "sources/MagicalContainer.hpp"

// PrimeIterator class
using namespace std;

namespace ariel {
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