#pragma once

#include <vector>

class MagicalContainer {
private:
    std::vector<int> _elements;
public:
    MagicalContainer() {};

    void addElement(int element) {};

    void removeElement(int element) {};

    std::size_t size() const { return _elements.size(); }

    class AscendingIterator;

    class SideCrossIterator;

    class PrimeIterator;

    class Iterator {
    protected:
        const MagicalContainer &container;
        std::size_t currentIndex;

        Iterator(const MagicalContainer &container)
                : container(container), currentIndex(0) {}

    public:
        virtual ~Iterator() = default;

        virtual int operator*() const = 0;

        virtual Iterator &operator++() = 0;

        virtual bool operator==(const Iterator &other) const = 0;

        virtual bool operator!=(const Iterator &other); //? TODO CHECK
//
//        Iterator begin();
//        Iterator end();
    };


    class AscendingIterator : public Iterator {
    public:
        AscendingIterator(const MagicalContainer &container);

        AscendingIterator(const AscendingIterator &other);

        ~AscendingIterator() override;

        AscendingIterator &operator=(const AscendingIterator &other);

        bool operator==(const Iterator &other) const override;

        bool operator>(const AscendingIterator &other) const;

        bool operator<(const AscendingIterator &other) const;

        int operator*() const override;

        AscendingIterator &operator++() override;

        AscendingIterator begin();

        AscendingIterator end();

    };

    class SideCrossIterator : public Iterator {
    private:
        int forwardIndex;
        int backwardIndex;
        bool moveForward;
    public:
        SideCrossIterator(const MagicalContainer &container);

        SideCrossIterator(const SideCrossIterator &other);

        ~SideCrossIterator() override;

        SideCrossIterator &operator=(const SideCrossIterator &other);

        bool operator==(const Iterator &other) const override;

        bool operator>(const SideCrossIterator &other) const;

        bool operator<(const SideCrossIterator &other) const;

        int operator*() const override;

        SideCrossIterator &operator++() override;

        SideCrossIterator begin();

        SideCrossIterator end();
    };

    class PrimeIterator : public Iterator {
    private:
        bool isPrime(int number) const;

    public:
        PrimeIterator(const MagicalContainer &container);

        PrimeIterator(const PrimeIterator &other);

        ~PrimeIterator() override;

        PrimeIterator &operator=(const PrimeIterator &other);

        bool operator==(const Iterator &other) const override;

        bool operator>(const PrimeIterator &other) const;

        bool operator<(const PrimeIterator &other) const;

        int operator*() const override;

        PrimeIterator &operator++() override;

        PrimeIterator begin();

        PrimeIterator end();
    };

};
