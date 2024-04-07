Classes, Types, Functions, Structs are named using `CammelCase`
```c++
class UciClient
{
    public:
        void DoSomething();
}

```

Use of Prefix `m_` for class / struct members
```c++
class UciClient
{
    private:
        Vector<CommandBase> m_commands;
}
```

Constants in `UPPER_SNAKE_CASE`
```C++
constexpr int PLAYER_ELO = 1700;
```

local function variables and functtion parameters in `snake_case`
```c++ 
Vector<Move> move_list = board.GenerateMoves();
```

```c++
void PlayAwesomeMove(Board* board)
{
    ....
    a_board->MakeMove(move);
}
```