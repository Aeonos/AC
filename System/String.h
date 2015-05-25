namespace AC{
namespace System{
class String: public AC::System::AObject{
  private:
    std::string _FromNumber(int Value);
    std::string _FromNumber(double Value);
    
  public:
    String();
    String(double Value);
    String(int Value);
    String(const char* c_String);
    String(const std::string& stdString);
    String(const String & other);

    virtual ~String();

    virtual std::string GetID() const;

    String operator=(const String& other);
    
    String& operator +=(const String& other);
    String& operator +=(const std::string& other);
    String& operator +=(int other);
    String& operator +=(double other);
    String& operator *=(int other);
    String& operator *=(double other);
    
    
    String FromNumber(int Value);
    String FromNumber(double Value);
    
  protected:
    std::string _Primitive;
};
}}
