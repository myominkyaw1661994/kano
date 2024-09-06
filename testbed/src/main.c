#include "../../engine/src/core/logger.h"

int main(void) {
    KFATEL("Fetal testing %f", 3.31);
    KERROR("Error testing");
    KDEBUG("Debug testing");
    KWARN("WARN testing");
    KINFO("INFO testing");
    KTRACE("TRACE testing");
    return 0;
}