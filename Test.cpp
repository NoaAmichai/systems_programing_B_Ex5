#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test MagicalContainer") {
    MagicalContainer container;

    // Test behavior when removing elements while iterating
    SUBCASE("Test behavior when removing elements while iterating") {
        container.addElement(5);
        container.addElement(10);
        container.addElement(15);

        MagicalContainer::AscendingIterator ascIter(container);
        auto it = ascIter.begin();
        ++it; // Move iterator to the second element

        container.removeElement(10); // Remove an element while iterating

        CHECK(*it == 15); // Check if the iterator handles removal correctly
    }

    // Test the container with negative numbers
    SUBCASE("Test container with negative numbers") {
        container.addElement(-10);
        container.addElement(5);
        container.addElement(-5);
        container.addElement(10);
        container.addElement(-20);

        std::vector<int> expected{-20, -10, -5, 5, 10};
        std::vector<int> result;

        MagicalContainer::AscendingIterator ascIter(container);
        for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

TEST_CASE("Additional Tests for MagicalContainer") {
    MagicalContainer container;

    // Test iterator behavior when iterating over an empty container
    SUBCASE("Test iterator behavior when iterating over an empty container") {
        std::vector<int> result;

        MagicalContainer::AscendingIterator ascIter(container);
        for (auto it = ascIter.begin();
             it != ascIter.end(); ++it) {
            result.push_back(*it);
        }

        CHECK(result.empty()); // The iteration should not produce any elements
    }

    // Test iterator behavior when dereferencing an iterator that is out of bounds
    SUBCASE("Test iterator behavior when dereferencing an out-of-bounds iterator") {
        container.addElement(5);
        container.addElement(10);

        MagicalContainer::AscendingIterator ascIter(container);
        auto it = ascIter.begin();
        ++it; // Move to the second element

        // Remove the second element from the container
        container.removeElement(10);

        // Dereference the iterator pointing to the removed element
        CHECK_THROWS(*it); // Dereferencing an out-of-bounds iterator should throw an exception
    }

    // Test iterator behavior when modifying an iterator while it is being used
    SUBCASE("Test iterator behavior when modifying an iterator while it is being used") {
        container.addElement(5);
        container.addElement(10);

        MagicalContainer::AscendingIterator ascIter(container);
        auto it = ascIter.begin();

        container.addElement(15); // Add an element while iterating

        // Attempt to access the newly added element using the iterator
        CHECK_THROWS(*it); // Modifying the iterator while it is being used should throw an exception
    }
}

TEST_CASE("Empty container") {
    MagicalContainer container;

    CHECK(container.size() == 0);

    MagicalContainer::AscendingIterator asc_it(container);
    CHECK(asc_it.begin() == asc_it.end());

    MagicalContainer::SideCrossIterator side_it(container);
    CHECK(side_it.begin() == side_it.end());

    MagicalContainer::PrimeIterator prime_it(container);
    CHECK(prime_it.begin() == prime_it.end());
}

TEST_CASE("Adding and removing elements") {
    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    CHECK(container.size() == 5);

    CHECK_NOTHROW(container.removeElement(3));
    CHECK(container.size() == 4);

    container.removeElement(1);
    CHECK(container.size() == 3);
}

TEST_CASE("Iterators after adding elements") {
    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    MagicalContainer::AscendingIterator asc_it(container);
    CHECK(*asc_it == 1);
    ++asc_it;
    CHECK(*asc_it == 2);

    MagicalContainer::SideCrossIterator side_it(container);
    CHECK(*side_it == 1);
    ++side_it;
    CHECK(*side_it == 14);

    MagicalContainer::PrimeIterator prime_it(container);
    CHECK(*prime_it == 2);
    ++prime_it;
    CHECK(*prime_it == 5);
}

TEST_CASE("Iterators after removing elements") {
    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    container.removeElement(1);
    container.removeElement(14);

    MagicalContainer::AscendingIterator asc_it(container);
    CHECK(*asc_it == 2);
    ++asc_it;
    CHECK(*asc_it == 4);

    MagicalContainer::SideCrossIterator side_it(container);
    CHECK(*side_it == 2);
    ++side_it;
    CHECK(*side_it == 5);

    MagicalContainer::PrimeIterator prime_it(container);
    CHECK(*prime_it == 2);
    ++prime_it;
    CHECK(*prime_it == 5);
}

TEST_CASE("Removing non-existent elements") {
    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    CHECK_THROWS(container.removeElement(4));
    CHECK_THROWS(container.removeElement(5));

    CHECK(container.size() == 3);
}

TEST_CASE("Iterators at the end of the container") {
    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    MagicalContainer::AscendingIterator asc_it(container);
    for (int i = 0; i < 5; ++i) {
        ++asc_it;
    }
    CHECK(asc_it == asc_it.end());

    MagicalContainer::SideCrossIterator side_it(container);
    for (int i = 0; i < 2; ++i) {
        ++side_it;
    }
    CHECK(side_it == side_it.end());

    MagicalContainer::PrimeIterator prime_it(container);
    for (int i = 0; i < 2; ++i) {
        ++prime_it;
    }
    CHECK(prime_it == prime_it.end());
}

TEST_CASE("Iterating beyond the end of the container") {
    MagicalContainer container;

    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);
    container.addElement(14);

    MagicalContainer::AscendingIterator asc_it(container);
    for (int i = 0; i < 6; ++i) {
        ++asc_it;
    }
    CHECK_THROWS(*asc_it);
}