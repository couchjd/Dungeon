#include "BinaryPacket.h"

inline BinaryPacket::BinaryPacket(char const* const data, u_long size) {
	m_Data = new(char[size + sizeof(u_long)]);
}

inline BinaryPacket::BinaryPacket(u_long size) {
}

inline void BinaryPacket::MemCpy(char const * const data, size_t size, int destOffset) {
}
