package ast;

import java.util.Map;

public class Variable implements Expression {

    private String identifier;

    public Variable(String identifier) {
        this.identifier = identifier;
    }

    @Override
    public double evaluate(Map<String, Double> context) {
        return context.get(this.identifier);
    }
}
