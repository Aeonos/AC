
namespace AC{
namespace System{
  class AObject{
    public:
      AObject();
      ~AObject();

      virtual std::string GetID() const = 0;

    protected:
      std::string _ClassID;
  };
}
}
