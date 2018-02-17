#define BOOST_TEST_MODULE bulk_test

#include <boost/test/unit_test.hpp>
#include "commands_storage.h"
#include "commands_storage.cpp"
#include "solvers.h"
#include "solvers.cpp"
#include "solver.h"
#include "solver.cpp"

//#include "version.h"

BOOST_AUTO_TEST_CASE(version_test)
{
//    BOOST_CHECK( version() > 0 );
}

BOOST_AUTO_TEST_SUITE(Test_CommandStorage)

BOOST_AUTO_TEST_CASE(test_commandsSize)
{
    CommandsStorage cmdStorage(4);
    cmdStorage.addString("cmd1");
    cmdStorage.addString("cmd2");
    cmdStorage.addString("cmd3");
    BOOST_CHECK(cmdStorage.commandsSize() == 3);

    cmdStorage.addString("cmd4");

    BOOST_CHECK(cmdStorage.commandsSize() == 0);
}

BOOST_AUTO_TEST_CASE(test_bracketSize)
{
    CommandsStorage cmdStorage(4);
    cmdStorage.addString("cmd1");
    cmdStorage.addString("{");
    BOOST_CHECK(cmdStorage.bracketSize() == 1);
    BOOST_CHECK(cmdStorage.commandsSize() == 0);
    cmdStorage.addString("cmd3");
    cmdStorage.addString("}");
    BOOST_CHECK(cmdStorage.bracketSize() == 0);
    BOOST_CHECK(cmdStorage.commandsSize() == 0);

    cmdStorage.addString("}");
    BOOST_CHECK(cmdStorage.bracketSize() == 0);
    BOOST_CHECK(cmdStorage.commandsSize() == 0);

    cmdStorage.addString("{");
    cmdStorage.addString("cmd1");
    cmdStorage.addString("cmd2");
    BOOST_CHECK(cmdStorage.bracketSize() == 1);
    BOOST_CHECK(cmdStorage.commandsSize() == 2);
    cmdStorage.addString("{");
    BOOST_CHECK(cmdStorage.bracketSize() == 2);
    BOOST_CHECK(cmdStorage.commandsSize() == 2);
    cmdStorage.addString("cmd3");
    BOOST_CHECK(cmdStorage.bracketSize() == 2);
    BOOST_CHECK(cmdStorage.commandsSize() == 3);
    cmdStorage.addString("}");
    BOOST_CHECK(cmdStorage.bracketSize() == 1);
    BOOST_CHECK(cmdStorage.commandsSize() == 3);
    cmdStorage.addString("cmd4");
    cmdStorage.addString("cmd5");
    BOOST_CHECK(cmdStorage.bracketSize() == 1);
    BOOST_CHECK(cmdStorage.commandsSize() == 5);
    cmdStorage.addString("}");
    BOOST_CHECK(cmdStorage.bracketSize() == 0);
    BOOST_CHECK(cmdStorage.commandsSize() == 0);
}

BOOST_AUTO_TEST_SUITE_END()
