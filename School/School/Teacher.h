#pragma once
#include "Worker.h"
#include <iostream>
using namespace std;
#include <string>

/* WYMAGANIA */
/*  pamietac jakiego przedmiotu uczy */
/*  i czy jest wychowawca a jesli tak to jakiej klasy (np "2b") */

class Teacher : public Worker
{
public:
  Teacher( string name="", int age=0,  double salary=0, int exp=0, Subjects subject = POLSKI, string mclass="");
  Teacher( const Teacher& t );
  virtual ~Teacher() {}

  Subjects getSubjectEnum() const;
  string getClass() const;
  bool isWychowawca() const;

  void printRole() const override;
  void calculateSalary() const override;

  void setSubject(Subjects subject);
  void setClass( string mclass );

  static string subjectToString(Subjects subject);

private:
  Subjects mSubject;
  string mClass = ""; /* wychowawca */ 

};

