#define AC_SYSTEM_TIME_DEFAULT_FORMAT_STRING "%c"
#define AC_SYSTEM_TIME_FORMAT_STRING_BUFFERSIZE 120

namespace AC{
namespace System{
  class Time: public AC::System::AObject{
  private:
  public:
    
    Time(const Time& other);
    Time(Time&& other);
    Time(struct tm*& TimeStamp);
    Time(const time_t& TimeStamp);
    
    //~Time();
    friend std::ostream& operator<<(std::ostream& out, Time& rhs);
    Time& operator=(const Time& rhs);
    
    Time& operator-=(const Time& rhs);
    Time& operator-=(int rhs);
    Time& operator+=(int rhs);
    
    friend Time operator+(const Time& lhs, const Time& rhs);
    friend Time operator-(const Time& lhs, const Time& rhs);
    friend Time operator+(const Time& lhs, int rhs);
    friend Time operator+(int lhs, const Time& rhs);
    friend Time operator-(const Time& lhs, int rhs);
    friend Time operator-(int lhs, const Time& rhs);
    
    virtual std::string GetID() const;
    
    int GetSeconds() const;
    int GetMinutes() const;
    int GetHours() const ;
    int GetDayOfMonth() const;
    int GetMonth() const;
    int GetYears() const;
    int GetDayOfWeek() const;
    int GetDayOfYear() const;
    bool IsDaylightSaving() const;
    
    static Time Now();
    
    virtual inline std::string ToString(const char* Format = AC_SYSTEM_TIME_DEFAULT_FORMAT_STRING);
    
    // CONSTRUCTOR
  protected:
    
    time_t _Time;
  };
}}