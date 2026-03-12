#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
using namespace std;

#define QINFO QInfo

class QInfo {

public:
  int key;
  int* pTab;

  QInfo(int key = 0, int* pTab = nullptr);
  virtual ~QInfo();

  friend ostream& operator << (ostream& out, const QINFO& info); 

  //---gettery---
  inline int getKey() const;
  inline int* getTab() const;

};

//---INLINE---
inline int QINFO::getKey() const {
  return key;
}

inline int* QINFO::getTab() const {
  return pTab;
}
#endif