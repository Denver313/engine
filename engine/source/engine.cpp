#include "engine.hpp"
#include <iostream>
#include <SDL2/SDL.h>

// Overloading the operator << to output the SDL version to the stream
std::ostream& operator << (std::ostream& out, const SDL_version& version)
{
    out << static_cast<int>(version.major) << '.';
    out << static_cast<int>(version.minor) << '.';
    out << static_cast<int>(version.patch);

    return out;
}

bool Engine::Initialize()
{
    std::cout << "========== Engine v.0.0 ==========" << std::endl;

    SDL_version compiled = {0, 0, 0};
    SDL_version linked   = {0, 0, 0};
    SDL_VERSION(&compiled);
    SDL_GetVersion(&linked);

    // Validation of the SDL version
    if (SDL_COMPILEDVERSION != SDL_VERSIONNUM(linked.major, linked.minor, linked.patch))
    {
        std::cerr << "WARNING: SDL2 compiled and linked version mismatch: " 
            << compiled << " " << linked << std::endl;
    }

    return true;
}