/// <reference path="jquery.d.ts" />
/// <reference path="underscore.d.ts" />
var HTML;
(function (HTML) {
    function newElement(tag) {
        return $(document.createElement(tag));
    }
    function newUnorderedList(children) {
        var ul = newElement('ul');
        _.each(children, function (child) {
            var li = newElement('li');
            li.append(child);
            ul.append(li);
        });
        return ul;
    }
    HTML.newUnorderedList = newUnorderedList;
    function newHyperlink(url, contents) {
        var a = newElement('a');
        a.attr('href', url);
        a.append(contents);
        return a;
    }
    HTML.newHyperlink = newHyperlink;
})(HTML || (HTML = {}));
