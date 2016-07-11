#ifndef SRC_PACKET_P_FOOD_H_
#define SRC_PACKET_P_FOOD_H_

#include <vector>

#include "game/food.h"
#include "packet/p_base.h"

// Sent when food that existed before enters range.
// The food id is calculated with (y * GameRadius * 3) + x
struct packet_set_food : public PacketBase {
  explicit packet_set_food(const std::vector<Food>* ptr)
      : PacketBase(packet_t_set_food), food_ptr(ptr) {}

  /**
   * 3    int8    Color?
   * 4-5  int16   Food X
   * 6-7  int16   Food Y
   * 8    int8    value / 5 -> Size
   */
  const std::vector<Food>* food_ptr;

  size_t get_size() const noexcept { return 3 + food_ptr->size() * 6; }
};

// Sent when food is created while in range (because of turbo or the death of a
// snake).
// The Food id is calculated with (y * GameRadius * 3) + x
struct packet_spawn_food : public PacketBase {
  packet_spawn_food() : PacketBase(packet_t_spawn_food) {}
  explicit packet_spawn_food(Food f)
      : PacketBase(packet_t_spawn_food), m_food(f) {}

  /**
   * 3    int8    Color?
   * 4-5  int16    Food X
   * 6-7  int16    Food Y
   * 8    int8    value / 5 -> Size
   */
  Food m_food;

  size_t get_size() const noexcept { return 3 + 6; }
};

// Sent when natural food spawns while in range.
// The food id is calculated with (y * GameRadius * 3) + x
struct packet_add_food : public PacketBase {
  packet_add_food() : PacketBase(packet_t_add_food) {}
  explicit packet_add_food(Food f)
      : PacketBase(packet_t_add_food), m_food(f) {}

  /**
   * 3    int8    Color?
   * 4-5  int16   Food X
   * 6-7  int16   Food Y
   * 8    int8    value / 5 -> Size
   */
  Food m_food;

  size_t get_size() const noexcept { return 3 + 6; }
};

struct packet_eat_food : public PacketBase {
  packet_eat_food() : PacketBase(packet_t_eat_food) {}
  packet_eat_food(uint16_t id, Food f)
      : PacketBase(packet_t_eat_food), m_food(f), snakeId(id) {}

  /**
   * 3-4    int16    Food X
   * 5-6    int16    Food Y
   */
  Food m_food;

  // 7-8    int16    Eater snake id
  uint16_t snakeId = 0;

  size_t get_size() const noexcept { return 3 + 6; }
};

std::ostream& operator<<(std::ostream& out, const packet_set_food& p);
std::ostream& operator<<(std::ostream& out, const packet_spawn_food& p);
std::ostream& operator<<(std::ostream& out, const packet_add_food& p);
std::ostream& operator<<(std::ostream& out, const packet_eat_food& p);

#endif  // SRC_PACKET_P_FOOD_H_
