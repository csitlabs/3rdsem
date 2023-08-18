#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// The main function that returns value
// of a given postfix expression
int evaluatePostfix(string exp)
{
    // Create a stack of capacity equal to expression size
    stack<int> st;
    unordered_map<char, int> operandValues;

    // Scan all characters one by one
    for (int i = 0; i < exp.size(); ++i)
    {
        // If the scanned character is an operand
        // (alphabet here), retrieve its value from the map and push it to the stack.
        if (isalpha(exp[i]))
        {
            char operand = exp[i];
            if (operandValues.find(operand) == operandValues.end())
            {
                int value;
                cout << "Enter the value for operand " << operand << ": ";
                cin >> value;
                operandValues[operand] = value;
            }
            st.push(operandValues[operand]);
        }

        // If the scanned character is a digit, push it to the stack.
        else if (isdigit(exp[i]))
        {
            st.push(exp[i] - '0');
        }

        // If the scanned character is an operator,
        // pop two elements from stack and apply the operator
        else
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            switch (exp[i])
            {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            }
        }
    }
    return st.top();
}

// Driver code
int main()
{
    string postfixExpression;
    cout << "Enter the postfix expression: ";
    getline(cin, postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
