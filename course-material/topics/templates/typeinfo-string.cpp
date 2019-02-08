template<>
struct typeinfo<std::string>
{
    static std::string zero()
    {
        return "";
    }
};
