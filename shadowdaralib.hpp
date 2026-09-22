#pragma once

// This Shadowdara Personal Library is a collection of utility
// functions and classes for various purposes, including
// configuration management, file loading, rendering, and string
// manipulation. It is designed to be used in conjunction with SDL2,
// OpenGL, and ImGui for creating graphical applications.

// for C++ 20


#pragma region includes

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <cstdint>
#include <stdexcept>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <fstream>

#pragma endregion

#pragma region Macros

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#pragma endregion

#pragma region colors

// Header File with all ANSI Colors as Macros
// by Shadowdara
//
// licensed under Appache 2.0
//
// by
// https://github.com/ShadowDara/samengine
//
//
// More Infos
// https://shadowdara.github.io/docs#/cpplibs/ansicolors


#if USE_COLORS_AS_MACRO == 0
#if RM_ANSI_FROM_COLORNAME == 0

    // Use as Raylib Macros

#define ANSI_END 				    "\x1b[0m"
#define	ANSI_BOLD			    	"\x1b[1m"

#define	ANSI_ITALIC				    "\x1b[3m"
#define	ANSI_UNDERLINED			    "\x1b[4m"

#define	ANSI_REVERSE_TEXT		    "\x1b[7m"

#define	ANSI_NOT_UNDERLINED		    "\x1b[24m"

#define	ANSI_POSITIVE_TEXT		    "\x1b[27m"

#define	ANSI_BLACK			    	"\x1b[30m"
#define	ANSI_RED					"\x1b[31m"
#define	ANSI_GREEN			    	"\x1b[32m"
#define	ANSI_YELLOW			    	"\x1b[33m"
#define	ANSI_BLUE			    	"\x1b[34m"
#define	ANSI_PURPLE			    	"\x1b[35m"
#define	ANSI_CYAN			    	"\x1b[36m"
#define	ANSI_WHITE			    	"\x1b[37m"

#define	ANSI_BG_BLACK		    	"\x1b[40m"
#define	ANSI_BG_RED			    	"\x1b[41m"
#define	ANSI_BG_GREEN			    "\x1b[42m"
#define	ANSI_BG_YELLOW			    "\x1b[43m"
#define	ANSI_BG_BLUE				"\x1b[44m"
#define	ANSI_BG_PURPLE			    "\x1b[45m"
#define	ANSI_BG_CYAN		   		"\x1b[46m"
#define	ANSI_BG_WHITE			    "\x1b[47m"

#define	ANSI_BRIGHT_BLACK	    	"\x1b[90m"
#define	ANSI_BRIGHT_RED		    	"\x1b[91m"
#define	ANSI_BRIGHT_GREEM		    "\x1b[92m"
#define	ANSI_BRIGHT_YELLOW	    	"\x1b[93m"
#define	ANSI_BRIGHT_BLUE			"\x1b[94m"
#define	ANSI_BRIGHT_PURPLE	    	"\x1b[95m"
#define	ANSI_BRIGHT_CYAN			"\x1b[96m"
#define	ANSI_BRIGHT_WHITE		    "\x1b[97m"

#define	ANSI_BG_BRIGHT_BLACK		"\x1b[100m"
#define	ANSI_BG_BRIGHT_RED		    "\x1b[101m"
#define	ANSI_BG_BRIGHT_GREEM		"\x1b[102m"
#define	ANSI_BG_BRIGHT_YELLOW	    "\x1b[103m"
#define	ANSI_BG_BRIGHT_BLUE		    "\x1b[104m"
#define	ANSI_BG_BRIGHT_PURPLE	    "\x1b[105m"
#define	ANSI_BG_BRIGHT_CYAN		    "\x1b[106m"
#define	ANSI_BG_BRIGHT_WHITE		"\x1b[107m"

#else

    // Use as Normal Macros

#define END 				"\x1b[0m"
#define	BOLD				"\x1b[1m"

#define	ITALIC				"\x1b[3m"
#define	UNDERLINED			"\x1b[4m"

#define	REVERSE_TEXT		"\x1b[7m"

#define	NOT_UNDERLINED		"\x1b[24m"

#define	POSITIVE_TEXT		"\x1b[27m"

#define	BLACK				"\x1b[30m"
#define	RED					"\x1b[31m"
#define	GREEN				"\x1b[32m"
#define	YELLOW				"\x1b[33m"
#define	BLUE				"\x1b[34m"
#define	PURPLE				"\x1b[35m"
#define	CYAN				"\x1b[36m"
#define	WHITE				"\x1b[37m"

