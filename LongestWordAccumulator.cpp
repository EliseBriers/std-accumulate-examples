#include "LongestWordAccumulator.h"
#include <cctype>

namespace longest_word {
namespace {
    bool IsWordCharacter(char character)
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
    : mIndex(0U)
    , mCurrentWordStart(0U)
    , mCurrentWordSize(0U)
    , mLongestWordStart(0U)
    , mLongestWordSize(0U)
{
}

LongestWordAccumulator operator+(LongestWordAccumulator accumulator, char character)
{
    if (IsWordCharacter(character)) {
        const bool foundNewWord = accumulator.mCurrentWordSize == 0;
        if (foundNewWord) {
            accumulator.mCurrentWordStart = accumulator.mIndex;
        }
        ++accumulator.mCurrentWordSize;
    } else {
        accumulator.mCurrentWordSize = 0;
    }

    const bool foundNewLongestWord = accumulator.mCurrentWordSize > accumulator.mLongestWordSize;
    if (foundNewLongestWord) {
        accumulator.mLongestWordSize = accumulator.mCurrentWordSize;
        accumulator.mLongestWordStart = accumulator.mCurrentWordStart;
    }

    ++accumulator.mIndex;
    return accumulator;
}

size_t LongestWordAccumulator::Start() const
{
    return mLongestWordStart;
}

size_t LongestWordAccumulator::Size() const
{
    return mLongestWordSize;
}

}
