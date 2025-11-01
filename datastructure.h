#include <stdint.h>

// Common message header
typedef struct {
    uint8_t msg_type;     // 1=discover, 2=resp, 3=connect, 4=handshake, 5=data, 6=disconnect
    uint8_t source_id;    // ID of robot or station
    uint8_t dest_id;      // Target ID
    uint8_t seq;          // Sequence number
} MessageHeader;

// Handshake message (100 bytes payload)
typedef struct {
    MessageHeader header;
    uint8_t payload[100];
} HandshakeMessage;

// Real-time message (50 bytes payload)
typedef struct {
    MessageHeader header;
    uint8_t payload[50];
} RealtimeMessage;

// Discover message (10 bytes payload example)
typedef struct {
    MessageHeader header;
    uint8_t payload[10];
} DiscoverMessage;