#define	BG_BLACK			"\x1b[40m"
#define	BG_RED				"\x1b[41m"
#define	BG_GREEN			"\x1b[42m"
#define	BG_YELLOW			"\x1b[43m"
#define	BG_BLUE				"\x1b[44m"
#define	BG_PURPLE			"\x1b[45m"
#define	BG_CYAN				"\x1b[46m"
#define	BG_WHITE			"\x1b[47m"

#define	BRIGHT_BLACK		"\x1b[90m"
#define	BRIGHT_RED			"\x1b[91m"
#define	BRIGHT_GREEM		"\x1b[92m"
#define	BRIGHT_YELLOW		"\x1b[93m"
#define	BRIGHT_BLUE			"\x1b[94m"
#define	BRIGHT_PURPLE		"\x1b[95m"
#define	BRIGHT_CYAN			"\x1b[96m"
#define	BRIGHT_WHITE		"\x1b[97m"

#define	BG_BRIGHT_BLACK		"\x1b[100m"
#define	BG_BRIGHT_RED		"\x1b[101m"
#define	BG_BRIGHT_GREEM		"\x1b[102m"
#define	BG_BRIGHT_YELLOW	"\x1b[103m"
#define	BG_BRIGHT_BLUE		"\x1b[104m"
#define	BG_BRIGHT_PURPLE	"\x1b[105m"
#define	BG_BRIGHT_CYAN		"\x1b[106m"
#define	BG_BRIGHT_WHITE		"\x1b[107m"

#endif

// Use as const

#else

    // Use as Const

#if RM_ANSI_FROM_COLORNAME == 1

    // Use as Raylib Name Const

inline constexpr const char* ANSI_END = "\x1b[0m";
inline constexpr const char* ANSI_BOLD = "\x1b[1m";

inline constexpr const char* ANSI_ITALIC = "\x1b[3m";
inline constexpr const char* ANSI_UNDERLINED = "\x1b[4m";

inline constexpr const char* ANSI_REVERSE_TEXT = "\x1b[7m";

inline constexpr const char* ANSI_NOT_UNDERLINED = "\x1b[24m";

inline constexpr const char* ANSI_POSITIVE_TEXT = "\x1b[27m";

inline constexpr const char* ANSI_BLACK = "\x1b[30m";
inline constexpr const char* ANSI_RED = "\x1b[31m";
inline constexpr const char* ANSI_GREEN = "\x1b[32m";
inline constexpr const char* ANSI_YELLOW = "\x1b[33m";
inline constexpr const char* ANSI_BLUE = "\x1b[34m";
inline constexpr const char* ANSI_PURPLE = "\x1b[35m";
inline constexpr const char* ANSI_CYAN = "\x1b[36m";
inline constexpr const char* ANSI_WHITE = "\x1b[37m";

inline constexpr const char* ANSI_BG_BLACK = "\x1b[40m";
inline constexpr const char* ANSI_BG_RED = "\x1b[41m";
inline constexpr const char* ANSI_BG_GREEN = "\x1b[42m";
inline constexpr const char* ANSI_BG_YELLOW = "\x1b[43m";
inline constexpr const char* ANSI_BG_BLUE = "\x1b[44m";
inline constexpr const char* ANSI_BG_PURPLE = "\x1b[45m";
inline constexpr const char* ANSI_BG_CYAN = "\x1b[46m";
inline constexpr const char* ANSI_BG_WHITE = "\x1b[47m";

inline constexpr const char* ANSI_BRIGHT_BLACK = "\x1b[90m";
inline constexpr const char* ANSI_BRIGHT_RED = "\x1b[91m";
inline constexpr const char* ANSI_BRIGHT_GREEN = "\x1b[92m";
inline constexpr const char* ANSI_BRIGHT_YELLOW = "\x1b[93m";
inline constexpr const char* ANSI_BRIGHT_BLUE = "\x1b[94m";
inline constexpr const char* ANSI_BRIGHT_PURPLE = "\x1b[95m";
inline constexpr const char* ANSI_BRIGHT_CYAN = "\x1b[96m";
inline constexpr const char* ANSI_BRIGHT_WHITE = "\x1b[97m";

