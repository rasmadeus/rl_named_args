#include <iostream>
#include <string>
#include "named_type.hpp"

using namespace fluent;

using FirstName = NamedType<std::string, struct FirstNameTag>;
using LastName = NamedType<std::string, struct LastNameTag>;

static const FirstName::argument firstName;
static const LastName::argument lastName;

void print(FirstName const& firstName, LastName const& lastName)
{
    std::cout << firstName.get() << "\t" << lastName.get() << "\n";
}

int main(int argc, char** argv)
{
    print(firstName = "James", lastName = "Bond");
    return 0;
}