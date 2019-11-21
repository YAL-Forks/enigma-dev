#include "TestHarness.hpp"

#include <gtest/gtest.h>

TEST(Game, window_test) {
  if (!TestHarness::windowing_supported()) return;
  TestConfig tc;
  tc.extensions = "Paths,GTest";
  auto test_harness = LAUNCH_HARNESS_FOR_SOG(tc);
  if (!test_harness) FAIL() << "Game could not be run.";

  test_harness->wait();  // Let the game run for a moment.
  // TODO: better tests than "game stays alive for a brief window of time"
  ASSERT_TRUE(test_harness->game_is_running())
      << "Game stopped running unexpectedly";

  // Close the window and verify that the game ends normally.
  test_harness->close_window();
  bool game_running = test_harness->game_is_running();
  for (int i = 0; game_running && i < 10; ++i) {
    test_harness->wait();
    game_running = test_harness->game_is_running();
  }
  ASSERT_FALSE(game_running) << "Game did not exit after window was closed!";
  EXPECT_EQ(test_harness->get_return(), 0) << "Game returned non-zero exit code!";
}