inline constexpr const char* ANSI_BG_BRIGHT_BLACK = "\x1b[100m";
inline constexpr const char* ANSI_BG_BRIGHT_RED = "\x1b[101m";
inline constexpr const char* ANSI_BG_BRIGHT_GREEN = "\x1b[102m";
inline constexpr const char* ANSI_BG_BRIGHT_YELLOW = "\x1b[103m";
inline constexpr const char* ANSI_BG_BRIGHT_BLUE = "\x1b[104m";
inline constexpr const char* ANSI_BG_BRIGHT_PURPLE = "\x1b[105m";
inline constexpr const char* ANSI_BG_BRIGHT_CYAN = "\x1b[106m";
inline constexpr const char* ANSI_BG_BRIGHT_WHITE = "\x1b[107m";

#else

    // Use as Normal name Const

inline constexpr const char* END = "\x1b[0m";
inline constexpr const char* OLD = "\x1b[1m";

inline constexpr const char* ITALIC = "\x1b[3m";
inline constexpr const char* UNDERLINED = "\x1b[4m";

inline constexpr const char* REVERSE_TEXT = "\x1b[7m";

inline constexpr const char* NOT_UNDERLINED = "\x1b[24m";

inline constexpr const char* POSITIVE_TEXT = "\x1b[27m";

inline constexpr const char* BLACK = "\x1b[30m";
inline constexpr const char* RED = "\x1b[31m";
inline constexpr const char* GREEN = "\x1b[32m";
inline constexpr const char* YELLOW = "\x1b[33m";
inline constexpr const char* BLUE = "\x1b[34m";
inline constexpr const char* PURPLE = "\x1b[35m";
inline constexpr const char* CYAN = "\x1b[36m";
inline constexpr const char* WHITE = "\x1b[37m";

inline constexpr const char* BG_BLACK = "\x1b[40m";
inline constexpr const char* BG_RED = "\x1b[41m";
inline constexpr const char* BG_GREEN = "\x1b[42m";
inline constexpr const char* BG_YELLOW = "\x1b[43m";
inline constexpr const char* BG_BLUE = "\x1b[44m";
inline constexpr const char* BG_PURPLE = "\x1b[45m";
inline constexpr const char* BG_CYAN = "\x1b[46m";
inline constexpr const char* BG_WHITE = "\x1b[47m";

inline constexpr const char* BRIGHT_BLACK = "\x1b[90m";
inline constexpr const char* BRIGHT_RED = "\x1b[91m";
inline constexpr const char* BRIGHT_GREEN = "\x1b[92m";
inline constexpr const char* BRIGHT_YELLOW = "\x1b[93m";
inline constexpr const char* BRIGHT_BLUE = "\x1b[94m";
inline constexpr const char* BRIGHT_PURPLE = "\x1b[95m";
inline constexpr const char* BRIGHT_CYAN = "\x1b[96m";
inline constexpr const char* BRIGHT_WHITE = "\x1b[97m";

inline constexpr const char* BG_BRIGHT_BLACK = "\x1b[100m";
inline constexpr const char* BG_BRIGHT_RED = "\x1b[101m";
inline constexpr const char* BG_BRIGHT_GREEN = "\x1b[102m";
inline constexpr const char* BG_BRIGHT_YELLOW = "\x1b[103m";
inline constexpr const char* BG_BRIGHT_BLUE = "\x1b[104m";
inline constexpr const char* BG_BRIGHT_PURPLE = "\x1b[105m";
inline constexpr const char* BG_BRIGHT_CYAN = "\x1b[106m";
inline constexpr const char* BG_BRIGHT_WHITE = "\x1b[107m";

#endif

#endif

#pragma endregion

#pragma region sorting

// bublsort algorithm, which is a simple sorting algorithm that
// repeatedly steps through the list, compares adjacent elements
// and swaps them if they are in the wrong order. The pass through
// the list is repeated until no swaps are needed, which means the
// list is sorted.

