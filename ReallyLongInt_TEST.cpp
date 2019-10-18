
/*****************
 **WHEN 32 SIZE THERE ARE EXTRA 0S WHAT TO DO
ALSO BINARY TO DECIMAL THING DOEST WORK ***/


#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"

/*More info on Catch
Git-Page: https://github.com/philsquared/Catch
*/

//What are we testing today?
#include "ReallyLongInt.hpp"


TEST_CASE("TESTING ReallyLongInt Class")
{
  ReallyLongInt *test_ReallyLongInt;
  ReallyLongInt *test_ReallyLongInttwo;

  SECTION("Testing Sub Case 3")
    {

      ReallyLongInt test1(19925626416902200);
      ReallyLongInt test2(75);

      ReallyLongInt fin = test1.add(test2);

      REQUIRE(fin.toString() == "19925626416902272"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

  SECTION("Testing Div 2")
    {

      ReallyLongInt test1(10);
      ReallyLongInt test2(4);
      ReallyLongInt quot;
      ReallyLongInt rem;
      
 

      test1.div(test2,quot,rem);

      ReallyLongInt re = 125 % 3;
      ReallyLongInt qu = 125 / 3;

      REQUIRE(qu.toString() == "41"); // THIS IS WRONG
      REQUIRE(re.toString() == "2"); 
      REQUIRE(rem.toString() == "2"); // THIS IS WRONG
      REQUIRE(quot.toString() == "2"); 
      
      //REQUIRE(quot.toStringBinary() == "1111");
      
    }

  SECTION("Default Constructor")
    {

      test_ReallyLongInt = new ReallyLongInt();
      

      REQUIRE(test_ReallyLongInt->toString() == "0");
      REQUIRE(test_ReallyLongInt->toStringBinary() == "0");
      
      delete  test_ReallyLongInt;
      }

  SECTION("Constructor String")
    {
      test_ReallyLongInt = new ReallyLongInt("1234");

      REQUIRE(test_ReallyLongInt->toString() == "1234");
      REQUIRE(test_ReallyLongInt->toStringBinary() == "10011010010");
      


      delete  test_ReallyLongInt;


      }
  
  SECTION("Constructor Number Long")
    {
      test_ReallyLongInt = new ReallyLongInt(1234);
      
      REQUIRE(test_ReallyLongInt->toString() == "1234"); // THIS IS WRONG
      REQUIRE(test_ReallyLongInt->toStringBinary() == "10011010010");
      


      delete  test_ReallyLongInt;

      
    }

  

  SECTION("Constructor Number Long Megative")
    {
      test_ReallyLongInt = new ReallyLongInt(-10);
      
      REQUIRE(test_ReallyLongInt->toString() == "-10"); // THIS IS WRONG
      //REQUIRE(test_ReallyLongInt->toStringBinary() == "10011010010");
      
      
      
      delete  test_ReallyLongInt;

      
    }

  SECTION("Testing absAdd")
    {

      ReallyLongInt test1(10);
      ReallyLongInt test2(5);

      ReallyLongInt fin = test1.absAdd(test2);

      REQUIRE(fin.toString() == "15"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "10100");
    
      
    }

  SECTION("Constructor Other Checkinh")
    {

      test_ReallyLongInt = new ReallyLongInt(1234);
      ReallyLongInt test_ReallyLongInt2 (*test_ReallyLongInt);
      
      REQUIRE(test_ReallyLongInt->toString() == "1234"); // THIS IS WRONG
      REQUIRE(test_ReallyLongInt->toStringBinary() == "10011010010");
      
      delete  test_ReallyLongInt;

      
      }

   SECTION("Testing Equalsss !!!!!!!!!!!!!!!")
    {

      test_ReallyLongInt = new ReallyLongInt(1234567);
      
      REQUIRE(test_ReallyLongInt->equal(1234567) == true); // THIS IS WRONG
      //REQUIRE(test_ReallyLongInt->toStringBinary() == "10011010010");
      
      delete  test_ReallyLongInt;

      
    }


  SECTION("Testing Greaterrrrrrr !!!!!!!!!!!!!!!")
    {

      

      test_ReallyLongInt = new ReallyLongInt("1234567");

      //REQUIRE(test_ReallyLongInt->absGreater(12345) == false);

      CAPTURE(test_ReallyLongInt->toStringBinary() );
      
      REQUIRE(test_ReallyLongInt->greater(1234) == true); // THIS IS WRONG
      REQUIRE(test_ReallyLongInt->greater(12345678) == false); // THIS IS WRONG
      REQUIRE(test_ReallyLongInt->greater(123) == true); // THIS IS WRONG
      REQUIRE(test_ReallyLongInt->greater(-123) == true); // THIS IS WRONG
      
      
      //REQUIRE(test_ReallyLongInt->toStringBinary() == "0000010011010010");
      

      delete  test_ReallyLongInt;

      
      }

  SECTION ("Testing absGreater")
    {
      ReallyLongInt test1(5);
      ReallyLongInt test2(3);

      REQUIRE(test1.absGreater(test2) == true); // THIS IS WRONG

    }

  SECTION("Testing absAdd")
    {

      ReallyLongInt test1(10);
      ReallyLongInt test2(10);

      ReallyLongInt fin = test1.absAdd(test2);

      REQUIRE(fin.toString() == "20"); // THIS IS WRONG
      REQUIRE(fin.toStringBinary() == "10100");
    
      
    }

  SECTION("Testing Add")
    {

      ReallyLongInt test1(10);
      ReallyLongInt test2(10);

      ReallyLongInt fin = test1.add(test2);

      REQUIRE(fin.toString() == "20"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }
  SECTION("Testing Add Case 2")
    {

      ReallyLongInt test1(10);
      ReallyLongInt test2(5);

      
      //cout << "Test 2"  << test2.toString() <<endl;
	  
      ReallyLongInt fin = test1.add(test2);

      REQUIRE(fin.toString() == "15"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
      }
  SECTION("Testing Add Case 3")
    {

      ReallyLongInt test1(10);
      ReallyLongInt test2(5);

      ReallyLongInt fin = test1.add(test2);

      REQUIRE(fin.toString() == "15"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

  

  
   SECTION("Testing Add Case 4")
    {

      ReallyLongInt test1(10);
      ReallyLongInt test2(10);

      ReallyLongInt fin = test1.add(test2);

      REQUIRE(fin.toString() == "20"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }
   SECTION("Testing Add Case 5")
    {

      ReallyLongInt test1(5);
      ReallyLongInt test2(10);

      ReallyLongInt fin = test1.add(test2);

      REQUIRE(fin.toString() == "15"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
      }
  

  SECTION("Testing absSub")
    {

      ReallyLongInt test1(0);
      ReallyLongInt test2(1);

      ReallyLongInt fin = test1.sub(test2);

      REQUIRE(fin.toString() == "1"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "00110");

    }

   SECTION("Testing Sub Case 1")
    {

      ReallyLongInt test1(100);
      ReallyLongInt test2(20);

      ReallyLongInt fin = test1.sub(test2);

      REQUIRE(fin.toString() == "80"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

   SECTION("Testing Sub Case 2")
    {

      ReallyLongInt test1(20);
      ReallyLongInt test2(100);

      ReallyLongInt fin = test1.sub(test2);

      REQUIRE(fin.toString() == "-80"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

   SECTION("Testing Sub Case 3")
    {

      ReallyLongInt test1(5);
      ReallyLongInt test2(3);

      ReallyLongInt fin = test1.sub(test2);

      REQUIRE(fin.toString() == "2"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }
   SECTION("Testing Sub Case 4")
    {

      ReallyLongInt test1(-100);
      ReallyLongInt test2(20);

      ReallyLongInt fin = test1.sub(test2);

      REQUIRE(fin.toString() == "-120"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

     SECTION("Testing Sub Case 5")
    {

      ReallyLongInt test1(20);
      ReallyLongInt test2(-100);

      ReallyLongInt fin = test1.sub(test2);

      REQUIRE(fin.toString() == "120"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

     SECTION("Testing Sub Case 6")
    {

      ReallyLongInt test1(100);
      ReallyLongInt test2(-20);

      ReallyLongInt fin = test1.sub(test2);

      REQUIRE(fin.toString() == "120"); // THIS IS WRONG
      REQUIRE(fin.toStringBinary() == "1111000");
      
    }

     
     SECTION("Testing Sub Case 7")
    {

      ReallyLongInt test1(-20);
      ReallyLongInt test2(100);

      ReallyLongInt fin = test1.sub(test2);

      REQUIRE(fin.toString() == "-120"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

      SECTION("Testing Sub Case 8")
    {

      ReallyLongInt test1(-20);
      ReallyLongInt test2(-100);

      ReallyLongInt fin = test1.sub(test2);

      REQUIRE(fin.toString() == "80"); // THIS IS WRONG
      REQUIRE(fin.toStringBinary() == "1010000");
      
      }

      SECTION("Testing Sub Case 9")
    {

      ReallyLongInt test1(-100);
      ReallyLongInt test2(-20);

      ReallyLongInt fin = test1.sub(test2);

      REQUIRE(fin.toString() == "-80"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }


      SECTION("Testing Sub Case 4")
    {

      ReallyLongInt test1(-10);
      ReallyLongInt test2(-10);

      ReallyLongInt fin = test1.sub(test2);

      REQUIRE(fin.toString() == "-20"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

    SECTION("Testing Flip Sign")
    {

      ReallyLongInt test1(10);
      ReallyLongInt test2(10);

      test1.flipSign();

      //REQUIRE(test1.toString() == "20"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

   SECTION("Testing absMult")
    {

      ReallyLongInt test1(2);
      ReallyLongInt test2(100);

      ReallyLongInt fin = test1.absMult(test2);

      REQUIRE(fin.toString() == "200"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

   SECTION("Testing absMult One")
    {

      ReallyLongInt test1(7);
      ReallyLongInt test2(3);

      ReallyLongInt fin = test1.absMult(test2);

      REQUIRE(fin.toString() == "21"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

    SECTION("Testing absMult Two")
    {

      ReallyLongInt test1(100);
      ReallyLongInt test2(2);

      ReallyLongInt fin = test1.absMult(test2);

      REQUIRE(fin.toString() == "200"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

    SECTION("Testing Mult 1")
    {

      ReallyLongInt test1(50);
      ReallyLongInt test2(50);

      ReallyLongInt fin = test1.mult(test2);

      REQUIRE(fin.toString() == "2500"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

    SECTION("Testing Mult 2")
    {

      ReallyLongInt test1(50);
      ReallyLongInt test2(50);

      ReallyLongInt fin = test1.mult(test2);

      REQUIRE(fin.toString() == "2500"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

    SECTION("Testing Mult 3")
    {

      ReallyLongInt test1(50);
      ReallyLongInt test2(50);

      ReallyLongInt fin = test1.mult(test2);

      REQUIRE(fin.toString() == "2500"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

     SECTION("Testing Mult 4")
    {

      ReallyLongInt test1(50);
      ReallyLongInt test2(-50);

      ReallyLongInt fin = test1.mult(test2);

      REQUIRE(fin.toString() == "-2500"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

     SECTION("Testing Swap")
    {

      ReallyLongInt test1(50);
      ReallyLongInt test2(100);

      test1 = test2;

      REQUIRE(test1.toString() == "100"); // THIS IS WRONG
      //REQUIRE(fin.toStringBinary() == "100001001001111001");
      
    }

     SECTION("Testing absDiv")
    {

      ReallyLongInt test1(-125);
      ReallyLongInt test2(3);
      ReallyLongInt quot;
      ReallyLongInt rem;
      
 

      test1.div(test2,quot,rem);

      ReallyLongInt re = -125 % 3;
      ReallyLongInt qu = -125 / 3;

      REQUIRE(qu.toString() == "-41"); // THIS IS WRONG
      REQUIRE(re.toString() == "-2"); 
      REQUIRE(rem.toString() == "-2"); // THIS IS WRONG
      REQUIRE(quot.toString() == "-41"); 
      
      }

         SECTION("Testing Div 1")
    {

      ReallyLongInt test1(20);
      ReallyLongInt test2(5);
      ReallyLongInt quot;
      ReallyLongInt rem;
      

      

      test1.div(test2,quot,rem);

      
       REQUIRE(rem.toString() == "0"); // THIS IS WRONG
       REQUIRE(quot.toString() == "4"); 
     
       //REQUIRE(quot.toStringBinary() == "1111");
      
    }
       
       SECTION("Testing Div 2")
    {

      ReallyLongInt test1(125);
      ReallyLongInt test2(3);
      ReallyLongInt quot;
      ReallyLongInt rem;
      
 

      test1.div(test2,quot,rem);

      ReallyLongInt re = 125 % 3;
      ReallyLongInt qu = 125 / 3;

      REQUIRE(qu.toString() == "41"); // THIS IS WRONG
      REQUIRE(re.toString() == "2"); 
      REQUIRE(rem.toString() == "2"); // THIS IS WRONG
      REQUIRE(quot.toString() == "41"); 
      
      //REQUIRE(quot.toStringBinary() == "1111");
      
    }
       
        SECTION("Testing Div 3")
    {

      ReallyLongInt test1(-125);
      ReallyLongInt test2(3);
      ReallyLongInt quot;
      ReallyLongInt rem;
      
 

      test1.div(test2,quot,rem);

      ReallyLongInt re = 10 % 4;
      ReallyLongInt qu = 10 / 4;

      REQUIRE(qu.toString() == "2"); // THIS IS WRONG
      REQUIRE(re.toString() == "2"); 
      REQUIRE(rem.toString() == "-2"); // THIS IS WRONG
      REQUIRE(quot.toString() == "-41"); 
      
      }

	 SECTION("Testing Div 4")
    {

      ReallyLongInt test1(400);
      ReallyLongInt test2(20);
      ReallyLongInt quot;
      ReallyLongInt rem;
      
 

      test1.div(test2,quot,rem);

      ReallyLongInt re = 125 % 5;
      ReallyLongInt qu = 125 / 5;

      //REQUIRE(qu.toString() == "41"); // THIS IS WRONG
      //REQUIRE(re.toString() == "2"); 
      REQUIRE(rem.toString() == "0"); // THIS IS WRONG
      //REQUIRE(quot.toString() == "20"); 
      
       }

	 SECTION("Testing Div 5")
    {

      ReallyLongInt test1(50);
      ReallyLongInt test2(5);
      ReallyLongInt quot;
      ReallyLongInt rem;
      
 

      test1.div(test2,quot,rem);

      ReallyLongInt re = 125 % 5;
      ReallyLongInt qu = 125 / 5;

      REQUIRE(qu.toString() == "25"); // THIS IS WRONG
      REQUIRE(re.toString() == "0"); 
      REQUIRE(rem.toString() == "0"); // THIS IS WRONG
      REQUIRE(quot.toString() == "10"); 
      
      }

       SECTION("Testing Div 6")
    {

      ReallyLongInt test1(0);
      ReallyLongInt test2(10);
      ReallyLongInt quot;
      ReallyLongInt rem;
      
 

      test1.div(test2,quot,rem);

      REQUIRE(rem.toString() == "0"); // THIS IS WRONG
      REQUIRE(quot.toString() == "0"); 
      
    }
       
       SECTION("Testing Div 7")
    {

      ReallyLongInt test1(10);
      ReallyLongInt test2(0);
      ReallyLongInt quot;
      ReallyLongInt rem;
      
 

      test1.div(test2,quot,rem);

      REQUIRE(rem.toString() == "0"); // THIS IS WRONG
      REQUIRE(quot.toString() == "0"); 
      
    }

       SECTION("Testing Expo")
    {

      ReallyLongInt test1(10);
      ReallyLongInt test2(2);

      ReallyLongInt fin =  test1.exp(test2);


      REQUIRE(fin.toString() == "100"); 
     
      
    }

        SECTION("Testing Expo 1")
    {

      ReallyLongInt test1(10);
      ReallyLongInt test2(3);

      ReallyLongInt fin =  test1.exp(test2);


      REQUIRE(fin.toString() == "1000"); 
     
      
    }

	SECTION("Testing isPrime")
    {

      ReallyLongInt test1(7);
               
      bool fin =  test1.isPrime();

      REQUIRE(fin == true); 
     
      
    }

	SECTION("Testing isPrime 1")
    {

      ReallyLongInt test1(124);
           
      bool fin =  test1.isPrime();

      REQUIRE(fin == false); 
     
      
    }
	
       	SECTION("Testing isPrime 2")
    {

      ReallyLongInt test1(2);
           
      bool fin =  test1.isPrime();

      REQUIRE(fin == true); 
     
      
      }  
       


       
      
       
       




     
  
}
