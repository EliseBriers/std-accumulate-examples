#ifndef AVERAGE_ACCUMULATOR_H
#define AVERAGE_ACCUMULATOR_H
#include <cstddef>
#include <optional>

namespace average_accumulator {
using std::size_t;

class AverageAccumulator {
public:
    AverageAccumulator();

    [[nodiscard]] auto GetAverage() const -> std::optional<float>;

    // Operator will automatically be detected by std::accumulate.
    friend auto operator+(AverageAccumulator accumulator, float value) -> AverageAccumulator;

private:
    size_t mAmount;
    float mTotal;
};

} // namespace average_accumulator

#endif // !AVERAGE_ACCUMULATOR_H
