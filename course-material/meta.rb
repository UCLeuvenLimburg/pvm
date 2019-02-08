require 'Template2'
require 'Html2'
require 'MetaData2'
require 'Upload2'
require 'Shortcuts'



class Context
  include Contracts::TypeChecking
  
  def topic(name, description, handouts: false)
    typecheck binding do
      assert(name: string, description: string)
    end

    path = Pathname.pwd + "topics/#{name}"

    if not File.directory? path
    then abort "ERROR: No topic directory #{name}"
    end

    url = "topics"
    
    slides_link = %{<a href="#{url}/#{name}.pdf">#{description}</a>}
    handout_link = if handouts
                   then %{ <a class="handout" href="#{url}/#{name}-handouts.pdf">(handouts)</a>}
                   else ''
                   end
    
    "#{slides_link}#{handout_link}"
  end

  def lab(name, description)
    typecheck binding do
      assert(name: string, description: string)
    end

    if not File.directory? "labs/#{name}"
    then abort "ERROR: No lab directory #{name}"
    end

    %{<a href="labs/#{name}/assignment.html">#{description}</a>}
  end
end


meta_object do
  extend MetaData2
  extend Template2::Actions
  extend Upload2::Actions
  extend Shortcuts::Actions

  inherit_remote_directory

  bind( { :index => template(input: 'index.html.template', context: Context.new) } )
  
  uploadable 'pvm.css', 'revealer.js', 'source-editor.js', 'html.js', 'quiz.js', 'index.html'

  quick_recursive_all
end
