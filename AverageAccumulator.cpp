#include "AverageAccumulator.h"
#include <optional>

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

auto AverageAccumulator::GetAverage() const -> std::optional<float>
{
    if (mAmount == 0) {
        return std::nullopt;
    }
    return mTotal / mAmount;
}

} // namespace average_accumulator
