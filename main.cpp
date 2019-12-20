#include <iostream>
#include <string>
#include "named_type.hpp"

using namespace fluent;

using FirstName = NamedType<std::string, struct FirstNameTag>;
using LastName = NamedType<std::string, struct LastNameTag>;

static const FirstName::argument firstName;
static const LastName::argument lastName;

template<typename TypeToPick, typename... Types>
TypeToPick pick(Types&&... args)
{
    return std::get<TypeToPick>(std::make_tuple(std::forward<Types>(args)...));
}

template<typename Arg0, typename Arg1>
void printName(Arg0&& arg0, Arg1&& arg1)
{
    auto const firstName = pick<FirstName>(arg0, arg1);
    auto const lastName = pick<LastName>(arg0, arg1);
    std::cout << firstName.get() << "\t" << lastName.get() << "\n";
}

void print(FirstName const& firstName, LastName const& lastName)
{
    std::cout << firstName.get() << "\t" << lastName.get() << "\n";
}

int main(int argc, char** argv)
{
    print(firstName = "James", lastName = "Bond");
    printName(firstName = "James", lastName = "Bond");
    printName(lastName = "Bond", firstName = "James");
    return 0;
}