#include<iostream>
using namespace std;

//implementation

class MoveType
{
    public:
    virtual void move() = 0 ;
};
class Walk : public MoveType
{
     public:
   void move() override
   {
       cout<<" is Walking\n";
   }
};
class Swim : public MoveType
{
     public:
    void move() override
    {
        cout<<" is Swiming\n";
    }
};
class Fly : public MoveType
{
     public:
    void move() override
    {
        cout<<" is Flying \n";
    }
};


//Abstraction
class Animal
{
    protected:
        MoveType* moveType;
    public:
        virtual void makeMove() =0 ;

};
class Human: public Animal
{
    public:
    Human(MoveType* moveTypeGiven)
    {
        this->moveType = moveTypeGiven;
    }
    void makeMove() override
    {
        cout<<"Human ";
        this->moveType->move();
    }
};
class Fish: public Animal
{
    public:
    Fish(MoveType* moveTypeGiven)
    {
        this->moveType = moveTypeGiven;
    }
    void makeMove() override
    {
        cout<<"Fish ";
        this->moveType->move();
    }
};
class Bird: public Animal
{
    public:
    Bird(MoveType* moveTypeGiven)
    {
        this->moveType = moveTypeGiven;
    }
    void makeMove() override
    {
        cout<<"Bird ";
        this->moveType->move();
    }
};

//client 
class Client
{
    public: 
    Client()
    {
        MoveType* moveTypeWalk = new Walk;
        Animal* human = new Human(moveTypeWalk);
        human->makeMove();

        MoveType* moveTypeSwim = new Swim;
        Animal* fish = new Fish(moveTypeSwim);
        fish->makeMove();

        MoveType* moveTypeFly = new Fly;
        Animal* bird = new Bird(moveTypeFly);
        bird->makeMove();

        delete human;
        human = new Human(moveTypeSwim);
        human->makeMove();

        delete bird;
        bird = new Bird(moveTypeWalk);
        bird->makeMove();

        //like this we can combine human fish bird 
        //with walk swim fly to get 9 cartition products 
        //like bird and swim , human and fly and so on.
         
    }
};

int main()
{
    Client Demo;
    return 0;
}