#ifndef AC_SYSTEM_CLOCK
#define AC_SYSTEM_CLOCK

#include <string>

namespace AC{
namespace System{
  class Clock: public Object{
  private:
  public:
    Clock();
    
    // class should not be transverable
    Clock(const Clock& other) = delete;
    Clock(Clock&& other) = delete;
    Clock operator=(const Clock& other) = delete;
    
    int Start();
    int Stop();
    
    std::string ToString() const;
    
    bool IsRunning() const;
    
    virtual std::string GetID() const;
    
    friend std::ostream& operator<<(std::ostream& out, const Clock& rhs);
  protected:
    bool _IsRunning;
    
    std::chrono::time_point<std::chrono::high_resolution_clock> _Start;
    std::chrono::time_point<std::chrono::high_resolution_clock> _Stop;
  };
}}

#endif