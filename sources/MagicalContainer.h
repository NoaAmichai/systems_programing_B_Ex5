#pragma once

#include <vector>

class MagicalContainer {
private:
    std::vector<int> _elements;
public:
    MagicalContainer() {};

    void addElement(int element) {};

    void removeElement(int element) {};

    std::size_t size() const { return 0; }

    class AscendingIterator;

    class SideCrossIterator;

    class PrimeIterator;

    class Iterator {
    protected:
        const MagicalContainer& container;
        std::size_t currentIndex;

        Iterator(const MagicalContainer& container)
                : container(container), currentIndex(0) {}

    public:
        virtual ~Iterator() {}

        virtual int operator*() const = 0;
        virtual Iterator& operator++() = 0;
        virtual bool operator==(const Iterator& other) const = 0;
        virtual bool operator!=(const Iterator& other) const = 0;

        Iterator begin();
        Iterator end();
    };


    class AscendingIterator: public Iterator{
    private:
        const MagicalContainer &container;
        int currentIndex;
    public:
        AscendingIterator(const MagicalContainer &container);

        AscendingIterator(const AscendingIterator &other);

        ~AscendingIterator();

        AscendingIterator &operator=(const AscendingIterator &other);

        bool operator==(const AscendingIterator &other) const;

        bool operator>(const AscendingIterator &other) const;

        bool operator<(const AscendingIterator &other) const;

        int operator*() const;

        AscendingIterator &operator++();

        AscendingIterator begin();

        AscendingIterator end();

    };

    class SideCrossIterator :public Iterator{
    private:
        const MagicalContainer &container;
        int forwardIndex;
        int backwardIndex;
        bool moveForward;
    public:
        SideCrossIterator(const MagicalContainer &container);

        SideCrossIterator(const SideCrossIterator &other);

        ~SideCrossIterator();

        SideCrossIterator &operator=(const SideCrossIterator &other);

        bool operator==(const SideCrossIterator &other) const;


        bool operator>(const SideCrossIterator &other) const;

        bool operator<(const SideCrossIterator &other) const;

        int operator*() const;

        SideCrossIterator &operator++();

        SideCrossIterator begin();

        SideCrossIterator end();
    };

    class PrimeIterator: public Iterator{
    private:
        const MagicalContainer &container;
        int currentIndex;

        bool isPrime(int number) const;

    public:
        PrimeIterator(const MagicalContainer &container);

        PrimeIterator(const PrimeIterator &other);

        ~PrimeIterator();

        PrimeIterator &operator=(const PrimeIterator &other);

        bool operator==(const PrimeIterator &other) const;

        bool operator>(const PrimeIterator &other) const;

        bool operator<(const PrimeIterator &other) const;

        int operator*() const;

        PrimeIterator &operator++();

        PrimeIterator begin();

        PrimeIterator end();
    };

};
