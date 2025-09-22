#include "timingFixture.hpp"
#include <chrono>
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>

// function prototypes
std::vector<int> randomVector(std::size_t n);
template<typename T> void sortTest(std::vector<T>& v);


int main()
{
    // create a random vector of 10000 entries
    auto v = randomVector(10000);

    // create a timing fixture for sortTest
    auto fixture = makeTimingFixture<std::chrono::microseconds>(sortTest<std::vector<int>::value_type>, v);

    // run the test once
    auto time = fixture.run();
    std::cout << "Single run time: " << time << " microseconds" << std::endl;

    // run the test 10 times and get the average
    auto avgTime = fixture.average(10);
    std::cout << "Average time over 10 runs: " << avgTime << " microseconds" << std::endl;

    // run the test once
    time = fixture.run();
    std::cout << "Single run time: " << time << " microseconds" << std::endl;

    return 0;
}


/**
 * @brief Return a vector with n random entries.
 * 
 * @param n 
 * @return std::vector<int> 
 */
std::vector<int> randomVector(std::size_t n)
{
    std::vector<int> v(n);
    std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> dist(0, n*10);

    std::generate(v.begin(), v.end(), [&mt, &dist]() { return dist(mt); });

    return v;
}


/**
 * @brief Test the standard sort algorithm.
 * 
 * @tparam T 
 * @param v 
 */
template<typename T>
void sortTest(std::vector<T>& v)
{
    std::sort(v.begin(), v.end());
}