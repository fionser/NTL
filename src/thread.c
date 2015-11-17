
#include <NTL/thread.h>

#ifdef NTL_THREADS

#include <thread>
#include <sstream>

#endif



NTL_START_IMPL


const string& CurrentThreadID()
{
   NTL_THREAD_LOCAL static string ID;
   NTL_THREAD_LOCAL static bool initialized = false;

   if (!initialized) {
#ifdef NTL_THREADS
      stringstream ss;
      ss << this_thread::get_id();
      ID = ss.str();
#else
      ID = "0";
#endif
      initialized = true;
   }

   return ID;
}



NTL_END_IMPL
