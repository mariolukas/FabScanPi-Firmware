
#ifndef __PINS_H__
#define __PINS_H__

#if MB(FABSCANPI)
  #include "pins_FABSCANPI.h"
#elif MB(FABSCANPIV2)
 #include "pins_FABSCANPIV2.h"
#elif MB(CYCLOP)
 #include "pins_CYCLOP.h" 
#elif MB(SANGOINOLOLU)
 #include "pins_SANGOINOLOLU.h"
#elif MB(CNCSHIELD)
 #include "pins_CNCSHIELD.h"
#endif

#endif
