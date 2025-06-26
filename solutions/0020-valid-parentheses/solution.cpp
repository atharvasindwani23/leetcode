class Solution {
public:
   bool isValid(string s) {
    stack<char> elements;
    elements.push(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (elements.empty()) {
            elements.push(s[i]);
            continue;
        }
        char c = elements.top();
        char next = s[i];
        if (c == '(' && next == ')' || c == '[' && next == ']' || c == '{' && next == '}') {
            elements.pop();
        } else {
            elements.push(next);   
        }
    }
    return elements.empty();
}
    // "([])"
};
