package ast;

import java.util.ArrayList;
import java.util.Map;

public class Addition extends Operator {
    public Addition(ArrayList<Expression> operands) {
        super(operands);
    }

    @Override
    public double evaluate(Map<String, Double> context) {
        double total = 0;

        for (Expression operand : this.operands) {
            total += operand.evaluate(context);
        }

        return total;
    }
}
