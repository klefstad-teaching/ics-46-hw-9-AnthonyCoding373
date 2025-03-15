#include <gtest/gtest.h>

// #include "dijkstras.h"
#include "ladder.h"

// TEST(Ladder, get_edit_distance) {
//   string test1 = "test";
//   string test2 = "cat";
//   int edit_distance = get_edit_distance(test1, test2);
//   EXPECT_EQ(edit_distance, 3);
// }

// TEST(Ladder, get_edit_distance2) {
//   string test1 = "";
//   string test2 = "cat";
//   int edit_distance = get_edit_distance(test1, test2);
//   EXPECT_EQ(edit_distance, 3);
// }

// TEST(Ladder, get_edit_distance3) {
//   string test1 = "train";
//   string test2 = "same";
//   int edit_distance = get_edit_distance(test1, test2);
//   EXPECT_EQ(edit_distance, 4);
// }

// TEST(Ladder, edit_distance_within1) {
//   string test1 = "test";
//   string test2 = "cat";
//   EXPECT_TRUE(edit_distance_within(test1, test2, 4));
// }

// TEST(Ladder, edit_distance_within2) {
//   string test1 = "test";
//   string test2 = "cat";
//   EXPECT_FALSE(edit_distance_within(test1, test2, 2));
// }


// TEST(Ladder, is_adjacent) {
//   string test1 = "test";
//   string test2 = "cat";
//   EXPECT_FALSE(is_adjacent(test1, test2));
// }

// TEST(Ladder, is_adjacent1) {
//   string test1 = "ca";
//   string test2 = "cat";
//   EXPECT_TRUE(is_adjacent(test1, test2));
// }

TEST(Ladder, generate_word_ladder) {
  string test1 = "ca";
  string test2 = "cats";
  set<string> word_list = {"ca", "cats", "cat"};
  vector<string> result = generate_word_ladder(test1, test2, word_list);
  print_word_ladder(result);
}

TEST(Ladder, verify_word_ladder) {
  verify_word_ladder();
}