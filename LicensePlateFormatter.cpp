#include "LicensePlateFormatter.h"
#include "LongestWordAccumulator.h"
#include <cctype>

namespace license_plate {
namespace {
    CharacterType GetCharacterTypeOf(char character)
    {
        if (isalpha(character) != 0) {
            return CharacterType::kLetter;
        }
        if (isdigit(character) != 0) {
            return CharacterType::kDigit;
        }

        return CharacterType::kInvalid;
    }
}

LicensePlateFormatter::LicensePlateFormatter()
    : mLastChatacter(CharacterType::kInvalid)
    , mConsecutiveCharacterCount(0U)
{
    mResult.reserve(10U);
}

LicensePlateFormatter operator+(LicensePlateFormatter&& formatter, char character)
{
    const CharacterType characterType = GetCharacterTypeOf(character);

    // Early return for invalid characters.
    if (characterType == CharacterType::kInvalid) {
        return formatter;
    }

    // Check if character type switch has occured.
    if (characterType != formatter.mLastChatacter || formatter.mConsecutiveCharacterCount >= 3) {
        // Prevent hyphen at start of string.
        if (!formatter.mResult.empty()) {
            formatter.mResult += '-';
        }
        formatter.mLastChatacter = characterType;
        formatter.mConsecutiveCharacterCount = 0;
    }

    ++formatter.mConsecutiveCharacterCount;
    formatter.mResult += toupper(character);

    return formatter;
}

std::string LicensePlateFormatter::Result() const
{
    return mResult;
}

}
