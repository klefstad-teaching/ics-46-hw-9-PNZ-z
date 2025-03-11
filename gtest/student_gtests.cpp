#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(Replace, Me) {
  EXPECT_TRUE(true);
}


TEST(Ladder, IsAdj){
  string word1 = "hello";
  string word2 = "hell";
  EXPECT_TRUE(is_adjacent(word1, word2));
  EXPECT_TRUE(is_adjacent(word2, word1));
  string word3 = "Hello";
  EXPECT_TRUE(is_adjacent(word1, word3));
  EXPECT_TRUE(is_adjacent(word3, word1));
  string word4 = "hall";
  EXPECT_TRUE(is_adjacent(word2, word4));
  EXPECT_TRUE(is_adjacent(word4, word2));
  EXPECT_FALSE(is_adjacent(word4, word1));
  string wordfalse = "abshdhakljsd";
  EXPECT_FALSE(is_adjacent(word1, wordfalse));
}