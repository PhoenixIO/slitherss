#ifndef SRC_PACKET_P_FULLNESS_H_
#define SRC_PACKET_P_FULLNESS_H_

#include "game/snake.h"
#include "packet/p_base.h"

struct packet_fullness : public PacketBase {
  packet_fullness() : PacketBase(packet_t_set_fullness) {}
  packet_fullness(uint16_t in_snakeId, uint8_t in_f)
      : PacketBase(packet_t_set_fullness),
        snakeId(in_snakeId),
        fullness(in_f) {}
  explicit packet_fullness(const Snake* s)
      : PacketBase(packet_t_set_fullness),
        snakeId(s->id),
        fullness(static_cast<uint8_t>(s->fullness)) {}

  uint16_t snakeId = 0;  // 3-4, int16, Snake id
  uint8_t fullness = 0;  // 5-7, int24, value / 16777215 -> fam

  size_t get_size() const noexcept { return 8; }
};

std::ostream& operator<<(std::ostream& out, const packet_fullness& p);

#endif  // SRC_PACKET_P_FULLNESS_H_
