#include "AverageAccumulator.h"

namespace average_accumulator {

AverageAccumulator::AverageAccumulator()
    : mTotal(0.F)
    , mAmount(0U)
{
}
auto operator+(AverageAccumulator accumulator, float value) -> AverageAccumulator
{
    ++accumulator.mAmount;
    accumulator.mTotal += value;

    return accumulator;
}
} // namespace average_accumulator
