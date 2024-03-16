Classes, Types, Functions, Structs are named using `CammelCase`
```c++
class UciClient
{
    public:
        void DoSomething();
}

```

Use of prefix `a_` for function arguments
```c++
void foo(Board* a_board)
{
    ....
    a_board->MakeMove(move);
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
const char* PRODUCT_VERSION = "3.0";
```

local function variables in `snake_case`
```c++ 
Vector<Move> move_list = a_board.GenerateMoves();
```