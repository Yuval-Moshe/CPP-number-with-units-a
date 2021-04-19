/**
 * Tests for number-with-units.
 *
 * AUTHOR: Yuval Moshe
 * 
 * Date: 2021-04
 */
#include <stdlib.h>
#include "doctest.h"
#include <iostream>
#include <fstream>
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;

TEST_CASE("Good Cases - Regular Operations")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    string g_arr[7] = {"km", "m", "kg", "ton", "hour", "min", "USD"};
    for (int i = 0; i < 7; i++)
    {
        try
        {
            NumberWithUnits good{20, g_arr[i]};
            throw invalid_argument("Reached Here, So Consturctor Didn't Throw Exception");
        }
        catch (invalid_argument e)
        {
            string s(e.what());
            CHECK_EQ(s, "Reached Here, So Consturctor Didn't Throw Exception");
        }
    }
}

TEST_CASE("Bad Cases - Wrong Creation Of Object")
{
    string w_arr[10] = {"KM", "kM", "Km", "", "yard", "centimeter", "TON", "toN", "usd", "hours"};
    for (int i = 0; i < 10; i++)
    {
        try
        {
            NumberWithUnits wrong{20, w_arr[i]};
            throw invalid_argument("Reached Here, So Consturctor Didn't Throw Exception");
        }
        catch (invalid_argument e)
        {
            string s(e.what());
            CHECK_EQ(s, "Invalid Unit");
        }
    }
}
TEST_CASE("Bad Cases - Oeprations Between Non Converting Units")
{
    string group_a[2] = {"km", "m"};
    string group_b[2] = {"kg", "ton"};
    string group_c[2] = {"hour", "min"};
    string group_d[2] = {"USD", "ILS"};
    string *groups[4] = {group_a, group_b, group_c, group_d};
    for (int i = 0; i < 20; i++)
    {
        int g1_i = rand() % 4;
        int g2_i = rand() % 4;
        while (g2_i == g1_i)
        {
            g2_i = rand() % 4;
        }
        int g1_a = rand() % 2;
        int g2_b = rand() % 2;
        NumberWithUnits a{20, groups[g1_i][g1_a]};
        NumberWithUnits b{20, groups[g2_i][g2_b]};
        CHECK_THROWS(a+b);
        CHECK_THROWS(a-b);
    }
}