/*
// Example usage:
std::vector<int> values = { 5, 2, 8, 1, 3 };

bubblesort(values, [](int a, int b)
    {
        return a < b;
    });
*/
template <typename T, typename Compare>
inline void bubblesort(std::vector<T>& values, Compare comp)
{
    bool swapped;

    do
    {
        swapped = false;

        for (size_t i = 0; i + 1 < values.size(); ++i)
        {
            if (comp(values[i + 1], values[i]))
            {
                std::swap(values[i], values[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

#pragma endregion

#pragma region strings

// string_utils.hpp
// Header-only C++ Bibliothek mit String-Manipulationsfunktionen,
// wie man sie aus Python, JavaScript, Java etc. kennt.
//
// Einfach includieren:
//   #include "string_utils.hpp"
//   using namespace strutil;
//
// Alle Funktionen sind als `inline` markiert -> keine ODR-Probleme
// beim Einbinden in mehrere �bersetzungseinheiten.


namespace strutil {

    // ---------------------------------------------------------------------
    // Trimming / Whitespace  (Python: strip, lstrip, rstrip)
    // ---------------------------------------------------------------------

    inline std::string lstrip(const std::string& s) {
        size_t start = 0;
        while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
            ++start;
        return s.substr(start);
    }

    inline std::string rstrip(const std::string& s) {
        size_t end = s.size();
        while (end > 0 && std::isspace(static_cast<unsigned char>(s[end - 1])))
            --end;
        return s.substr(0, end);
    }

    inline std::string strip(const std::string& s) {
        return lstrip(rstrip(s));
    }

    // Variante mit eigenem Zeichensatz, der entfernt werden soll (wie Python's strip(chars))
    inline std::string strip(const std::string& s, const std::string& chars) {
        size_t start = s.find_first_not_of(chars);
        if (start == std::string::npos) return "";
        size_t end = s.find_last_not_of(chars);
        return s.substr(start, end - start + 1);
    }

    // ---------------------------------------------------------------------
    // Gro�-/Kleinschreibung (Python: upper, lower, title, capitalize, swapcase)
    // ---------------------------------------------------------------------

    inline std::string to_upper(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return std::toupper(c); });
        return s;
    }

    inline std::string to_lower(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return std::tolower(c); });
        return s;
    }

    inline std::string capitalize(std::string s) {
        if (!s.empty()) {
            s[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[0])));
            for (size_t i = 1; i < s.size(); ++i)
                s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
        }
        return s;
    }

    inline std::string title(const std::string& s) {
        std::string result = s;
        bool new_word = true;
        for (auto& c : result) {
            if (std::isalpha(static_cast<unsigned char>(c))) {
                c = new_word ? std::toupper(static_cast<unsigned char>(c))
                    : std::tolower(static_cast<unsigned char>(c));
                new_word = false;
            }
            else {
                new_word = true;
            }
        }
        return result;
    }

    inline std::string swapcase(std::string s) {
        for (auto& c : s) {
            if (std::isupper(static_cast<unsigned char>(c)))
                c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
            else if (std::islower(static_cast<unsigned char>(c)))
                c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        }
        return s;
    }

    // ---------------------------------------------------------------------
    // Pr�fen / Suchen (Python: startswith, endswith, contains/in, count, find)
    // ---------------------------------------------------------------------

    inline bool starts_with(const std::string& s, const std::string& prefix) {
        return s.size() >= prefix.size() &&
            s.compare(0, prefix.size(), prefix) == 0;
    }

    inline bool ends_with(const std::string& s, const std::string& suffix) {
        return s.size() >= suffix.size() &&
            s.compare(s.size() - suffix.size(), suffix.size(), suffix) == 0;
    }

    inline bool contains(const std::string& s, const std::string& needle) {
        return s.find(needle) != std::string::npos;
    }

    inline size_t count(const std::string& s, const std::string& sub) {
        if (sub.empty()) return 0;
        size_t cnt = 0, pos = 0;
        while ((pos = s.find(sub, pos)) != std::string::npos) {
            ++cnt;
            pos += sub.size();
        }
        return cnt;
    }

    // ---------------------------------------------------------------------
    // is*-Pr�fungen (Python: isdigit, isalpha, isalnum, isspace, isupper, islower)
    // ---------------------------------------------------------------------

    inline bool is_digit(const std::string& s) {
        if (s.empty()) return false;
        return std::all_of(s.begin(), s.end(),
            [](unsigned char c) { return std::isdigit(c); });
    }

    inline bool is_alpha(const std::string& s) {
        if (s.empty()) return false;
        return std::all_of(s.begin(), s.end(),
            [](unsigned char c) { return std::isalpha(c); });
    }

    inline bool is_alnum(const std::string& s) {
        if (s.empty()) return false;
        return std::all_of(s.begin(), s.end(),
            [](unsigned char c) { return std::isalnum(c); });
    }

    inline bool is_space(const std::string& s) {
        if (s.empty()) return false;
        return std::all_of(s.begin(), s.end(),
            [](unsigned char c) { return std::isspace(c); });
    }

    inline bool is_upper(const std::string& s) {
        bool has_alpha = false;
        for (unsigned char c : s) {
            if (std::isalpha(c)) {
                has_alpha = true;
                if (!std::isupper(c)) return false;
            }
        }
        return has_alpha;
    }

    inline bool is_lower(const std::string& s) {
        bool has_alpha = false;
        for (unsigned char c : s) {
            if (std::isalpha(c)) {
                has_alpha = true;
                if (!std::islower(c)) return false;
            }
        }
        return has_alpha;
    }

    // ---------------------------------------------------------------------
    // Split / Join (Python: split, rsplit, splitlines, join)
    // ---------------------------------------------------------------------

    // Split an jedem beliebigen Zeichen aus `delims` (Standard: Whitespace),
    // analog zu Python's str.split() ohne Argument (mehrfache Trenner werden zusammengefasst)
    inline std::vector<std::string> split(const std::string& s, const std::string& delims = " \t\n\r\f\v") {
        std::vector<std::string> tokens;
        size_t start = s.find_first_not_of(delims);
        while (start != std::string::npos) {
            size_t end = s.find_first_of(delims, start);
            tokens.push_back(s.substr(start, end - start));
            start = (end == std::string::npos) ? std::string::npos : s.find_first_not_of(delims, end);
        }
        return tokens;
    }

    // Split an einem festen String-Trenner (wie Python's str.split(sep))
    inline std::vector<std::string> split_by(const std::string& s, const std::string& sep) {
        if (sep.empty()) throw std::invalid_argument("split_by: separator darf nicht leer sein");
        std::vector<std::string> tokens;
        size_t start = 0, pos;
        while ((pos = s.find(sep, start)) != std::string::npos) {
            tokens.push_back(s.substr(start, pos - start));
            start = pos + sep.size();
        }
        tokens.push_back(s.substr(start));
        return tokens;
    }

    inline std::vector<std::string> splitlines(const std::string& s) {
        std::vector<std::string> lines;
        std::istringstream iss(s);
        std::string line;
        while (std::getline(iss, line)) {
            if (!line.empty() && line.back() == '\r') line.pop_back();
            lines.push_back(line);
        }
        return lines;
    }

    inline std::string join(const std::vector<std::string>& parts, const std::string& sep) {
        std::string result;
        for (size_t i = 0; i < parts.size(); ++i) {
            if (i) result += sep;
            result += parts[i];
        }
        return result;
    }

    // ---------------------------------------------------------------------
    // Ersetzen (Python: replace)
    // ---------------------------------------------------------------------

    inline std::string replace(const std::string& s, const std::string& from,
        const std::string& to, int max_count = -1) {
        if (from.empty()) return s;
        std::string result;
        size_t start = 0, pos;
        int replaced = 0;
        while ((pos = s.find(from, start)) != std::string::npos) {
            if (max_count >= 0 && replaced >= max_count) break;
            result.append(s, start, pos - start);
            result += to;
            start = pos + from.size();
            ++replaced;
        }
        result.append(s, start, std::string::npos);
        return result;
    }

    // ---------------------------------------------------------------------
    // Padding / Ausrichtung (Python: ljust, rjust, center, zfill)
    // ---------------------------------------------------------------------

    inline std::string ljust(const std::string& s, size_t width, char fill = ' ') {
        if (s.size() >= width) return s;
        return s + std::string(width - s.size(), fill);
    }

    inline std::string rjust(const std::string& s, size_t width, char fill = ' ') {
        if (s.size() >= width) return s;
        return std::string(width - s.size(), fill) + s;
    }

    inline std::string center(const std::string& s, size_t width, char fill = ' ') {
        if (s.size() >= width) return s;
        size_t total_pad = width - s.size();
        size_t left = total_pad / 2;
        size_t right = total_pad - left;
        return std::string(left, fill) + s + std::string(right, fill);
    }

    inline std::string zfill(const std::string& s, size_t width) {
        if (s.size() >= width) return s;
        bool has_sign = !s.empty() && (s[0] == '+' || s[0] == '-');
        std::string sign = has_sign ? std::string(1, s[0]) : "";
        std::string rest = has_sign ? s.substr(1) : s;
        size_t pad = width - s.size();
        return sign + std::string(pad, '0') + rest;
    }

    // ---------------------------------------------------------------------
    // Sonstiges (Python: str * n, reversed(str), removeprefix, removesuffix)
    // ---------------------------------------------------------------------

    inline std::string repeat(const std::string& s, size_t n) {
        std::string result;
        result.reserve(s.size() * n);
        for (size_t i = 0; i < n; ++i) result += s;
        return result;
    }

    inline std::string reverse(std::string s) {
        std::reverse(s.begin(), s.end());
        return s;
    }

    // Python 3.9+: removeprefix / removesuffix
    inline std::string remove_prefix(const std::string& s, const std::string& prefix) {
        return starts_with(s, prefix) ? s.substr(prefix.size()) : s;
    }

    inline std::string remove_suffix(const std::string& s, const std::string& suffix) {
        return ends_with(s, suffix) ? s.substr(0, s.size() - suffix.size()) : s;
    }

    // Wie Java/JS Array.prototype.slice bzw. Python's s[start:end]
    inline std::string slice(const std::string& s, int start, int end) {
        int len = static_cast<int>(s.size());
        if (start < 0) start += len;
        if (end < 0) end += len;
        start = std::max(0, std::min(start, static_cast<int>(len)));
        end = std::max(0, std::min(end, static_cast<int>(len)));
        if (start >= end) return "";
        return s.substr(start, end - start);
    }

} // namespace strutil

