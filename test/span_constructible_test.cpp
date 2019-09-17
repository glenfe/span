/*
Copyright 2019 Glen Joseph Fernandes
(glenjofe@gmail.com)

Distributed under the Boost Software License, Version 1.0.
(http://www.boost.org/LICENSE_1_0.txt)
*/
#include <boost/span/span.hpp>
#include <boost/core/lightweight_test_trait.hpp>

template<class T>
struct range {
    T* data() {
        return 0;
    }

    const T* data() const {
        return 0;
    }

    std::size_t size() const {
        return 0;
    }
};

struct base { };

struct derived
    : base { };

void test_default()
{
    BOOST_TEST_TRAIT_TRUE((std::is_default_constructible<
        boost::spans::span<int> >));
    BOOST_TEST_TRAIT_TRUE((std::is_default_constructible<
        boost::spans::span<int, 0> >));
    BOOST_TEST_TRAIT_FALSE((std::is_default_constructible<
        boost::spans::span<int, 2> >));
}

void test_data_size()
{
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<int>,
        int*, std::size_t>));
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<const int>,
        int*, std::size_t>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int>,
        int, std::size_t>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int>,
        const int*, std::size_t>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<base>,
        derived*, std::size_t>));
}

void test_first_last()
{
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<int>,
        int*, int*>));
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<int>,
        int*, const int*>));
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<const int>,
        int*, int*>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int>,
        int, int*>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int>,
        const int*, int*>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<base>,
        derived*, derived*>));
}

void test_array()
{
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<int>,
        int(&)[4]>));
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<int, 4>,
        int(&)[4]>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int, 2>,
        int(&)[4]>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int, 4>,
        int(&)[2]>));
}

void test_std_array()
{
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<int>,
        std::array<int, 4>&>));
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<const int>,
        std::array<int, 4>&>));
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<int, 4>,
        std::array<int, 4>&>));
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<const int,
        4>, std::array<int, 4>&>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int>,
        std::array<const int, 4>&>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<base>,
        std::array<derived, 4>&>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int, 2>,
        std::array<int, 4>&>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int, 4>,
        std::array<const int, 4>&>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<base, 4>,
        std::array<derived, 4>&>));
}

void test_const_std_array()
{
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<const int>,
        const std::array<int, 4> >));
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<const int,
        4>, const std::array<int, 4> >));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int>,
        const std::array<int, 4> >));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<const
        base>, const std::array<derived, 4> >));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<const int,
        2>, const std::array<int, 4> >));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int, 4>,
        const std::array<int, 4> >));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<const
        base, 4>, const std::array<derived, 4> >));
}

void test_range()
{
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<int>,
        range<int>&>));
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<const int>,
        range<int>&>));
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<const int>,
        range<int> >));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int>,
        int*>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int>,
        range<int> >));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int>,
        const range<int>&>));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<base>,
        range<derived>&>));
}

void test_span()
{
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<const int>,
        boost::spans::span<int> >));
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<int>,
        boost::spans::span<int, 4> >));
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<int, 4>,
        boost::spans::span<int> >));
    BOOST_TEST_TRAIT_TRUE((std::is_constructible<boost::spans::span<const int,
        4>, boost::spans::span<int, 4> >));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int>,
        boost::spans::span<const int> >));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<base>,
        boost::spans::span<derived> >));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int, 2>,
        boost::spans::span<int, 4> >));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<int, 4>,
        boost::spans::span<const int, 4> >));
    BOOST_TEST_TRAIT_FALSE((std::is_constructible<boost::spans::span<base, 4>,
        boost::spans::span<derived, 4> >));
}

void test_copy()
{
    BOOST_TEST_TRAIT_TRUE((std::is_copy_constructible<
        boost::spans::span<int> >));
    BOOST_TEST_TRAIT_TRUE((std::is_copy_constructible<
        boost::spans::span<int, 4> >));
}

void test_assign()
{
    BOOST_TEST_TRAIT_TRUE((std::is_copy_assignable<
        boost::spans::span<int> >));
    BOOST_TEST_TRAIT_TRUE((std::is_copy_assignable<
        boost::spans::span<int, 4> >));
}

int main()
{
    test_default();
    test_data_size();
    test_first_last();
    test_array();
    test_std_array();
    test_const_std_array();
    test_range();
    test_span();
    test_copy();
    test_assign();
    return boost::report_errors();
}