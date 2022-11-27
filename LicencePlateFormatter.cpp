#include "LicencePlateFormatter.h"
#include "LongestWordAccumulator.h"
#include <cctype>

namespace licence_plate {
namespace {
    auto GetCharacterTypeOf(char character) -> CharacterType
    {
        if (isalpha(character) != 0) {
            return CharacterType::kLetter;
        }
        if (isdigit(character) != 0) {
            return CharacterType::kDigit;
        }

        return CharacterType::kInvalidCharacter;
    }
}

LicencePlateFormatter::LicencePlateFormatter()
    : mLastChatacter(CharacterType::kInvalidCharacter)
    , mConsecutiveCharacterCount(0U)
{
    mResult.resize(10U);
}

auto operator+(LicencePlateFormatter&& formatter, char character) -> LicencePlateFormatter
{
    CharacterType characterType = GetCharacterTypeOf(character);

    // Early return for invalid characters.
    if (characterType == CharacterType::kInvalidCharacter) {
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

[[nodiscard]] auto LicencePlateFormatter::Result() const -> std::string
{
    return mResult;
}

}
