/*
Copyright 2019 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost/span/span.hpp>
#include <boost/core/lightweight_test_trait.hpp>

void test_element_type()
{
    BOOST_TEST_TRAIT_SAME(int,
        boost::spans::span<int>::element_type);
    BOOST_TEST_TRAIT_SAME(char,
        boost::spans::span<char>::element_type);
}

void test_value_type()
{
    BOOST_TEST_TRAIT_SAME(char,
        boost::spans::span<char>::value_type);
    BOOST_TEST_TRAIT_SAME(int,
        boost::spans::span<int>::value_type);
    BOOST_TEST_TRAIT_SAME(int,
        boost::spans::span<const int>::value_type);
    BOOST_TEST_TRAIT_SAME(int,
        boost::spans::span<volatile int>::value_type);
    BOOST_TEST_TRAIT_SAME(int,
        boost::spans::span<const volatile int>::value_type);
}

void test_size_type()
{
    BOOST_TEST_TRAIT_SAME(std::size_t,
        boost::spans::span<char>::size_type);
    BOOST_TEST_TRAIT_SAME(std::size_t,
        boost::spans::span<int>::size_type);
}

void test_difference_type()
{
    BOOST_TEST_TRAIT_SAME(std::ptrdiff_t,
        boost::spans::span<char>::difference_type);
    BOOST_TEST_TRAIT_SAME(std::ptrdiff_t,
        boost::spans::span<int>::difference_type);
}

void test_pointer()
{
    BOOST_TEST_TRAIT_SAME(char*,
        boost::spans::span<char>::pointer);
    BOOST_TEST_TRAIT_SAME(int*,
        boost::spans::span<int>::pointer);
}

void test_const_pointer()
{
    BOOST_TEST_TRAIT_SAME(const char*,
        boost::spans::span<char>::const_pointer);
    BOOST_TEST_TRAIT_SAME(const int*,
        boost::spans::span<int>::const_pointer);
}

void test_reference()
{
    BOOST_TEST_TRAIT_SAME(char&,
        boost::spans::span<char>::reference);
    BOOST_TEST_TRAIT_SAME(int&,
        boost::spans::span<int>::reference);
}

void test_const_reference()
{
    BOOST_TEST_TRAIT_SAME(const char&,
        boost::spans::span<char>::const_reference);
    BOOST_TEST_TRAIT_SAME(const int&,
        boost::spans::span<int>::const_reference);
}

void test_iterator()
{
    BOOST_TEST_TRAIT_SAME(char*,
        boost::spans::span<char>::iterator);
    BOOST_TEST_TRAIT_SAME(int*,
        boost::spans::span<int>::iterator);
}

void test_const_iterator()
{
    BOOST_TEST_TRAIT_SAME(const char*,
        boost::spans::span<char>::const_iterator);
    BOOST_TEST_TRAIT_SAME(const int*,
        boost::spans::span<int>::const_iterator);
}

void test_reverse_iterator()
{
    BOOST_TEST_TRAIT_SAME(std::reverse_iterator<char*>,
        boost::spans::span<char>::reverse_iterator);
    BOOST_TEST_TRAIT_SAME(std::reverse_iterator<int*>,
        boost::spans::span<int>::reverse_iterator);
}

void test_const_reverse_iterator()
{
    BOOST_TEST_TRAIT_SAME(std::reverse_iterator<const char*>,
        boost::spans::span<char>::const_reverse_iterator);
    BOOST_TEST_TRAIT_SAME(std::reverse_iterator<const int*>,
        boost::spans::span<int>::const_reverse_iterator);
}

int main()
{
    test_element_type();
    test_value_type();
    test_size_type();
    test_difference_type();
    test_pointer();
    test_const_pointer();
    test_reference();
    test_const_reference();
    test_iterator();
    test_const_iterator();
    test_reverse_iterator();
    test_const_reverse_iterator();
    return boost::report_errors();
}
