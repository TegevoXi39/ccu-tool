// watcher.cpp — part of ccu-tool.

#include "ccutool/watcher.h"

#include <cstdio>

namespace ccutool {

Watcher::Watcher(const std::string& config_path)
    : config_path_(config_path) {}

void Watcher::configure(const std::string& key, const std::string& value) {
    if (key == "verbose") verbose_ = (value == "true");
}

bool Watcher::run() {
    if (verbose_) std::fprintf(stderr, "[ccu-tool] watcher: run\n");
    // core logic lives here
    return true;
}

}  // namespace ccutool
