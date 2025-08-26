//
//  CPU-M
//
//  (c) 2025 TDolphin
//

#include "Main.hpp"

#include "App.hpp"

#include <iostream>
#include <proto/dos.h>
#include <proto/exec.h>

using namespace std;

int main(int argc, char **argv)
{
#ifdef TRACE
    std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif

    try
    {
        App::instance().Run();
    }
    catch (const runtime_error &e)
    {
        cerr << "Runtime exception: " << e.what() << endl;
        return -1;
    }
    catch (const exception &e)
    {
        cerr << "Exception: " << e.what() << endl;
        return RETURN_FAIL;
    }
    catch (...)
    {
        cerr << "Unknown exception (...)" << endl;
        return RETURN_FAIL;
    }

    return RETURN_OK;
}
