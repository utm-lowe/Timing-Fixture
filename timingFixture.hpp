/**
 * @file timingFixture.hpp
 * @author Bob Lowe <rlowe8@utm.edu
 * @brief This is a template for a high-resolution timing fixture.
 * @version 0.1
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include <chrono>


template<typename Resolution, typename Function, typename Argument>
class TimingFixture
{
public:
    TimingFixture(Function func, Argument arg) : func(func), arg(arg) {}

    unsigned long long run() {
        // copy the argument
        Argument argcopy(arg);

        // Perform the run 
        auto start = std::chrono::high_resolution_clock::now();
        func(arg);
        auto end = std::chrono::high_resolution_clock::now();

        // get the duration
        auto duration = std::chrono::duration_cast<Resolution>(end-start);
        return duration.count();
    }


    unsigned long long average(unsigned int count) {
        unsigned long long total=0;

        // run for count number of times, accumulating total
        for(int i=0; i<count; i++) {
            total += run();
        }

        // return the average
        return total / count;
    }
private:
    Function func;
    Argument arg;
};


template<typename Resolution, typename Function, typename Argument>
TimingFixture<Resolution, Function, Argument> makeTimingFixture(Function func, Argument arg) 
{
    return TimingFixture<Resolution, Function, Argument>(func, arg);
}