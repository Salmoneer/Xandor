namespace xandor {
    class bit {
    private:
        bool _bool_value;
        int _int_value;
    public:
        bit(bool bool_value);
        bit (int int_value);

        int get_int();
        bool get_bool();
    };
}