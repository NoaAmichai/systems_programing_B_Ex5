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
            size_t index;// NOLINT(cppcoreguidelines-non-private-member-variables-in-classes)

        public:
            Iterator(Iterator &&other) = default;

            Iterator &operator=(Iterator &&other) = delete;

            Iterator(MagicalContainer &container);

            Iterator(const Iterator &other) = default;

            virtual ~Iterator() = default;

            bool operator==(const Iterator &other) const;

            bool operator!=(const Iterator &other) const;

            virtual bool operator>(Iterator &other) const = 0;

            virtual bool operator<(Iterator &other) const = 0;

            Iterator &operator=(const Iterator &other);

            virtual int operator*();
        };

        // AscendingIterator class
        class AscendingIterator : public Iterator {
        public:
            AscendingIterator(MagicalContainer &container);

            AscendingIterator &operator++();

            bool operator>(Iterator &other) const override;

            bool operator<(Iterator &other) const override;

            AscendingIterator begin();

            AscendingIterator end();
        };

        // SideCrossIterator class
        class SideCrossIterator : public Iterator {
        private:
            size_t end_index;
            bool reverse;
        public:
            SideCrossIterator(MagicalContainer &container);

            SideCrossIterator &operator++();

            bool operator>(Iterator &other) const override;

            bool operator<(Iterator &other) const override;

            SideCrossIterator begin();

            SideCrossIterator end();

            int operator*()  override;
        };

        // PrimeIterator class
        class PrimeIterator : public Iterator {
        private:
            static bool isPrime(int number);

        public:
            PrimeIterator(MagicalContainer &container);

            PrimeIterator &operator++();

            bool operator>(Iterator &other) const override;

            bool operator<(Iterator &other) const override;

            PrimeIterator begin();

            PrimeIterator end();
        };
    };
}