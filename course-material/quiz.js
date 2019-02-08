/// <reference path="jquery.d.ts" />
/// <reference path="html.ts" />
var Quiz;
(function (Quiz) {
    function processValidatedInput(inputElement) {
        var validatorLiteral = inputElement.attr('data-validator');
        var validator = eval(validatorLiteral);
        var feedback = $('<span class="quiz-feedback">&#10004;</span>');
        inputElement.after(feedback);
        feedback.hide();
        inputElement.change(function () {
            var answer = inputElement.val();
            var isCorrect = validator(answer);
            if (isCorrect) {
                inputElement.removeClass('incorrect');
                inputElement.addClass('correct');
                feedback.show();
            }
            else {
                inputElement.removeClass('correct');
                inputElement.addClass('incorrect');
                feedback.hide();
            }
        });
    }
    function formatQuizzes() {
        $("input[data-validator]").each(function () {
            var inputElement = $(this);
            processValidatedInput(inputElement);
        });
    }
    Quiz.formatQuizzes = formatQuizzes;
    function verbatim(expected) {
        return function (actual) {
            return expected == actual;
        };
    }
    Quiz.verbatim = verbatim;
    function numeric(number, delta) {
        return function (actual) {
            var difference = Math.abs(number - Number(actual));
            return difference <= delta;
        };
    }
    Quiz.numeric = numeric;
})(Quiz || (Quiz = {}));
