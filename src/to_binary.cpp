#include "saber.hpp"

namespace Saber {

Endian get_loca_endian() {
    uint16_t x = 0x0001;
    return *((uint8_t *)&x) ? Endian::little : Endian::big;
}

void decompose_byte(uint8_t byte, std::ostream &out) {
    for (size_t i = bits_in_byte; i > 0; i--) {
        out << ((byte >> (i - 1)) & 1);
    }
}

int swap_endian(int value) {
    int result = 0;
    size_t bytes_number = sizeof(value);
    for (size_t i = 1; i < bytes_number; i++) {
        result = result | (value & 0xff);
        value = value >> bits_in_byte;
        result = result << bits_in_byte;
    }
    return result;
}

void to_binary(int value, Endian endian, std::ostream &out) {
    size_t bytes_number = sizeof(value);
    bool negative = value < 0;
    if (negative) {
        value *= -1;
    }
    size_t significant_byte_index =
        endian == Endian::big ? 0 : bytes_number - 1;

    if (get_loca_endian() != endian) {
        value = swap_endian(value);
    }

    for (size_t i = 0; i < bytes_number; i++) {
        size_t shift = i * bits_in_byte;
        uint8_t byte = (value >> shift) & 0xff;

        if (negative && i == significant_byte_index) {
            byte |= 0x80;
        }

        decompose_byte(byte, out);
    }
}

} // namespace Saber