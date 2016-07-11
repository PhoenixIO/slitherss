#include "packet/p_remove_part.h"

std::ostream& operator<<(std::ostream& out, const packet_remove_part& p) {
  out << static_cast<PacketBase>(p);
  out << write_uint16(p.snakeId);
  if (p.fullness > 0) {
    out << write_fp24(p.fullness / 100.0f);
  }
  return out;
}
