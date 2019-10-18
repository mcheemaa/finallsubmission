#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"

/*More info on Catch
Git-Page: https://github.com/philsquared/Catch
*/

//What are we testing today?
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"


TEST_CASE("TESTING numberTheory Class")
{
 

  SECTION("GCD 1")
    {

      ReallyLongInt a(2);
      ReallyLongInt b(6);
      ReallyLongInt c;
      ReallyLongInt d;

      numberTheory fina;

      ReallyLongInt fin = fina.extendedEuclid(a,b,c,d);

      ReallyLongInt testi = a % b;
      
      REQUIRE(fin.toString() == "2");
      REQUIRE(c.toString() == "1");
      REQUIRE(d.toString() == "0"); 

      }

 SECTION("GCD 2")
    {

      ReallyLongInt a(10);
      ReallyLongInt b(4);
      ReallyLongInt c;
      ReallyLongInt d;

      numberTheory fina;

      ReallyLongInt fin = fina.extendedEuclid(a,b,c,d);

      ReallyLongInt testi = a % b;
      
      REQUIRE(fin.toString() == "2");
      REQUIRE(c.toString() == "1");
      REQUIRE(d.toString() == "-2"); 

    }

 
 SECTION("GCD 3")
    {

      ReallyLongInt a(550);
      ReallyLongInt b(45);
      ReallyLongInt c;
      ReallyLongInt d;

      numberTheory fina;

      ReallyLongInt fin = fina.extendedEuclid(a,b,c,d);

      ReallyLongInt testi = a % b;
      
      REQUIRE(fin.toString() == "5");
      REQUIRE(c.toString() == "-4");
      REQUIRE(d.toString() == "49"); 

    }


}
