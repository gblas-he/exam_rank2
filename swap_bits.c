
#include <unistd.h>

// Intercambia los 4 bits altos y los 4 bits bajos de un byte (nibble swapping).
unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
