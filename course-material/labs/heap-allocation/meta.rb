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
  include Contracts::TypeChecking

  def initialize
    @last_exercise_index = 0
    @last_code_index = 0
  end

  def increment_exercise_counter
    @last_exercise_index += 1
  end

  def increment_code_index
    @last_code_index += 1
  end

  def interpret_exercise(source, input: nil)
    typecheck do
      assert(source: string)
    end

    current_exercise_index = increment_exercise_counter

    basename = "temp-noupload#{current_exercise_index}"
    source_path = Pathname.new "#{basename}.cpp"
    executable_path = Pathname.new "#{basename}.exe"

    formatted_source = source_editor(source)

    File.open(source_path, 'w') do |out|
      out.write(source)
    end

    output = Cpp.compile_and_run(source_path, input: input).strip

    if input
      input_message = %{<p>Input: <code>#{input}</code></p>}
    else
      input_message = ""
    end

    format_exercise(index: current_exercise_index) do
      <<-END
        <p>What is the output of the following code?</p>
        #{formatted_source}
        #{input_message}
        <p>Output: #{Quiz.validated_input { verbatim output }}</p>
      END
    end
  end

  def produce_output(basename, input: true)
    typecheck do
      assert(basename: string)
    end

    source_path = Pathname.new("#{basename}.cpp")
    input_path = Pathname.new("#{basename}-input.txt")
    output_path = Pathname.new("#{basename}-output.txt")

    typecheck do
      assert(source_path: file,
             input_path: file,
             output_path: pathname)
    end

    File.open(output_path, 'w') do |out|
      input = if input then input_path.read else nil end
      output = Cpp.compile_and_run(source_path, input: input)

      out.write(output)
    end
  end

  def interpretation(source, input: nil)
    typecheck do
      assert(source: string)
    end

    exercise(Lib::Interpretation) do
      self.source = source
      self.input = input

      <<-END
        <p>What is the output of the following code?</p>
        #{show_source_editor}
        #{if input then show_input else '' end}
        #{show_output_field}
      END
    end
  end

  def solution_link(filename)
    typecheck do
      assert(filename: string)
    end

    %{<div class="solution"><a href="#{filename}">Solution</a></div>}
  end
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
