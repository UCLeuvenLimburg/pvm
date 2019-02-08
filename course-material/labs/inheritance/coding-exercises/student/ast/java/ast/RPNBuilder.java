package ast;

import java.util.ArrayList;
import java.util.Stack;

public class RPNBuilder {
    private Stack<Expression> stack;

    public RPNBuilder() {
        stack = new Stack<Expression>();
    }

    public RPNBuilder add() {
        Expression a = stack.pop();
        Expression b = stack.pop();

        ArrayList<Expression> operands = new ArrayList<>();
        operands.add(a);
        operands.add(b);

        stack.push(new Addition(operands));

        return this;
    }

    public RPNBuilder multiply() {
        Expression a = stack.pop();
        Expression b = stack.pop();

        ArrayList<Expression> operands = new ArrayList<>();
        operands.add(a);
        operands.add(b);

        stack.push(new Multiplication(operands));

        return this;
    }

    public RPNBuilder literal(double x) {
        stack.push(new Literal(x));

        return this;
    }

    public RPNBuilder variable(String identifier) {
        stack.push(new Variable(identifier));

        return this;
    }

    public Expression build() {
        return stack.peek();
    }
}
