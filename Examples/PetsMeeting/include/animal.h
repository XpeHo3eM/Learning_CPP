#pragma once



class Animal
{
public:
    virtual void voice () = 0;
};



class Cat : public Animal
{
public:
    virtual void voice ();
};



class Dog : public Animal
{
public:
    virtual void voice ();
};



void meeting (Animal* a, Animal* b);