#pragma endregion

#pragma region Version

struct Version
{
    int major = 0;
    int minor = 0;
    int patch = 0;

    // to compare the versions
    auto operator<=>(const Version&) const = default;
};

inline Version parseVersion(const std::string& versionStr)
{
    Version version;
    std::stringstream ss(versionStr);
    std::string part;
    std::vector<int> numbers;

    while (std::getline(ss, part, '.'))
    {
        numbers.push_back(std::stoi(part));
    }

    if (numbers.size() != 3)
        throw std::invalid_argument("Invalid version format. Expected MAJOR.MINOR.PATCH");

    version.major = numbers[0];
    version.minor = numbers[1];
    version.patch = numbers[2];

    return version;
}

#pragma endregion

#pragma region Nana UI

// Enable with the Macros 
// #define SHADOWDARA_LIB_NANA_UI

#ifdef SHADOWDARA_LIB_NANA_UI

#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/slider.hpp>
#include <nana/gui/widgets/combox.hpp>
#include <nana/gui/widgets/checkbox.hpp>
#include <nana/gui/widgets/textbox.hpp>
#include <nana/gui/widgets/progress.hpp>
#include <nana/gui/widgets/panel.hpp>

namespace shadowdara::nana_ui {

    inline void create_nana_button(
        nana::button& button,
        const std::string& name,
        int desX,
        int desY,
        unsigned sizeX,
        unsigned sizeY)
    {
        button.caption(name);
        button.move({ desX, desY });
        button.size({ sizeX, sizeY });
    }

#define NANA_ON_CLICK(button, code) \
    (button).events().click([&]()  code );

// Easy Size, MOve
#define NANA_SIMO(object, movX, movY, sizeX, sizeY) \
    object.move( { movX, movY });                   \
    object.size({ sizeX, sizeY });;

} // shadowdara::nana_ui

