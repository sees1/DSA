#include "data_struct/priority_queue/priority_queue.hpp"
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