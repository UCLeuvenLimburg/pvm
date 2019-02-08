package ast;

import java.util.ArrayList;
import java.util.Map;

public class Multiplication extends Operator {
    public Multiplication(ArrayList<Expression> operands) {
        super(operands);
    }

    @Override
    public double evaluate(Map<String, Double> context) {
        double total = 1;

        for (Expression operand : this.operands) {
            total *= operand.evaluate(context);
        }

        return total;
    }
}
