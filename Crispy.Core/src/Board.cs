using System.Runtime.CompilerServices;
using System.Collections.Generic;
using System;

namespace Crispy.Core 
{
    public sealed class Board 
    {
        public PositionData position {get; private set;}
        private PositionData[] history;
        private int history_index = -1;

        public Board()
        {

        }
        
        public void SetPosition(PositionData new_position)
        {
            position = new_position;
            // Clear history
            System.Array.Clear(history, 0 , history.Length);
            history_index = -1;
        }

        public void MakeMove()
        {

        }

        public void UndoLastMove()
        {

        }
    }
}