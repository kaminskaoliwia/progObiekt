#pragma once
#include <iostream>
using namespace std;
#include <string>

#define MAXSUBJECTS NIEMIECKI +1
enum Subjects{ POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI };

class Person
{
public:
    Person( string name="", int age=0);
    Person( const Person& p );
    //destruktor
    virtual ~Person() { }
    //defaultowy operator =
    Person& operator = ( const Person& p ) = default;

    string getName();
    int getAge();
    void setName( string newName );
    void setAge( int newAge );
    void setPerson( string newName, int newAge );

private:
    string mName;
    int mAge;
};

//INLINE

inline string Person::getName()
{
    return this->mName;
}

inline int Person::getAge()
{
    return this->mAge;
}

inline void Person::setName( string newName )
{
    this->mName = newName;
}

inline void Person::setAge( int newAge )
{
    this->mAge = newAge;
}
