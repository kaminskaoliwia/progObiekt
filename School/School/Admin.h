#pragma once
#include "Worker.h"

/* WYMAGANIA: */
/* Dla pracownika administracyjnego pamietac na jakim stanowisku pracuje 
(mozliwosci: mlodszy specjalista, specjalista, starszy specjalista) */

class Admin : public Worker
{
public:
  Admin( string name="", int age=0, double salary=0, int exp=0, Jobs mJob = MLODSZY_SPECJALISTA);
  Admin( const Admin& a );
  virtual ~Admin() {}

  Jobs getJobEnum();
  void setJob( Jobs job );

  void printRole() const override;
  void calculateSalary() const override;

  static string jobsToString( Jobs job );

private:
  Jobs mJob;
};

