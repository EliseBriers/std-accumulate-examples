#include "catch2/catch_amalgamated.hpp"

namespace tests {
using std::accumulate;
using std::multiplies;

TEST_CASE("Basic accumulate", "[accumulate]")
{
    // Artifact: Sum
    {
        std::vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        int sum = accumulate(vec.cbegin(), vec.cend(), 0);

        REQUIRE(sum == 55);
    }

    // Artifact: Sum with offset
    {
        std::vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        int sum = accumulate(vec.cbegin(), vec.cend(), 20);

        REQUIRE(sum == 75);
    }

    // Artifact: Multiplication
    {
        std::vector<int> vec { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        int product = accumulate(vec.cbegin(), vec.cend(), 1, multiplies());

        REQUIRE(product == 3628800);
    }
}
}
