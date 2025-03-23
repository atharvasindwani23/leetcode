class Solution {
public:
   bool isValid(string s) {
    stack<char> elements;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            elements.push(c);
        } else {
            if (elements.empty()) return false; // Prevent accessing top() on empty stack
            
            char top = elements.top();
            if ((top == '(' && c == ')') ||
                (top == '[' && c == ']') ||
                (top == '{' && c == '}')) {
                elements.pop();
            } else {
                return false; // Mismatched closing bracket
            }
        }
    }
    
    return elements.empty(); // Stack should be empty for valid brackets
}
    // "([])"
};
