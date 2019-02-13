require 'Contracts'
require 'Html'
require 'Environment2'

module Quiz
  extend Html::Generation::Quiz
end


class Counter
  def initialize
    @last = 0
  end

  def next
    @last += 1
  end
end


class Exercise
  include Contracts::TypeChecking

  def initialize(exercise_index)
    @exercise_index = exercise_index
  end

  attr_reader :exercise_index
end

module SourceCodeMixin
  attr_accessor :source

  def show_source_editor(source: nil, **opts)
    Html::Generation.source_editor(source || self.source, **opts)
  end
end

module MemoryLayoutMixin
  def memory_layout(*args)
    tds = args.map do |arg|
      %{<td class="byte#{arg}" />}
    end.join('')

    %{<table class="memory-layout"><tbody><tr>#{tds}</tr></tbody></table>}
  end
end

module SolutionMixin
  def solution_link(filename)
    typecheck do
      assert(filename: string)
    end

    %{<div class="solution"><a href="#{filename}">Solution</a></div>}
  end
end

module GitMixin
  def git_link(target)
    typecheck do
      assert(target: string)
    end

    relative_path = Environment2.relative_to_git_root( Pathname.new(target).expand_path )

    %{<div class="git">Git-repo path: #{relative_path}</div>}
  end
end

module CakeMixin
  def cake(contents)
    %{<section class="cake"><span class="header">Cake Question</span>#{contents}</section>}
  end
end

module RevealerMixin
  def show_revealable(contents, html_class:, caption:)
    typecheck do
      assert(contents: string,
             html_class: string,
             caption: string)
    end

    <<-END
      <div data-revealer="#{caption}" class="#{html_class}">
        #{contents}
      </div>
    END
  end

  def show_explanation(contents, html_class: 'explanation', caption: 'Show explanation')
    typecheck do
      assert(contents: string,
             html_class: string,
             caption: string)
    end

    show_revealable(contents, html_class: html_class, caption: caption)
  end

  def show_hint(contents, html_class: 'hint', caption: 'Show hint')
    typecheck do
      assert(contents: string,
             html_class: string,
             caption: string)
    end

    show_revealable(contents, html_class: html_class, caption: caption)
  end
end

module Lib
  class Interpretation < Exercise
    include Contracts::TypeChecking
    include SourceCodeMixin

    attr_accessor :input, :output

    def show_input
      typecheck do
        assert(input: string)
      end

      %{<p>Input: <code>#{input}</code></p>}
    end

    def compute_output
      typecheck do
        assert(source: string, output: string | value(nil))
      end

      self.output = Cpp.compile_and_run_source(source, input: input).strip
    end

    def show_output_field(auto_compute: true)
      if !output && auto_compute then
        compute_output
      end

      out = output
      %{<p>Output: #{Quiz.validated_input { verbatim out }}</p>}
    end
  end


  class TypeInference < Exercise
    include Contracts::TypeChecking
    include SourceCodeMixin

    # Pairs of [ expression, type ]
    def ask_type_of_table(*pairs)
      pairs_html = pairs.map do |expression, type|
        %{<tr><td><code>#{Html.escape(expression)}</code></td><td>#{Quiz.validated_input { verbatim type }}</td>}
      end.join("\n")

      <<-END
        <table class="type-inference">
          <tr><th>Expression</th><th>Type</th></tr>
          #{pairs_html}
        </table>
      END
    end
  end

  class Numerical < Exercise
    include Contracts::TypeChecking
    
    def show_input_field(expected, delta)
      %{#{Quiz.validated_input { numerical(expected, delta) }} &plusmn; #{delta}}
    end
  end

  class LZ77 < Exercise
    include Contracts::TypeChecking
    
    def lz77_encoding(triplets)
      rows = triplets.map do |triplet|        
        distance = Quiz.validated_input { numerical(triplet[0], 0) }
        length = Quiz.validated_input { numerical(triplet[1], 0) }
        datum = Quiz.validated_input { verbatim(triplet[2]) }

        %{<tr><td>#{distance}</td><td>#{length}</td><td>#{datum}</td></tr>}
      end.join('')

      %{<table class="lz77 encoding"><tbody>#{rows}</tbody></table>}
    end

    def lz77_decoding(triplets)
      rows = triplets.map do |triplet|        
        distance, length, datum = triplet

        %{<tr><td>#{distance}</td><td>#{length}</td><td>#{datum}</td></tr>}
      end.join('')

      %{<table class="lz77 decoding"><tbody>#{rows}</tbody></table>}
    end
    
    def numeric_field(expected, delta=0)
      %{#{Quiz.validated_input { numerical(expected, delta) }}}
    end

    def text_field(expected)
      Quiz.validated_input { verbatim(expected) }
    end
  end
end


class SharedContext
  include Contracts::TypeChecking
  include Html::Generation

  def self.create_counters(*symbols)
    symbols.each do |symbol|
      instance_variable = "@#{symbol.to_s}"

      define_method symbol do
        counter = instance_variable_get(instance_variable)

        unless counter then
          instance_variable_set(instance_variable, counter = Counter.new)
        end

        counter
      end
    end
  end
  
  create_counters :exercise_counter

  def source_editor(source)
    typecheck do
      assert(source: string)
    end

    source = Html.escape(Code.remove_redundant_indentation(source)).strip

    %{<div class="source-editor"><pre>#{source}</pre></div>}
  end

  def quick_interpretation_exercise(source, input: nil)
    typecheck do
      assert(source: string)
    end

    interpretation_exercise do
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

  def interpretation_exercise(&block)
    format_exercise do |exercise_index|
      Lib::Interpretation.new(exercise_index).instance_eval(&block)
    end
  end
  
  def format_exercise(index: exercise_counter.next)
    typecheck do
      assert(index: integer & positive)
    end

    <<-END
    <section class="question">
      <h1>Exercise #{index}</h1>
      #{yield index}
    </section>
    END
  end

  def exercise(exercise_context = Exercise, index: exercise_counter.next, &block)
    typecheck do
      assert(index: integer & positive)
    end

    ctx = exercise_context.new(index)

    <<-END
    <section class="question">
      <h1>Exercise #{index}</h1>
      #{ctx.instance_eval(&block)}
    </section>
    END
  end


  # Adds single script declaration
  def script(file)
    typecheck do
      assert(file: string)
    end

    case file
    when 'jquery'
      url = 'https://code.jquery.com/jquery-3.2.1.min.js'
    when 'jquery-ui'
      url = 'https://code.jquery.com/ui/1.12.0/jquery-ui.min.js'
    when 'ace/ace'
      url = 'https://cdnjs.cloudflare.com/ajax/libs/ace/1.2.8/ace.js'
    when 'underscore'
      url = 'https://cdnjs.cloudflare.com/ajax/libs/underscore.js/1.8.3/underscore-min.js'
    else
      unless file.end_with? '.js'
        file = file + '.js'
      end

      url = Environment2.relative_path_from_cwd_to "course-material/#{file}"
    end

    %{<script src="#{url}" type="text/javascript" charset="utf-8"></script>}
  end

  # Adds multiple script declarations
  def scripts(*files)
    typecheck do
      assert(files: array(string))
    end

    files.map do |file|
      script file
    end.join("\n")
  end

  def css_link(basename = 'ucll')
    url = Environment2.relative_path_from_cwd_to "course-material/#{basename}.css"
    
    %{<link rel="stylesheet" href="#{url}">}
  end

  def stylesheets(*css_files)
    css_files.map do |css_file|
      css_link(css_file)
    end.join("\n")
  end
end
