#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Caesar Cipher Sentences That Should Solve Correctly")
{
    CHECK(solve("Z'd r Evn Pfib Xzrekj reu Prebvvj wre!") == "I'm a New York Giants and Yankees fan!");
    CHECK(solve("U pa zaf nqxuqhq uz mefdaxask mzp pa zaf wzai yk Lapumo eusz.") == "I do not believe in astrology and do not know my Zodiac sign.");
    CHECK(solve("Frpsxwhuv dqg wulqnhwv dqg zroyhv") == "Computers and trinkets and wolves");
    CHECK(solve("shqdui qhu dysu!") == "cranes are nice!");
}

TEST_CASE("Caesar Cipher Sentences That Should Not Solve Correctly")
{
    CHECK(solve("mxqj yi q wofio?") != "what is a gypsy?");
    CHECK(solve("uyraf msr ufmq rfyr") != "watch out whos that");
    CHECK(solve("ywtumd") != "trophy");
}