#endif

#pragma endregion

#pragma region Process

#ifdef _WIN32
#define NOMINMAX
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#endif


inline int runProcess(
    const std::string& executable,
    const std::vector<std::string>& args)
{
#ifdef _WIN32

    // ------------------------------------------------------------
    // Windows - Unicode / UTF-16
    // ------------------------------------------------------------

    // UTF-8 -> UTF-16
    auto utf8ToWide = [](const std::string& str) -> std::wstring
        {
            if (str.empty())
                return {};

            int size = MultiByteToWideChar(
                CP_UTF8,
                0,
                str.data(),
                static_cast<int>(str.size()),
                nullptr,
                0
            );

            if (size <= 0)
                return {};

            std::wstring result(size, L'\0');

            MultiByteToWideChar(
                CP_UTF8,
                0,
                str.data(),
                static_cast<int>(str.size()),
                result.data(),
                size
            );

            return result;
        };

    std::wstring wideExecutable = utf8ToWide(executable);

    std::wstring commandLine = L"\"" + wideExecutable + L"\"";

    for (const auto& arg : args)
    {
        std::wstring wideArg = utf8ToWide(arg);

        commandLine += L" \"";

        // Minimal escaping für Windows command line arguments.
        for (wchar_t c : wideArg)
        {
            if (c == L'"')
                commandLine += L"\\\"";
            else
                commandLine += c;
        }

        commandLine += L"\"";
    }

    STARTUPINFOW startupInfo{};
    startupInfo.cb = sizeof(startupInfo);

    PROCESS_INFORMATION processInfo{};

    std::vector<wchar_t> commandLineBuffer(
        commandLine.begin(),
        commandLine.end()
    );

    commandLineBuffer.push_back(L'\0');

    BOOL success = CreateProcessW(
        nullptr,
        commandLineBuffer.data(),
        nullptr,
        nullptr,
        FALSE,
        0,
        nullptr,
        nullptr,
        &startupInfo,
        &processInfo
    );

    if (!success)
        return -1;

    WaitForSingleObject(
        processInfo.hProcess,
        INFINITE
    );

    DWORD exitCode = 0;

    GetExitCodeProcess(
        processInfo.hProcess,
        &exitCode
    );

    CloseHandle(processInfo.hThread);
    CloseHandle(processInfo.hProcess);

    return static_cast<int>(exitCode);

#else

    // ------------------------------------------------------------
    // Linux / macOS
    // ------------------------------------------------------------

    pid_t pid = fork();

    if (pid < 0)
        return -1;

    if (pid == 0)
    {
        std::vector<char*> argv;

        argv.push_back(
            const_cast<char*>(executable.c_str())
        );

        for (const auto& arg : args)
        {
            argv.push_back(
                const_cast<char*>(arg.c_str())
            );
        }

        argv.push_back(nullptr);

        execvp(
            executable.c_str(),
            argv.data()
        );

        _exit(127);
    }

    int status = 0;

    if (waitpid(pid, &status, 0) < 0)
        return -1;

    if (WIFEXITED(status))
        return WEXITSTATUS(status);

    if (WIFSIGNALED(status))
        return 128 + WTERMSIG(status);

    return -1;

#endif
}

