/*
 *                         OpenSplice DDS
 *
 *   This software and documentation are Copyright 2006 to TO_YEAR PrismTech
 *   Limited, its affiliated companies and licensors. All rights reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 *
 */

/** \file os/linux/code/os_sharedmem.c
 *  \brief Linux 2.6 shared memory management
 *
 * Implements shared memory management for Linux by
 * including the POSIX, SVR4 and heap implementation
 */

#include <assert.h>
#include "os__sharedmem.h"
#include "../posix/code/os_sharedmem_file.c"
#include "../svr4/code/os_sharedmem_seg.c"
#include "../common/code/os_sharedmem_heap.c"
#include "../common/code/os_sharedmem.c"

void
os_sharedAttrInit (
    os_sharedAttr *sharedAttr)
{
    assert (sharedAttr != NULL);
    sharedAttr->lockPolicy = OS_LOCK_DEFAULT;
    sharedAttr->sharedImpl = OS_MAP_ON_SEG;
    sharedAttr->userCred.uid = 0;
    sharedAttr->userCred.gid = 0;
#ifdef __x86_64__
    sharedAttr->map_address = (void *)0x140000000;
#else
    sharedAttr->map_address = (void *)0x20000000;
#endif
}
