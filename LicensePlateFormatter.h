#ifndef LICENCE_PLATE_FORMATTER_H
#define LICENCE_PLATE_FORMATTER_H

#include <string>
namespace license_plate {
using std::size_t;

enum class CharacterType {
    kDigit,
    kLetter,
    kInvalid
};

class LicensePlateFormatter {
public:
    LicensePlateFormatter();

    friend LicensePlateFormatter operator+(LicensePlateFormatter&& formatter, char character);

    std::string Result() const;

    // Ensure copy operators are disabled for performance reasons.
    LicensePlateFormatter(const LicensePlateFormatter& other) = delete;
    LicensePlateFormatter(LicensePlateFormatter&& other) = default;
    LicensePlateFormatter& operator=(const LicensePlateFormatter& other) = delete;
    LicensePlateFormatter& operator=(LicensePlateFormatter&& other) noexcept = default;

private:
    std::string mResult;
    CharacterType mLastChatacter;
    size_t mConsecutiveCharacterCount;
};

}

#endif // !LICENCE_PLATE_FORMATTER_H
