class T_cell
{
private:
    bool act_state;
    bool next_state;

public:
    T_cell(bool state = 0) : act_state{state}, next_state{state} {}
    bool check_state()
    {
        return act_state;
    }
    bool check_next_state()
    {
        return next_state;
    }
    void change_act_state(bool state)
    {
        act_state = state;
    }
    void change_state(bool state)
    {
        next_state = state;
    }
};