// WIndows only function
void enable_utf8() {
#if _WIN32

    // that ansi codes work

    SetConsoleOutputCP(CP_UTF8);

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    DWORD mode = 0;
    if (GetConsoleMode(hOut, &mode))
    {
        SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }

#endif
}

// open a file
void openFile(const std::string& path)
{
#ifdef _WIN32

    ShellExecuteA(NULL, "open", path.c_str(), NULL, NULL, SW_SHOW);

#elif __APPLE__

    std::string command = "open \"" + path + "\"";
    system(command.c_str());

#elif __linux__

    std::string command = "xdg-open \"" + path + "\"";
    system(command.c_str());

#endif
}


std::string loadFile(const std::string& pfad)
{
    std::ifstream datei(pfad);

    if (!datei)
        return "";

    std::stringstream buffer;
    buffer << datei.rdbuf();

    return buffer.str();
}

#pragma endregion

#pragma region ArgParser

class ArgParser {
private:
    std::unordered_map<std::string, std::string> options;
    std::vector<std::string> args;

public:
    inline ArgParser(int argc, char* argv[])
    {
        for (int i = 1; i < argc; i++) {
            std::string arg = argv[i];

            // Option mit Wert: --name Bob
            if (arg.rfind("--", 0) == 0 || arg.rfind("-", 0) == 0) {
                if (i + 1 < argc && argv[i + 1][0] != '-') {
                    options[arg] = argv[++i];
                }
                else {
                    // Flag ohne Wert
                    options[arg] = "true";
                }
            }
            else {
                args.push_back(arg);
            }
        }
    }

    inline bool has(const std::string& option)
    {
        return options.find(option) != options.end();
    }

    inline std::string get(const std::string& option,
        const std::string& defaultValue = "")
    {
        if (has(option))
            return options[option];

        return defaultValue;
    }

    inline bool getBool(const std::string& option)
    {
        return get(option) == "true";
    }


    inline std::vector<std::string> positional()
    {
        return args;
    }
};

#pragma endregion

// END of shadowdaras LIB
