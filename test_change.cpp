#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>

#include "change.h"

using ::testing::ElementsAre;

TEST(Change, Calculate)
{
    auto changer = ChangeItForMe();

    EXPECT_THAT(changer.calculate(100), ElementsAre(0, 0, 0, 0, 1));
    EXPECT_THAT(changer.calculate(25), ElementsAre(0, 0, 0, 1, 0));
    EXPECT_THAT(changer.calculate(10), ElementsAre(0, 0, 1, 0, 0));
    EXPECT_THAT(changer.calculate(5), ElementsAre(0, 1, 0, 0, 0));
    EXPECT_THAT(changer.calculate(1), ElementsAre(1, 0, 0, 0, 0));

    EXPECT_THAT(changer.calculate(141), ElementsAre(1, 1, 1, 1, 1));
    EXPECT_THAT(changer.calculate(99), ElementsAre(4, 0, 2, 3, 0));
    EXPECT_THAT(changer.calculate(207), ElementsAre(2, 1, 0, 0, 2));
}

TEST(Change, Transact)
{
    auto changer = ChangeItForMe();

    EXPECT_THAT(changer.transact(20, 100), ElementsAre(0, 1, 0, 3, 0));
    EXPECT_THAT(changer.transact(56, 100), ElementsAre(4, 1, 1, 1, 0));
}
