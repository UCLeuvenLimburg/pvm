require 'MetaData2'
require 'Upload2'


meta_object do
  extend MetaData2
  extend Upload2::Actions

  def remote_directory
    Pathname.new '/www/pvm'
  end
end
