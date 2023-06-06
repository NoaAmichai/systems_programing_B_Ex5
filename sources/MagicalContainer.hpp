#pragma once
#include "Iterator.hpp"
#include <vector>
#include <cstdio>
#include <valarray>
#include <set>


namespace ariel {
    class MagicalContainer {
    private:
        std::vector<int> elements;
        std::vector<int *> prime_elements;
        std::vector<int *> side_cross_elements;

        void insertInSortedOrder(int element);
        void insertIntoPrime(int element);
        void rearrangeSideCross();

    public:
        MagicalContainer();

        ~MagicalContainer();

        void addElement(int element);

        void removeElement(int element);

        size_t size() const;

        bool isPrime(int element);


        // AscendingIterator class
        class AscendingIterator : public Iterator {
        private:
            MagicalContainer &container;
            size_t index;

            const AscendingIterator *validateAndCast(const Iterator &other) const;

        public:
            AscendingIterator(MagicalContainer &container);

            AscendingIterator(const AscendingIterator &other);

            ~AscendingIterator() override = default;

            AscendingIterator &operator=(const AscendingIterator &other);

            AscendingIterator &operator++();

            int operator*();

            bool operator==(const Iterator &other) const override;

            bool operator!=(const Iterator &other) const override;

            bool operator<(const Iterator &other) const override;

            bool operator>(const Iterator &other) const override;

            AscendingIterator begin() const;

            AscendingIterator end() const;
        };

        // SideCrossIterator class
        class SideCrossIterator : public Iterator {
        private:
            MagicalContainer &container;
            size_t index;

            const SideCrossIterator *validateAndCast(const Iterator &other) const;

        public:
            SideCrossIterator(MagicalContainer &container);

            SideCrossIterator(const SideCrossIterator &other);

            ~SideCrossIterator() override = default;

            SideCrossIterator &operator=(const SideCrossIterator &other);

            SideCrossIterator &operator++();

            int operator*();

            bool operator==(const Iterator &other) const override;

            bool operator!=(const Iterator &other) const override;

            bool operator<(const Iterator &other) const override;

            bool operator>(const Iterator &other) const override;

            SideCrossIterator begin() const;

            SideCrossIterator end() const;
        };

        // PrimeIterator class
        class PrimeIterator : public Iterator {
        private:
            MagicalContainer &container;
            size_t index;

            const PrimeIterator *validateAndCast(const Iterator &other) const;

        public:
            PrimeIterator(MagicalContainer &container);

            PrimeIterator(const PrimeIterator &other);

            ~PrimeIterator() override = default;

            PrimeIterator &operator=(const PrimeIterator &other);

            PrimeIterator &operator++();

            int operator*();

            bool operator==(const Iterator &other) const override;

            bool operator!=(const Iterator &other) const override;

            bool operator<(const Iterator &other) const override;

            bool operator>(const Iterator &other) const override;

            PrimeIterator begin() const;

            PrimeIterator end() const;
        };

    };
}