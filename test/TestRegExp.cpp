#include <vector>
#include <iostream>
#include <string>
#include "RegExp.h"
#include "gtest/gtest.h"

TEST(TestRegExp, dotNotationClassMethods) {
  std::vector<std::string> methods;
  const std::string s1 =
      R"(
        cat.eat(); 
        dog.eat();
        bool fishFed = fish.isHungry();
        dog.setAge(3);
        )";

  methods = RegExp::getMethodNames(s1);
  EXPECT_EQ(4, methods.size());
  EXPECT_EQ("eat", methods.at(0));
  EXPECT_EQ("eat", methods.at(1));
  EXPECT_EQ("isHungry", methods.at(2));
  EXPECT_EQ("setAge", methods.at(3));
}

TEST(TestRegExp, arrowNotationClassMethods) {
  std::vector<std::string> methods;
  const std::string s1 =
      R"(
        cat->eat(); 
        dog->eat();
        bool fishFed = fish->isHungry();
        dog->setAge(3);
        )";

  methods = RegExp::getMethodNames(s1);
  EXPECT_EQ(4, methods.size());
  EXPECT_EQ("eat", methods.at(0));
  EXPECT_EQ("eat", methods.at(1));
  EXPECT_EQ("isHungry", methods.at(2));
  EXPECT_EQ("setAge", methods.at(3));
}

TEST(TestRegExp, constructorCallPrefixedWithNew) {
  std::vector<std::string> methods;
  const std::string s1 =
      R"(
        Animal* animal = new Animal();
        Animal* dog1 = new Dog("Chihuahua", 3);
        Animal* dog2 = new Dog("Bulldog", 5);
        dog1->eat();
        dog2->eat();
        )";

  methods = RegExp::getMethodNames(s1);
  EXPECT_EQ(5, methods.size());
  EXPECT_EQ("Animal", methods.at(0));
  EXPECT_EQ("Dog", methods.at(1));
  EXPECT_EQ("Dog", methods.at(2));
  EXPECT_EQ("eat", methods.at(3));
  EXPECT_EQ("eat", methods.at(4));
}

TEST(TestRegExp, constructorCallProcedural) {
  std::vector<std::string> methods;
  const std::string s1 =
      R"(
        Animal animal = Animal();
        Dog dog1 = Dog("Chihuahua", 3);
        Dog dog2 = Dog("Bulldog", 5);
        dog1.eat();
        dog2.eat();
        )";

  methods = RegExp::getMethodNames(s1);
  EXPECT_EQ(5, methods.size());
  EXPECT_EQ("Animal", methods.at(0));
  EXPECT_EQ("Dog", methods.at(1));
  EXPECT_EQ("Dog", methods.at(2));
  EXPECT_EQ("eat", methods.at(3));
  EXPECT_EQ("eat", methods.at(4));
}

TEST(TestRegExp, withIfStatements) {
  std::vector<std::string> methods;
  const std::string s1 =
      R"(
        if(dog->age() > 5) {
            dog->bark();
        }else if(dog->age() > 3) {
            dog->eat();
        }else{
            dog->sleep();
        }
        )";

  methods = RegExp::getMethodNames(s1);
  EXPECT_EQ(5, methods.size());
  EXPECT_EQ("age", methods.at(0));
  EXPECT_EQ("bark", methods.at(1));
  EXPECT_EQ("age", methods.at(2));
  EXPECT_EQ("eat", methods.at(3));
  EXPECT_EQ("sleep", methods.at(4));
}

TEST(TestRegExp, withForLoopStatements) {
  std::vector<std::string> methods;
  const std::string s1 =
      R"(
        for(int i=0; i < 5; ++i)
            dog->bark();
        )";

  methods = RegExp::getMethodNames(s1);
  EXPECT_EQ(1, methods.size());
  EXPECT_EQ("bark", methods.at(0));
}

TEST(TestRegExp, withWhileLoopStatements) {
  std::vector<std::string> methods;
  const std::string s1 =
      R"(
        int i = 0;
        while(i < 5) {
            dog->bark();
            i++;
        }
        )";

  methods = RegExp::getMethodNames(s1);
  EXPECT_EQ(1, methods.size());
  EXPECT_EQ("bark", methods.at(0));
}

TEST(TestRegExp, methodDefinition) {
  std::vector<std::string> methods;
  const std::string s1 =
      R"(
        void Dog::bark() {
            std::cout << "Arf! arf!" << std::endl
        }
        )";

  methods = RegExp::getMethodNames(s1);
  EXPECT_EQ(0, methods.size());
}

TEST(TestRegExp, stdMethodsAndError) {
  std::vector<std::string> methods;
  const std::string s1 =
      R"(
        if(dog->age() > 0) {
            std::string dAge = std::to_string(dog->age());
        } else {
            throw std::invalid_age("Age invalid");
        }
        )";

  methods = RegExp::getMethodNames(s1);
  EXPECT_EQ(4, methods.size());
  EXPECT_EQ("age", methods.at(0));
  EXPECT_EQ("to_string", methods.at(1));
  EXPECT_EQ("age", methods.at(2));
  EXPECT_EQ("invalid_age", methods.at(3));
}

TEST(TestRegExp, dynamicAndStaticCast) {
  std::vector<std::string> methods;
  const std::string s1 =
      R"(
        Piece* rook = dynamic_cast<Rook*>((*board)[xRookOld][destination->getY()]);
        Piece* rook = static_cast<Rook*>((*board)[xRookOld][destination->getY()]);
        Piece* rook = static_cast<int>((*board)[xRookOld][destination->getY()]);
        )";

  methods = RegExp::getMethodNames(s1);
  EXPECT_EQ(6, methods.size());
  EXPECT_EQ("dynamic_cast", methods.at(0));
  EXPECT_EQ("getY", methods.at(1));
  EXPECT_EQ("static_cast", methods.at(2));
  EXPECT_EQ("getY", methods.at(3));
  EXPECT_EQ("static_cast", methods.at(4));
  EXPECT_EQ("getY", methods.at(5));
}
