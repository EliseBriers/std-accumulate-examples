#ifndef AVERAGE_ACCUMULATOR_H
#define AVERAGE_ACCUMULATOR_H
#include <cstddef>
#include <optional>

namespace average_accumulator {
using std::size_t;

class AverageAccumulator {
private:
    size_t mAmount;
    float mTotal;

public:
    AverageAccumulator();

    auto GetAverage() -> std::optional<float>;
    friend auto operator+(AverageAccumulator accumulator, float value) -> AverageAccumulator;
};
} // namespace average_accumulator

#endif
