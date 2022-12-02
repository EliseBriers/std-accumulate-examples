#include "AverageAccumulator.h"
#include <optional>

namespace average_accumulator {

AverageAccumulator::AverageAccumulator()
    : mTotal(0.F)
    , mAmount(0U)
{
}

AverageAccumulator operator+(AverageAccumulator accumulator, float value)
{
    ++accumulator.mAmount;
    accumulator.mTotal += value;

    return accumulator;
}

std::optional<float> AverageAccumulator::GetAverage() const
{
    if (mAmount == 0) {
        return std::nullopt;
    }
    return mTotal / mAmount;
}

} // namespace average_accumulator
