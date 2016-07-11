#ifndef SRC_PACKET_P_SECTOR_H_
#define SRC_PACKET_P_SECTOR_H_

#include "packet/p_base.h"

struct packet_sector : public PacketBase {
  explicit packet_sector(out_packet_t t) : PacketBase(t) {}
  packet_sector(out_packet_t t, uint8_t in_x, uint8_t in_y)
      : PacketBase(t), x(in_x), y(in_y) {}

  uint8_t x = 0;  // 3, int8, x-coordinate of the sector
  uint8_t y = 0;  // 4, int8, y-coordinate of the sector

  size_t get_size() const noexcept { return 5; }
};

struct packet_add_sector : public packet_sector {
  packet_add_sector() : packet_sector(packet_t_add_sector) {}
  packet_add_sector(uint8_t in_x, uint8_t in_y)
      : packet_sector(packet_t_add_sector, in_x, in_y) {}
};

struct packet_remove_sector : public packet_sector {
  packet_remove_sector() : packet_sector(packet_t_rem_sector) {}
  packet_remove_sector(uint8_t in_x, uint8_t in_y)
      : packet_sector(packet_t_rem_sector, in_x, in_y) {}
};

std::ostream& operator<<(std::ostream& out, const packet_sector& p);

#endif  // SRC_PACKET_P_SECTOR_H_
