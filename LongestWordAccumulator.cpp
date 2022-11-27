#include "LongestWordAccumulator.h"
#include <cctype>

namespace longest_word {
namespace {
    auto IsWordCharacter(char character) -> bool
    {
        if (character == '-') {
            return true;
        }
        if (character == '\'') {
            return true;
        }
        if (isalpha(character) != 0) {
            return true;
        }

        return false;
    }
}

LongestWordAccumulator::LongestWordAccumulator()
    : mCurrentWordIndex(0U)
    , mCurrentWordSize(0U)
    , mLongestWordIndex(0U)
    , mLongestWordSize(0U)
    , mIndex(0U)
{
}

auto operator+(LongestWordAccumulator accumulator, char character) -> LongestWordAccumulator
{
    // Check if the current character is part of a "word character".
    if (IsWordCharacter(character)) {
        // Set correct index if there's not ongoing longest word.
        if (accumulator.mCurrentWordSize == 0) {
            accumulator.mCurrentWordIndex = accumulator.mIndex;
        }
        ++accumulator.mCurrentWordSize;
    } else {
        accumulator.mCurrentWordSize = 0;
    }

    // Overwrite longest if current is longer.
    if (accumulator.mCurrentWordSize > accumulator.mLongestWordSize) {
        accumulator.mLongestWordSize = accumulator.mCurrentWordSize;
        accumulator.mLongestWordIndex = accumulator.mCurrentWordIndex;
    }

    ++accumulator.mIndex;
    return accumulator;
}

auto LongestWordAccumulator::Index() const -> size_t
{
    return mLongestWordIndex;
}
auto LongestWordAccumulator::Size() const -> size_t
{
    return mLongestWordSize;
}
}
