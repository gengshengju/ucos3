#include "cpu.h"
#include "os_cfg.h"

typedef struct os_tcb
{
    CPU_STK *StkPtr;
    CPU_STK_SIZE StkSize;
} OS_TCB;

typedef void (*OS_TASK_PTR)(void *p_arg);

typedef enum os_err
{
    OS_ERR_NONE = 0u,
    OS_ERR_A = 10000u,
} OS_ERR; /* TODO: implement it as listed in list 11 */

typedef struct os_rdy_list
{
    OS_TCB *HeadPtr;
    OS_TCB *TailPtr;
} OS_RDY_LIST;

#ifdef OS_GLOBALS
#define OS_EXT
#else
#define OS_EXT extern
#endif

OS_EXT OS_RDY_LIST OSRdyList[OS_CFG_PRIO_MAX];
OS_EXT OS_TCB *OSTCBCurPtr;
OS_EXT OS_TCB *OSTCBHighRdyPtr;

typedef CPU_INT08U OS_STATE; /* TODO: Current definition is my definition. Find the real definition. */
OS_EXT OS_STATE OSRunning;

#define OS_STATE_OS_STOPPED    (OS_STATE)0u
#define OS_STATE_OS_RUNNING    (OS_STATE)1u

typedef CPU_INT08U OS_PRIO; /* TODO: Current definition is my definition. Find the real definition. */
