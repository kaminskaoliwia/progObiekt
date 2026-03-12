#include "global.h"

QInfo::QInfo(int key, int* pTab) : key(key) {

//alokacja tablicvy 2-wu elem i zainicjoiwqanie jej
  this->key=key;
  pTab = new int[2];
  pTab[0] = key;
  pTab[1] = key;
}

QInfo::~QInfo() {
  delete [] pTab;
}

std::ostream& operator << (std::ostream& out, const QINFO& info) {
  out << "Key: " << info.key << " pTab[0] = " << info.pTab[0] << " pTab[1] = " << info.pTab[1];
  return out;
}
