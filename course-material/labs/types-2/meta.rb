require 'MetaData2'
require 'Html2'
require 'Template2'
require 'Code'
require 'Cpp'
require 'Upload2'
require 'Html'
require 'Environment'
require 'pathname'
require 'Shortcuts'
require '../shared.rb'


module Quiz
  extend Html::Generation::Quiz
end


class Context < SharedContext

end


meta_object do
  extend MetaData2
  extend Template2::Actions
  extend Upload2::Actions
  extend Shortcuts::Actions

  def remote_directory
    world.parent.remote_directory + Pathname.pwd.basename.to_s
  end

  bind( { :html => template(input: 'assignment.html.template', context: Context.new) } )
  quick_all :html
  
  uploadable('assignment.html')
end
