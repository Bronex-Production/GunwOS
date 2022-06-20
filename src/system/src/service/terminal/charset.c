//
//  charset.c
//  GunwOS
//
//  Created by Artur Danielewski on 13.03.2020.
//

#include "charset.h"

const struct k_chs_mapping k_chs_default[CHARSET_CODES_MAX] = {
    /* CODE     CHARACTER */
    /* 0   */ { 0 },
    /* 1   */ { '1' },
    /* 2   */ { '2' },
    /* 3   */ { '3' },
    /* 4   */ { '4' },
    /* 5   */ { '5' },
    /* 6   */ { '6' },
    /* 7   */ { '7' },
    /* 8   */ { '8' },
    /* 9   */ { '9' },
    /* 10  */ { '0' },
    /* 11  */ { '-' },
    /* 12  */ { '=' },
    /* 13  */ { '\b' },
    /* 14  */ { '\t' },
    /* 15  */ { 'q' },
    /* 16  */ { 'w' },
    /* 17  */ { 'e' },
    /* 18  */ { 'r' },
    /* 19  */ { 't' },
    /* 20  */ { 'y' },
    /* 21  */ { 'u' },
    /* 22  */ { 'i' },
    /* 23  */ { 'o' },
    /* 24  */ { 'p' },
    /* 25  */ { '[' },
    /* 26  */ { ']' },
    /* 27  */ { '\n' },
    /* 28  */ { 'a' },
    /* 29  */ { 's' },
    /* 30  */ { 'd' },
    /* 31  */ { 'f' },
    /* 32  */ { 'g' },
    /* 33  */ { 'h' },
    /* 34  */ { 'j' },
    /* 35  */ { 'k' },
    /* 36  */ { 'l' },
    /* 37  */ { ';' },
    /* 38  */ { '\'' },
    /* 39  */ { '`' },
    /* 40  */ { '\\' },
    /* 41  */ { 'z' },
    /* 42  */ { 'x' },
    /* 43  */ { 'c' },
    /* 44  */ { 'v' },
    /* 45  */ { 'b' },
    /* 46  */ { 'n' },
    /* 47  */ { 'm' },
    /* 48  */ { ',' },
    /* 49  */ { '.' },
    /* 50  */ { '/' },
    /* 51  */ { ' ' },
    /* 52  */ { '!' },
    /* 53  */ { '@' },
    /* 54  */ { '#' },
    /* 55  */ { '$' },
    /* 56  */ { '%' },
    /* 57  */ { '^' },
    /* 58  */ { '&' },
    /* 59  */ { '*' },
    /* 60  */ { '(' },
    /* 61  */ { ')' },
    /* 62  */ { '_' },
    /* 63  */ { '+' },
    /* 64  */ { 'Q' },
    /* 65  */ { 'W' },
    /* 66  */ { 'E' },
    /* 67  */ { 'R' },
    /* 68  */ { 'T' },
    /* 69  */ { 'Y' },
    /* 70  */ { 'U' },
    /* 71  */ { 'I' },
    /* 72  */ { 'O' },
    /* 73  */ { 'P' },
    /* 74  */ { '{' },
    /* 75  */ { '}' },
    /* 76  */ { 'A' },
    /* 77  */ { 'S' },
    /* 78  */ { 'D' },
    /* 79  */ { 'F' },
    /* 80  */ { 'G' },
    /* 81  */ { 'H' },
    /* 82  */ { 'J' },
    /* 83  */ { 'K' },
    /* 84  */ { 'L' },
    /* 85  */ { ':' },
    /* 86  */ { '"' },
    /* 87  */ { '~' },
    /* 88  */ { '|' },
    /* 89  */ { 'Z' },
    /* 90  */ { 'X' },
    /* 91  */ { 'C' },
    /* 92  */ { 'V' },
    /* 93  */ { 'B' },
    /* 94  */ { 'N' },
    /* 95  */ { 'M' },
    /* 96  */ { '<' },
    /* 97  */ { '>' },
    /* 98  */ { '?' }
};

uint_8 k_chs_defines(const struct k_chs_mapping *map, const uint_8 c) {
    return map[c].character;
}
