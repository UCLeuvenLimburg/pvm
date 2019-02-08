package ast;

import java.util.Map;

public class Literal implements Expression {
    private double value;

    public Literal(double value) {
        this.value = value;
    }

    @Override
    public double evaluate(Map<String, Double> context) {
        return value;
    }
}
