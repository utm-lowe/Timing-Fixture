# Timing Fixture
This timing fixture is a rather simple template which allows you to run a high
resolution timer on a function which takes a single argument. You pass the 
function and argument into the template and set the resolution to one of
the `std::chrono` resolutions. The fixture can perform either a single run
or an average over several runs. 

In each run, the fixture will make a copy of the argument that you give. That
way you'll always be performing an identical run.  It is recommend that you
perform at least one warmup run before performing the average run in order
to account for any cache loading.

A sample test run which times the `std::sort` function on an array of integers
can be found in the [test.cpp](test.cpp) file. The template itself is contained
in [timingFixture.hpp](timingFixture.hpp). 

Happy timings!