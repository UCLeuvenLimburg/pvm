package ast;

import java.util.ArrayList;

public abstract class Operator implements Expression {
    protected ArrayList<Expression> operands;

    public Operator(ArrayList<Expression> operands) {
        this.operands = new ArrayList<>(operands);
    }
}
