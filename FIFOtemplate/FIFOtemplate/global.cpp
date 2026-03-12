#include "global.h"

QInfo::QInfo(int key, int* pTab) : key(key), pTab(pTab) {
}

QInfo::~QInfo() {
}

std::ostream& operator << (std::ostream& out, const QINFO& info) {
  out << "Key: " << info.key;
  return out;
}
