#include "packet/p_highscore.h"

std::ostream& operator<<(std::ostream& out, const packet_highscore& p) {
  out << static_cast<PacketBase>(p);
  out << write_uint24(p.winner->parts.size());
  out << write_fp24(p.winner->fullness / 100.f);
  out << write_string(p.winner->name);
  // no len for message here
  for (const char c : p.message) {
    out.put(c);
  }
  return out;
}
