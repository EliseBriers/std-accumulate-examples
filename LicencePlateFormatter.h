#ifndef LICENCE_PLATE_FORMATTER_H
#define LICENCE_PLATE_FORMATTER_H

#include <string>
namespace licence_plate {
using std::size_t;

enum class CharacterType {
    kDigit,
    kLetter,
    kInvalidCharacter
};

class LicencePlateFormatter {
public:
    LicencePlateFormatter();

    friend auto operator+(LicencePlateFormatter&& formatter, char character) -> LicencePlateFormatter;

    [[nodiscard]] auto Result() const -> std::string;

    // Ensure copy operators are disabled for performance reasons.
    LicencePlateFormatter(const LicencePlateFormatter& other) = delete;
    LicencePlateFormatter(LicencePlateFormatter&& other) = default;
    auto operator=(const LicencePlateFormatter& other) -> LicencePlateFormatter& = delete;
    auto operator=(LicencePlateFormatter&& other) noexcept -> LicencePlateFormatter& = default;

private:
    std::string mResult;
    CharacterType mLastChatacter;
    size_t mConsecutiveCharacterCount;
};

}

#endif // !LICENCE_PLATE_FORMATTER_H
