#ifndef LONGEST_WORD_ACCUMULATOR_H
#define LONGEST_WORD_ACCUMULATOR_H

#include <cstddef>

namespace longest_word {

using std::size_t;
class LongestWordAccumulator {

public:
    LongestWordAccumulator();
    friend auto operator+(LongestWordAccumulator accumulator, char character) -> LongestWordAccumulator;

    [[nodiscard]] auto Index() const -> size_t;
    [[nodiscard]] auto Size() const -> size_t;

private:
    size_t mCurrentWordIndex;
    size_t mCurrentWordSize;
    size_t mLongestWordIndex;
    size_t mLongestWordSize;
    size_t mIndex;
};

}

#endif // !LONGEST_WORD_ACCUMULATOR_H
