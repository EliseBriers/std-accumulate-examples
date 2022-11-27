#ifndef LICENCE_PLATE_FORMATTER_H
#define LICENCE_PLATE_FORMATTER_H

#include <string>
namespace license_plate {
using std::size_t;

enum class CharacterType {
    kDigit,
    kLetter,
    kInvalidCharacter
};

class LicensePlateFormatter {
public:
    LicensePlateFormatter();

    friend auto operator+(LicensePlateFormatter&& formatter, char character) -> LicensePlateFormatter;

    [[nodiscard]] auto Result() const -> std::string;

    // Ensure copy operators are disabled for performance reasons.
    LicensePlateFormatter(const LicensePlateFormatter& other) = delete;
    LicensePlateFormatter(LicensePlateFormatter&& other) = default;
    auto operator=(const LicensePlateFormatter& other) -> LicensePlateFormatter& = delete;
    auto operator=(LicensePlateFormatter&& other) noexcept -> LicensePlateFormatter& = default;

private:
    std::string mResult;
    CharacterType mLastChatacter;
    size_t mConsecutiveCharacterCount;
};

}

#endif // !LICENCE_PLATE_FORMATTER_H
