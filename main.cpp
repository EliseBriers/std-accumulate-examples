#include "AverageAccumulator.h"
#include "LicensePlateFormatter.h"
#include "LongestWordAccumulator.h"
#include "catch2/catch_amalgamated.hpp"

#include <complex>
#include <numeric>
#include <optional>
#include <string_view>
#include <vector>

namespace tests {
using average_accumulator::AverageAccumulator;
using license_plate::LicensePlateFormatter;
using longest_word::LongestWordAccumulator;

// ╔══════════════════╗
// ║ Basic Accumulate ║
// ╚══════════════════╝
TEST_CASE("Accumulating numbers adds them together.", "[accumulate]")
{
    const std::vector<int> vec { 1, 2, 3 };

    const int startValue = 0;
    const int sum = std::accumulate(vec.cbegin(), vec.cend(), startValue);

    REQUIRE(sum == 6);
}

TEST_CASE("Accumulating numbers has an offset.", "[accumulate]")
{
    const std::vector<int> vec { 1, 2, 3 };

    const int startValue = 20;
    const int sum = std::accumulate(vec.cbegin(), vec.cend(), startValue);

    REQUIRE(sum == 26);
}

TEST_CASE("Accumulate with multiplies results in product.", "[accumulate]")
{
    const std::vector<int> vec { 1, 2, 3, 4, 5 };

    const int startValue = 1;
    const int product = std::accumulate(vec.cbegin(), vec.cend(), startValue, std::multiplies());

    REQUIRE(product == 120);
}

// ╔════════════════════════════════╗
// ║ Accumulate With Different Type ║
// ╚════════════════════════════════╝
TEST_CASE("Accumulate with complex number.", "[accumulate]")
{
    const std::vector<float> vec { 0.F, 5.F, 2.F };

    const std::complex startValue(0.F, 12.F);
    const std::complex result = std::accumulate(vec.cbegin(), vec.cend(), startValue);

    REQUIRE(result.real() == Catch::Approx(7.F));
    REQUIRE(result.imag() == Catch::Approx(12.F));
}

// ╔═══════════════════════╗
// ║ Accumulate With Class ║
// ╚═══════════════════════╝
TEST_CASE("Calculating average of empty vector is nullopt.", "[AverageAccumulator]")
{
    const std::vector<float> vec {};

    const AverageAccumulator acc = std::accumulate(vec.cbegin(), vec.cend(), AverageAccumulator());

    REQUIRE(acc.GetAverage() == std::nullopt);
}

TEST_CASE("Calculating average of 1 number results in that same number.", "[AverageAccumulator]")
{
    const std::vector<float> vec { 175.F };

    const AverageAccumulator acc = std::accumulate(vec.cbegin(), vec.cend(), AverageAccumulator());

    REQUIRE(acc.GetAverage().has_value());
    REQUIRE(acc.GetAverage().value() == 175.F);
}

TEST_CASE("Calculating average of some amount of numbers.", "[AverageAccumulator]")
{
    const std::vector<float> vec { 1.F, 5.F, 16.F, 22.F, 5.F, -5.F };

    const AverageAccumulator acc = std::accumulate(vec.cbegin(), vec.cend(), AverageAccumulator());

    REQUIRE(acc.GetAverage().has_value());
    REQUIRE(acc.GetAverage().value() == Catch::Approx(7.3333333333F));
}

// ╔════════════════════════╗
// ║ Longest Word In String ║
// ╚════════════════════════╝
TEST_CASE("Longest word of empty string results in empty string.", "[LongestWordAccumulator]")
{
    const std::string_view inputString;

    const LongestWordAccumulator result = std::accumulate(inputString.cbegin(), inputString.cend(), LongestWordAccumulator());

    const std::string_view subString = inputString.substr(result.Start(), result.Size());

    REQUIRE(subString.empty());
}

TEST_CASE("Longest word at start of scentence.", "[LongestWordAccumulator]")
{
    const std::string_view inputString = "Hippopotomonstro-sesquipedaliophobia is the fear of long words, how ironic!";

    const LongestWordAccumulator result = std::accumulate(inputString.cbegin(), inputString.cend(), LongestWordAccumulator());

    const std::string_view subString = inputString.substr(result.Start(), result.Size());

    REQUIRE(subString == "Hippopotomonstro-sesquipedaliophobia");
}

TEST_CASE("Longest word at end of scentence.", "[LongestWordAccumulator]")
{
    const std::string_view inputString = "Long live the Emperor!";

    const LongestWordAccumulator result = std::accumulate(inputString.cbegin(), inputString.cend(), LongestWordAccumulator());

    const std::string_view subString = inputString.substr(result.Start(), result.Size());

    REQUIRE(subString == "Emperor");
}

TEST_CASE("Longest word in middle of scentence.", "[LongestWordAccumulator]")
{
    const std::string_view inputString = "666, the number of the beast!";

    const LongestWordAccumulator result = std::accumulate(inputString.cbegin(), inputString.cend(), LongestWordAccumulator());

    const std::string_view longestWord = inputString.substr(result.Start(), result.Size());

    REQUIRE(longestWord == "number");
}

// ╔══════════════════════╗
// ║ Format License Plate ║
// ╚══════════════════════╝
// Note: I just randomly typed some license plates, any resemblance with a real world license plate is a coincidence.
TEST_CASE("Formatting empty string results in empty licence plate.", "[LicencePlateFormatter]")
{
    const std::string_view inputString;

    const LicensePlateFormatter result = std::accumulate(inputString.cbegin(), inputString.cend(), LicensePlateFormatter());

    REQUIRE(result.Result().empty());
}

TEST_CASE("Formatting invalid string results in empty licence plate", "[LicencePlateFormatter]")
{
    const std::string_view inputString = "*-===>? !";

    const LicensePlateFormatter result = std::accumulate(inputString.cbegin(), inputString.cend(), LicensePlateFormatter());

    REQUIRE(result.Result().empty());
}

TEST_CASE("Formatting simple string with separation by type.", "[LicencePlateFormatter]")
{
    const std::string_view inputString = "SLy12Sg";

    const LicensePlateFormatter result = std::accumulate(inputString.cbegin(), inputString.cend(), LicensePlateFormatter());

    REQUIRE(result.Result() == "SLY-12-SG");
}

TEST_CASE("Formatting simple string with separation by size.", "[LicencePlateFormatter]")
{
    const std::string_view inputString = "Hello World";

    const LicensePlateFormatter result = std::accumulate(inputString.cbegin(), inputString.cend(), LicensePlateFormatter());

    REQUIRE(result.Result() == "HEL-LOW-ORL-D");
}

TEST_CASE("Formatting string with separation by type and size.", "[LicencePlateFormatter]")
{
    const std::string_view inputString = "12pksbl";

    const LicensePlateFormatter result = std::accumulate(inputString.cbegin(), inputString.cend(), LicensePlateFormatter());

    REQUIRE(result.Result() == "12-PKS-BL");
}
}
