
#ifndef IN_MISC_H
#define IN_MISC_H

#include "c_base.h"
#include "u_participant.h"
#include "in_commonTypes.h"

#define IN_ALIGN(alignment, address)                       \
    ((in_long)(address) + (alignment) - 1U -             \
    ((in_long)(address) + (alignment) - 1U) % (alignment))

c_object in_participantCreateType(u_participant participant,
                                  const c_char *typeName);
                                  
char *   in_stringDup(const char *string); 
char *   in_dumpToString(void *data, unsigned int length);
      

#endif /* IN_MISC_H */

