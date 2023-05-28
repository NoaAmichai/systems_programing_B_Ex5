#pragma once

#include <vector>
#include <cstdio>
#include <valarray>

namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> elements;

    public:
        // Add an element to the container
        void addElement(int element) {
            elements.push_back(element);
        }

        // Remove an element from the container
        void removeElement(int element) {
        }

        // Get the size of the container
        size_t size() const {
            return elements.size();
        }

        // Iterator class
        class Iterator {
        protected:
            MagicalContainer &container; // NOLINT(cppcoreguidelines-non-private-member-variables-in-classes)
            size_t position;// NOLINT(cppcoreguidelines-non-private-member-variables-in-classes)

        public:
            Iterator(MagicalContainer &container) : container(container), position(0) {}

            // Equality comparison
            bool operator==(const Iterator &other) const {
                return position == other.position;
            }

            // Inequality comparison
            bool operator!=(const Iterator &other) const {
                return !(*this == other);
            }

            // Dereference operator
            int operator*() const {
                return container.size(); //TODO
            }
        };

        // AscendingIterator class
        class AscendingIterator : public Iterator {
        public:
            AscendingIterator(MagicalContainer &container) : Iterator(container) {}

            // Pre-increment operator
            AscendingIterator &operator++() {
                ++position;
                return *this;
            }

            // Begin iterator function
            AscendingIterator begin() {
                return AscendingIterator(container);
            }

            // End iterator function
            AscendingIterator end() {
                return AscendingIterator(container); //TODO CHANGE
            }
        };

        // SideCrossIterator class
        class SideCrossIterator : public Iterator {
        public:
             SideCrossIterator(MagicalContainer &container) : Iterator(container) {}

            // Pre-increment operator
            SideCrossIterator &operator++() {
                if (position % 2 == 0) {
                    position += 2;
                } else {
                    position = container.size() - 1 - (position - 1);
                }
                return *this;
            }

            // Begin iterator function
            SideCrossIterator begin() {
                return SideCrossIterator(container);
            }

            // End iterator function
            SideCrossIterator end() {
                return SideCrossIterator(container); //TODO CHANGE
            }
        };

        // PrimeIterator class
        class PrimeIterator : public Iterator {
        private:
            static bool isPrime(int number) {
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

        public:
            PrimeIterator(MagicalContainer &container) : Iterator(container) {}

            // Pre-increment operator
            PrimeIterator &operator++() {
                ++position;
//                while (position < container.size() && !isPrime(container[position])) {
//                    ++position;
//                }
                return *this;
            }

            // Begin iterator function
            PrimeIterator begin() {
                return PrimeIterator(container);
            }

            // End iterator function
            PrimeIterator end() {
                return PrimeIterator(container);//TODO CHANGE
            }
        };
    };
}