REM Build script for engine
@ECHO off
SETLocal EnableDelayedExpansion

REM Get the list of all .c files
SET cFilenames=
FOR /R  %%f in (*.) do (
    SET cFilenames=!cFilenames! %%f
)

SET assembly=engine
REM -g for debug -shared for dll

SET compilerFlags=-g -shared -Wvarargs -Wall -Werror

REM -I is include scr and inlcude the vulkan sdk
SET includeFlags=-Isrc -I%VULKAN_SDK%/Include
REM -l link with user 32 and link with vulkan 1 and vulkan sdk lib
SET linkerFlags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib
REM 
SET defines=-D_DEBUG -DKEXPORT -D_CRT_SECURE_NO_WARNINGS

ECHO "Building %assembly%...."
clang %cFilenames% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags% %linkerFlags%
