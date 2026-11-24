// main.cpp — entry point. Wires config and subsystems together.

#include "ccutool/settings.h"
#include "ccutool/watcher.h"
#include "ccutool/rotator.h"
#include "ccutool/store.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    ccutool::Settings settings = ccutool::Settings::load_default();
    ccutool::Watcher watcher(settings.store_path);
    ccutool::Rotator rotator(settings.store_path);
    ccutool::Store store(settings.store_path);
    std::fprintf(stderr, "[ccu-tool] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
