#include "AverageAccumulator.h"
#include "LongestWordAccumulator.h"
#include "catch2/catch_amalgamated.hpp"
#include <numeric>
#include <optional>
#include <string_view>
#include <vector>

namespace tests {
using average_accumulator::AverageAccumulator;
using longest_word::LongestWordAccumulator;

// ╔══════════════════╗
// ║ Basic Accumulate ║
// ╚══════════════════╝
TEST_CASE("Accumulating numbers adds them together.", "[accumulate]")
{
    std::vector<int> vec { 1, 2, 3 };

    int sum = accumulate(vec.cbegin(), vec.cend(), 0);

    REQUIRE(sum == 6);
}

TEST_CASE("Accumulating numbers has an offset.", "[accumulate]")
{
    std::vector<int> vec { 1, 2, 3 };

    int sum = std::accumulate(vec.cbegin(), vec.cend(), 20);

    REQUIRE(sum == 26);
}

TEST_CASE("Accumulate with multiplies results in product.", "[accumulate]")
{
    std::vector<int> vec { 1, 2, 3, 4, 5 };

    int product = std::accumulate(vec.cbegin(), vec.cend(), 1, std::multiplies());

    REQUIRE(product == 120);
}

// ╔════════════════════════╗
// ║ Accumulate With Struct ║
// ╚════════════════════════╝
TEST_CASE("Calculating average of empty vector is nullopt.", "[AverageAccumulator]")
{
    std::vector<float> vec {};

    const auto acc = std::accumulate(vec.cbegin(), vec.cend(), AverageAccumulator());

    REQUIRE(acc.GetAverage() == std::nullopt);
}

TEST_CASE("Calculating average of 1 number results in that same number.", "[AverageAccumulator]")
{
    std::vector<float> vec { 175.F };

    const auto acc = std::accumulate(vec.cbegin(), vec.cend(), AverageAccumulator());

    REQUIRE(acc.GetAverage() == Catch::Approx(175.F));
}

TEST_CASE("Calculating average of some amount of numbers.", "[AverageAccumulator]")
{
    std::vector<float> vec { 1.F, 5.F, 16.F, 22.F, 5.F, -5.F };

    const auto acc = std::accumulate(vec.cbegin(), vec.cend(), AverageAccumulator());

    REQUIRE(acc.GetAverage() == Catch::Approx(7.3333333333F));
}

// ╔════════════════════════╗
// ║ Longest Word In String ║
// ╚════════════════════════╝
TEST_CASE("Longest word of empty string results in empty string.", "[LongestWordAccumulator]")
{
    const std::string_view inputString;

    const auto result = std::accumulate(inputString.cbegin(), inputString.cend(), LongestWordAccumulator());

    const std::string_view subString = inputString.substr(result.Index(), result.Size());

    REQUIRE(subString.empty());
}

TEST_CASE("Longest word at start of scentence.", "[LongestWordAccumulator]")
{
    const std::string_view inputString = "Hippopotomonstro-sesquipedaliophobia is the fear of long words, how ironic!";

    const auto result = std::accumulate(inputString.cbegin(), inputString.cend(), LongestWordAccumulator());

    const std::string_view subString = inputString.substr(result.Index(), result.Size());

    REQUIRE(subString == "Hippopotomonstro-sesquipedaliophobia");
}

TEST_CASE("Longest word at end of scentence.", "[LongestWordAccumulator]")
{
    const std::string_view inputString = "Long live the Emperor!";

    const auto result = std::accumulate(inputString.cbegin(), inputString.cend(), LongestWordAccumulator());

    const std::string_view subString = inputString.substr(result.Index(), result.Size());

    REQUIRE(subString == "Emperor");
}

TEST_CASE("Longest word in middle of scentence.", "[LongestWordAccumulator]")
{
    const std::string_view inputString = "666, The number of the beast!";

    const auto result = std::accumulate(inputString.cbegin(), inputString.cend(), LongestWordAccumulator());

    const std::string_view subString = inputString.substr(result.Index(), result.Size());

    REQUIRE(subString == "number");
}
}
