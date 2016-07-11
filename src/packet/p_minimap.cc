#include "packet/p_minimap.h"

std::ostream& operator<<(std::ostream& out, const packet_minimap& p) {
  out << static_cast<PacketBase>(p);
  for (const uint8_t v : p.data) {
    out.put(v);
  }
  return out;
}
