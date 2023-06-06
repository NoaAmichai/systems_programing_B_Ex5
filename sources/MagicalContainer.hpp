#pragma once

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

        //for tidy
        MagicalContainer(const MagicalContainer &other) = delete;
        MagicalContainer &operator=(const MagicalContainer &other) = default;
        MagicalContainer(MagicalContainer &&other) = delete;
        MagicalContainer &operator=(MagicalContainer &&other) = delete;

        class Iterator {
        protected:
            MagicalContainer &container;  // NOLINT(cppcoreguidelines-non-private-member-variables-in-classes)
            size_t index; // NOLINT(cppcoreguidelines-non-private-member-variables-in-classes)
        public:
            Iterator(const MagicalContainer &container);

            virtual ~Iterator() = default;
            Iterator(const Iterator &other) = default;
            Iterator(Iterator &&other) = default;

            Iterator &operator=(const Iterator &other) = delete;
            Iterator &operator=(Iterator &&other) = delete;

            bool operator==(const Iterator &other) const;
            bool operator!=(const Iterator &other) const;
            bool operator<(const Iterator &other) const;
            bool operator>(const Iterator &other) const;
        };


        // AscendingIterator class
        class AscendingIterator : public Iterator {
        public:
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);
            ~AscendingIterator() override = default;

            AscendingIterator &operator=(const AscendingIterator &other);

            AscendingIterator &operator++();

            int operator*();

            AscendingIterator begin() const;
            AscendingIterator end() const;

            //tidy
            AscendingIterator(AscendingIterator &&other) = default;
            AscendingIterator &operator=(AscendingIterator &&other) = delete;

        };

        // SideCrossIterator class
        class SideCrossIterator : public Iterator {
        public:
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);
            ~SideCrossIterator() override = default;

            SideCrossIterator &operator=(const SideCrossIterator &other);

            SideCrossIterator &operator++();

            int operator*();

            SideCrossIterator begin() const;
            SideCrossIterator end() const;

            //tidy
            SideCrossIterator(SideCrossIterator &&other) = default;
            SideCrossIterator &operator=(SideCrossIterator &&other) = delete;
        };

        // PrimeIterator class
        class PrimeIterator : public Iterator {
        public:
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);
            ~PrimeIterator() override = default;

            PrimeIterator &operator=(const PrimeIterator &other);

            PrimeIterator &operator++();

            int operator*();

            PrimeIterator begin() const;
            PrimeIterator end() const;

            //tidy
            PrimeIterator(PrimeIterator &&other) = default;
            PrimeIterator &operator=(PrimeIterator &&other) = delete;
        };
    };
}