/// <reference path="jquery.d.ts" />
/// <reference path="html.ts" />
var Revealer;
(function (Revealer) {
    function processRevealee(revealee) {
        revealee.hide();
        var revealerCaption = revealee.attr('data-revealer');
        var revealer = createRevealer(revealerCaption);
        revealer.insertBefore(revealee);
        revealer.click(function () { revealee.show(); revealer.hide(); });
    }
    function createRevealer(caption) {
        return $("<div class=\"revealer\">" + caption + "</div>");
    }
    function initialize() {
        $("[data-revealer]").each(function () {
            var inputElement = $(this);
            processRevealee(inputElement);
        });
    }
    Revealer.initialize = initialize;
})(Revealer || (Revealer = {}));
