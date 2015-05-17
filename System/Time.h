namespace AC{
namespace System{
class Time: public AC::System::AObject{
  private:
  public:
    Time(const Time& other);
    Time(Time&& other);
    
    ~Time();
    
    Time& operator=(const Time& rhs);
    
    friend std::ostream& operator<<(std::ostream& out, const Time& rhs);
    
    static Time Now();
    
    virtual inline std::string ToString();
    
    virtual std::string GetID() const;
    
  protected:
    Time(const time_t& TimeStamp);
    
    time_t _Time;
};
}}
