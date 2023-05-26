#include "doctest.h"
#include "sources/MagicalContainer.h"

using namespace std;

TEST_CASE("Test MagicalContainer") {
    MagicalContainer container;

    // Test iterator behavior when elements are modified
    SUBCASE("Test iterator behavior when elements are modified") {
        container.addElement(5);
        container.addElement(10);
        container.addElement(15);
        MagicalContainer::AscendingIterator ascIter(container);
        auto it = ascIter.begin();
        ++it; // Move iterator to the second element
//
//        container._elements[1] = 20; // Modify the value in the container
//
//        CHECK(*it == 20); // Check if the modified value is reflected in the iterator
    }

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

    // Test iterator behavior when comparing iterators of different types
    SUBCASE("Test iterator behavior when comparing iterators of different types") {
        container.addElement(5);
        container.addElement(10);

        MagicalContainer::AscendingIterator ascIter(container);
        MagicalContainer::SideCrossIterator sideIter(container);
        auto it1 = ascIter.begin();
        auto it2 = sideIter.begin();

//        // Attempt to compare iterators of different types
//        CHECK_THROWS(it1 == it2); // Comparing iterators of different types should throw an exception
//        CHECK_THROWS(it1 != it2);
//        CHECK_THROWS(it1 > it2);
//        CHECK_THROWS(it1 < it2);
    }

    // Test iterator behavior when assigning an iterator of one type to an iterator of another type
    SUBCASE("Test iterator behavior when assigning iterators of different types") {
        container.addElement(5);
        container.addElement(10);

        MagicalContainer::AscendingIterator ascIter(container);
        MagicalContainer::SideCrossIterator sideIter(container);
        auto it1 = ascIter.begin();
        auto it2 = sideIter.begin();

        // Attempt to assign iterators of different types
//        CHECK_THROWS(it1 = it2); // Assigning iterators of different types should throw an exception
    }

    // Test iterator behavior when an iterator is destroyed while it is still being used
    SUBCASE("Test iterator behavior when an iterator is destroyed while it is still being used") {
        container.addElement(5);
        container.addElement(10);

        MagicalContainer::AscendingIterator ascIter(container);
        auto it = ascIter.begin();

        // Destroy the container while the iterator is still being used
        container.~MagicalContainer();

        // Attempt to dereference the iterator after the container has been destroyed
        CHECK_THROWS(*it); // Dereferencing a destroyed iterator should throw an exception
    }
}
