#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "Ws2_32.lib")
#include <winsock2.h>

typedef unsigned long u_long;

#define SAFE_DELETE(p) { if (p) {delete(p); (p)=nullptr; }}

class BinaryPacket {


protected:
	char* m_Data;

public:
	inline BinaryPacket(char const* const data, u_long size);
	inline BinaryPacket(u_long size);

	virtual ~BinaryPacket() { SAFE_DELETE(m_Data); }
	virtual char const* const VGetData() const { return m_Data; }
	virtual u_long VGetSize() const { return ntohl(*(u_long*)m_Data); }
	inline void MemCpy(char const* const data, size_t size, int destOffset);
};

