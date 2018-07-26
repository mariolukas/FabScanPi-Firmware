
#ifndef __PINS_H__
#define __PINS_H__

#if MB(FABSCANPI)
  #include "pins_FABSCANPI.h"
#elif MB(CYCLOP)
 #include "pins_CYCLOP.h"
#elif MB(SANGOINOLOLU)
 #include "pins_SANGOINOLOLU.h"
#endif

#endif
