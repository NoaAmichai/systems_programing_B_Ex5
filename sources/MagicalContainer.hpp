#pragma once

#include <vector>
#include <cstdio>
#include <valarray>

namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> elements;

    public:
        MagicalContainer();

        void addElement(int element);

        void removeElement(int element);

        size_t size() const;

        // Iterator class
        class Iterator {
        protected:
            MagicalContainer &container; // NOLINT(cppcoreguidelines-non-private-member-variables-in-classes)
            size_t position;// NOLINT(cppcoreguidelines-non-private-member-variables-in-classes)

        public:
            Iterator(MagicalContainer &container);

            bool operator==(const Iterator &other) const;

            bool operator!=(const Iterator &other) const;

            virtual bool operator>(const Iterator &other) const = 0;

            virtual bool operator<(const Iterator &other) const = 0;

            Iterator &operator=(const Iterator &other);

            int operator*() const;
        };

        // AscendingIterator class
        class AscendingIterator : public Iterator {
        public:
            AscendingIterator(MagicalContainer &container);

            AscendingIterator &operator++();

            bool operator>(const Iterator &other) const override;

            bool operator<(const Iterator &other) const override;

            AscendingIterator begin();

            AscendingIterator end();
        };

        // SideCrossIterator class
        class SideCrossIterator : public Iterator {
        public:
            SideCrossIterator(MagicalContainer &container);

            SideCrossIterator &operator++();

            bool operator>(const Iterator &other) const override;

            bool operator<(const Iterator &other) const override;

            SideCrossIterator begin();

            SideCrossIterator end();
        };

        // PrimeIterator class
        class PrimeIterator : public Iterator {
        private:
            static bool isPrime(int number);

        public:
            PrimeIterator(MagicalContainer &container);

            PrimeIterator &operator++();

            bool operator>(const Iterator &other) const override;

            bool operator<(const Iterator &other) const override;

            PrimeIterator begin();

            PrimeIterator end();
        };
    };
}