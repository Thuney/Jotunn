#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE VectorTests
#include <boost/test/unit_test.hpp>

#include "Math/Vector.h"

using namespace Jotunn;

BOOST_AUTO_TEST_CASE(ConstructorTests, *boost::unit_test::tolerance(0.0001))
{
    Vector2D a;
    Vector3D b;

    BOOST_TEST( a.x == 0.0f );
    BOOST_TEST( a.y == 0.0f );

    BOOST_TEST( b.x == 0.0f );
    BOOST_TEST( b.y == 0.0f );
    BOOST_TEST( b.z == 0.0f );

    a = Vector2D(5.0f, -5.0f);
    BOOST_TEST( a.x == 5.0f );
    BOOST_TEST( a.y == -5.0f );

    b = Vector3D(0.1211f, -0.7386f, 0.4287f);
    BOOST_TEST( b.x == 0.1211f );
    BOOST_TEST( b.y == -0.7386f );
    BOOST_TEST( b.z == 0.4287f );
}

BOOST_AUTO_TEST_CASE(AdditionTests, *boost::unit_test::tolerance(0.0001))
{

    Vector2D a;
    Vector3D b;

    a.x += 3.3f;
    a.y += -4.7f;

    BOOST_TEST( a.x == 3.3f );
    BOOST_TEST( a.y == -4.7f );

    b.x += 400.000007f;
    b.y += -4.7f;
    b.z += -0.6666f;

    BOOST_TEST( b.x == 400.000007f );
    BOOST_TEST( b.y == -4.7f );
    BOOST_TEST( b.z == -0.6666f );

}