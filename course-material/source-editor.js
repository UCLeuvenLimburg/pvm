var SourceEditor;
(function (SourceEditor) {

    function initialize()
    {
        var dom = ace.require("ace/lib/dom")
        var commands = ace.require("ace/commands/default_commands").commands

        commands.push({
                name: "Toggle Fullscreen",
                bindKey: {win: "Ctrl-M", mac: "Command-Option-M"},
                exec: function(editor) {
                        dom.toggleCssClass(document.body, "fullscreen")
                        dom.toggleCssClass(editor.container, "fullscreen-editor")
                        editor.resize()
                }
        });

        $('.source-editor').uniqueId();
        
        $('.source-editor').each( function ()
                                  {
                                      var elt = $(this);
                                      var eltId = elt.attr('id');

                                      var editor = ace.edit(eltId);                         
                                      editor.setTheme("ace/theme/github");
                                      editor.setHighlightActiveLine(false);
                                      editor.setShowPrintMargin(false);
                                      editor.getSession().setMode("ace/mode/c_cpp");
                                  } );
    }

    SourceEditor.initialize = initialize;
})(SourceEditor || (SourceEditor = {}));
