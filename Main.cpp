#ifdef EMSCRIPTEN
#include <emscripten.h>
void mainLoopWrapper();
#else
#endif

#include "include/MainLoop.h"

int main(int argc, char* argv[])
{
    init();

#ifdef EMSCRIPTEN
	emscripten_set_main_loop(mainLoopWrapper, 60, 1);
}
void mainLoopWrapper() {
#else
	while (true)
#endif
	{
        mainLoop();
	}
}