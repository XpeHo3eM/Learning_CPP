#pragma once

void clear ()
{
#ifdef _WIN32
    system ("cls");
#elif defined (__LINUX__)
    system ("clear");
#else
    for (int i = 0; i < 8; ++i)
        std::cout << std::endl;
#endif
}
