#include "priority_queue.hpp"
#include "vector.hpp"
#include <gtest/gtest.h>

TEST(StructuteTest, PriorityQueuePushTest)
{
  std::vector<int> empty;
  study::priority_queue cont(empty);
  cont.push(1);
  EXPECT_EQ(1, 1);
}

TEST(StructuteTest, PriorityQueuePopTest)
{
  std::vector<int> empty;
  study::priority_queue cont(empty);
  cont.push(1);
  cont.pop();
  EXPECT_EQ(1, 1);
}

TEST(StructuteTest, PriorityQueuePeakTest)
{
  std::vector<int> empty;
  study::priority_queue cont(empty);
  cont.push(1);
  EXPECT_EQ(cont.top(), 1);
}

TEST(StructuteTest, VectorPushBackTest)
{
  study::vector<int> v;
  v.push_back(1);
  EXPECT_EQ(1, 1);
}

struct Car {
  Car(int speed, int mass, int color)
  : speed_(speed),
    mass_(mass),
    color_(color)
  { }

public:
  int speed_;
  int mass_;
  int color_;
};


TEST(StructuteTest, VectorEmplaceBackTest)
{
  study::vector<Car> v;
  int first_car_mass = 1000;
  int second_car_mass = 2000;
  v.emplace_back(90, first_car_mass, 1);
  v.emplace_back(180, second_car_mass, 2);
  EXPECT_EQ(v[0].mass_, 1000);
  EXPECT_EQ(v[1].mass_, 2000);
}

TEST(StructuteTest, VectorBackTest)
{
  study::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
}

TEST(StructuteTest, VectorClearBackTest)
{
  study::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}