#pragma once

#include <iostream>
#include <stdint.h>

namespace Saber {

const uint8_t bits_in_byte = 8;

enum class Endian { big, little };

void to_binary(int value, Endian endian, std::ostream &out);

} // namespace Saber