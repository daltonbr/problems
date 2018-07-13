public class Solution
{
    public bool IsValid(string s)
    {
        Stack<int> stack = new Stack<int>();
     
        foreach (char c in s)
        {
            if (c == '(') { stack.Push(1); }
            
            if (c == '[') { stack.Push(2); }
            
            if (c == '{') { stack.Push(3); }
            
            try
            {
                if (c == ')')
                {
                    if (stack.Peek() != 1) return false;
                    stack.Pop();
                }

                if (c == ']')
                {
                    if (stack.Peek() != 2) return false;
                    stack.Pop();
                }

                if (c == '}')
                {
                    if (stack.Peek() != 3) return false;
                    stack.Pop();
                }
            }
            // Popping empty stack
            catch (InvalidOperationException ex)
            {
                return false;
            }
        }
        if (stack.Count == 0) return true;
        return false;
    }
}