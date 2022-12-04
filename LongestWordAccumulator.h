#ifndef LONGEST_WORD_ACCUMULATOR_H
#define LONGEST_WORD_ACCUMULATOR_H

#include <cstddef>

namespace longest_word {

using std::size_t;
class LongestWordAccumulator {

public:
    LongestWordAccumulator();
    friend LongestWordAccumulator operator+(LongestWordAccumulator accumulator, char character);

    size_t Start() const;
    size_t Size() const;

private:
    size_t mIndex;
    size_t mCurrentWordStart;
    size_t mCurrentWordSize;
    size_t mLongestWordStart;
    size_t mLongestWordSize;
};

}

#endif // !LONGEST_WORD_ACCUMULATOR_H
